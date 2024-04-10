#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

struct info{
    ll x00;
    ll x10;
    ll x01;
    ll x11;
    int l,r;
};

int n,m;
int base[MAXN];
info st[4*MAXN];

int val(int x)
{
    if(x<10)
        return x+1;
    return max(0,19-x);
}

ll vv(int p)
{
    if(base[p]!=1)
        return 0;
    return val(10+base[p+1]);
}

info merge(info &a,info &b)
{
    info res;
    res.r=b.r;
    res.l=a.l;
    res.x00=(a.x00*b.x00)%mod;
    res.x00=(res.x00+a.x01*b.x10*vv(a.r))%mod;

    res.x01=(a.x00*b.x01)%mod;
    res.x01=(res.x01+a.x01*b.x11*vv(a.r))%mod;

    res.x10=(a.x10*b.x00)%mod;
    res.x10=(res.x10+a.x11*b.x10*vv(a.r))%mod;

    res.x11=(a.x10*b.x01)%mod;
    res.x11=(res.x11+a.x11*b.x11*vv(a.r))%mod;
    return res;
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        st[p].x10=1;
        st[p].x11=0;
        st[p].x00=val(base[l]);
        st[p].x01=1;
        st[p].l=l;
        st[p].r=r;
        return ;
    }
    int mid=(l+r)>>1;

    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);

    st[p]=merge(st[p<<1],st[(p<<1)+1]);
}

void update(int p,int l,int r,int pos,int v)
{
    if(l==r)
    {
        base[l]=v;
        st[p].x00=val(base[l]);
        return ;
    }
    int mid=(l+r)>>1;

    if(pos<=mid)
        update(p<<1,l,mid,pos,v);
    else
        update((p<<1)+1,mid+1,r,pos,v);

    st[p]=merge(st[p<<1],st[(p<<1)+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
        base[i]=s[i]-'0';

    build(1,0,n-1);

    while(m--)
    {
        int p,x;
        cin >> p >> x;
        p--;
        update(1,0,n-1,p,x);
        db(st[1].x00)
    }

    return 0;
}
/**
2 3
14
2 4
2 1
1 0
**/