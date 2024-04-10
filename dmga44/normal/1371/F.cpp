#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
#define mod (int)(1e4+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

struct info{
    int m;
    int lt,lm;
    int rt,rm;
    info() : m(0),lt(0),lm(0),rt(0),rm(0){}
};

struct node{
    info ok,inv;
    bool lazy;
    node() : lazy(0){}
};

node st[4*MAXN];
string s;
int n,q;

info join(info &l,info &r,int szl,int szr)
{
    int m=max(l.m,r.m);
    int lt=l.lt;
    int lm=l.lm;
    int rt=r.rt;
    int rm=r.rm;

    if(l.rt==r.lt || (!l.rt && r.lt==1))
    {
        m=max(m,l.rm+r.lm);
        if(lm==szl)
            lm=l.rm+r.lm;
        if(rm==szr)
            rm=l.rm+r.lm;
    }
    info res;
    res.m=m;
    res.rm=rm;
    res.lm=lm;
    res.lt=lt;
    res.rt=rt;
    return res;
}

node merge(node &l,node &r,int szl,int szr)
{
    node res;
    res.ok=join(l.ok,r.ok,szl,szr);
    res.inv=join(l.inv,r.inv,szl,szr);
    return res;
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        int t=1;
        if(s[l]=='>')
            t=0;
        info ok;
        ok.m=1;
        ok.lt=t;
        ok.rt=t;
        ok.lm=1;
        ok.rm=1;
        info inv=ok;
        inv.lt=inv.rt=1-t;
        st[p].ok=ok;
        st[p].inv=inv;
        return ;
    }

    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    st[p]=merge(st[p<<1],st[(p<<1)+1],mid-l+1,r-mid);
}

void app(int p)
{
    swap(st[p].ok,st[p].inv);
    st[p].lazy^=1;
}

void push(int p,int l,int r)
{
    if(l==r || !st[p].lazy)
        return ;
    app(p<<1);
    app((p<<1)+1);
    st[p].lazy=0;
}

void update(int p,int l,int r,int L,int R)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        app(p);
        return ;
    }

    int mid=(l+r)>>1;
    if(L<=mid)
        update(p<<1,l,mid,L,R);
    if(R>mid)
        update((p<<1)+1,mid+1,r,L,R);
    st[p]=merge(st[p<<1],st[(p<<1)+1],mid-l+1,r-mid);
}

node query(int p,int l,int r,int L,int R)
{
    push(p,l,r);
    if(L<=l && r<=R)
        return st[p];
    int mid=(l+r)>>1;
    if(R<=mid)
        return query(p<<1,l,mid,L,R);
    if(L>mid)
        return query((p<<1)+1,mid+1,r,L,R);
    node a=query(p<<1,l,mid,L,mid);
    node b=query((p<<1)+1,mid+1,r,mid+1,R);
    return merge(a,b,mid-L+1,R-mid);
}

void qq(int l,int r)
{
    update(1,0,n-1,l,r);

    node x=query(1,0,n-1,l,r);
    db(x.ok.m)
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    cin >> s;

    build(1,0,n-1);

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        qq(l,r);
    }

    return 0;
}
/**
5 6
><>><
2 4
3 5
1 5
1 3
2 4
1 5
**/