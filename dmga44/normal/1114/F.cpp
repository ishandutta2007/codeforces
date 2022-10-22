#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 400005
#define mod (ll(1e9+7))

int p[305],a[MAXN],L,R,inverse[62];
pii x;
vector<ll> primes;

void criba()
{
    for(int i=2;i<305;i++)
        if(!p[i])
        {
            primes.push_back(i);
            for(int j=i;j<305;j+=i)
                p[j]=i;
        }
}

int qp(int b,int e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

pii st[4*MAXN],b[MAXN],lazy[4*MAXN];

pii me(pii x,pii y)
{
    return pii((x.first*y.first)%mod,x.second|y.second);
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        st[p]=b[l];
        return ;
    }
    int mid=(l+r)>>1;

    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    st[p]=me(st[p<<1],st[(p<<1)+1]);
}

void push(int p,int l,int r)
{
    if(l==r || lazy[p]==pii(1,0))
        return ;
    int mid=(l+r)>>1;
    int t1=mid-l+1;
    int t2=r-mid;

    lazy[p<<1].second|=lazy[p].second;
    lazy[p<<1].first*=lazy[p].first;
    if(lazy[p<<1].first>=mod)
        lazy[p<<1].first%=mod;
    st[p<<1].second|=lazy[p].second;
    st[p<<1].first=(st[p<<1].first*qp(lazy[p].first,t1))%mod;

    lazy[(p<<1)+1].second|=lazy[p].second;
    lazy[(p<<1)+1].first*=lazy[p].first;
    if(lazy[(p<<1)+1].first>=mod)
        lazy[(p<<1)+1].first%=mod;
    st[(p<<1)+1].second|=lazy[p].second;
    st[(p<<1)+1].first=(st[(p<<1)+1].first*qp(lazy[p].first,t2))%mod;

    lazy[p].first=1;
    lazy[p].second=0;
}

pii query(int p,int l,int r)
{
    push(p,l,r);
    if(L<=l && r<=R)
        return st[p];
    if(L>r || l>R)
        return pii(1,0);
    int mid=(l+r)>>1;

    return me(query(p<<1,l,mid),query((p<<1)+1,mid+1,r));
}

void update(int p,int l,int r)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        st[p].second|=x.second;
        lazy[p].second|=x.second;
        st[p].first=(st[p].first*qp(x.first,r-l+1))%mod;
        lazy[p].first=(lazy[p].first*x.first)%mod;
        return ;
    }
    if(l>R || L>r)
        return ;
    int mid=(l+r)>>1;

    if(L<=mid)
        update(p<<1,l,mid);
    if(R>mid)
        update((p<<1)+1,mid+1,r);

    st[p]=me(st[p<<1],st[(p<<1)+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();
    for(int i=0;i<62;i++)
        inverse[i]=qp(primes[i],mod-2);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<4*MAXN;i++)
        lazy[i]=pii(1,0);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        b[i].first=a[i];
        for(int j=0;j<62;j++)
            if(a[i]%primes[j]==0)
                b[i].second+=(1ll<<j);
    }

    build(1,0,n-1);

    while(q--)
    {
        string s;
        cin >> s;
        if(s[0]=='T')
        {
            ll l,r;
            cin >> l >> r;
            l--,r--;
            L=l,R=r;
            pii xxx=query(1,0,n-1);

            for(ll i=0;i<62;i++)
                if(xxx.second&(1ll<<i))
                {
                    xxx.first=(xxx.first*(primes[i]-1))%mod;
                    xxx.first=(xxx.first*inverse[i])%mod;
                }
            db(xxx.first)
        }
        else
        {
            ll l,r,xx;
            cin >> l >> r >> xx;
            l--,r--;
            L=l,R=r;

            ll bm=0;
            for(int i=0;i<62;i++)
                if(xx%primes[i]==0)
                    bm|=(1ll<<i);
            x=pii(xx,bm);
            update(1,0,n-1);
        }
    }
    return 0;
}