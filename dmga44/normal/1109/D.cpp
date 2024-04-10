    #include <bits/stdc++.h>
    #define db(x) cout << (x) << '\n';
    using namespace std;
    typedef long long ll;
    typedef double ld;
    typedef pair<ll,ll> pii;
    typedef pair<ll,pii> pip;
    typedef pair<pii,ll> ppi;
    typedef pair<pii,pii> ppp;
    typedef pair<ld,ll> pli;
    typedef pair<pii,string> pps;
    typedef pair<string,ll> psi;
    typedef pair<ll,char> pic;
    typedef pair<char,ll> pci;
    typedef complex<double> point;
    typedef vector<point> polygon;
    #define pi (acos(-1))
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    #define MAXN 1000005
    #define mod (ll(1e9+7))
     
    ll f[MAXN],ifa[MAXN];
     
    ll qp(ll b,ll e)
    {
        if(!e)
            return 1;
        ll x=qp(b,e/2);
        x=(x*x)%mod;
        if(e&1)
            x=(x*b)%mod;
        return x;
    }
     
    ll c(ll m,ll n)
    {
        return (f[n]*((ifa[m]*ifa[n-m])%mod))%mod;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
     
        f[0]=1;
        ifa[0]=1;
        for(ll i=1;i<MAXN;i++)
        {
            f[i]=(f[i-1]*i)%mod;
            ifa[i]=qp(f[i],mod-2);
        }
     
        int n,m,aaaaa,bbbbb;
        cin >> n >> m >> aaaaa >> bbbbb;
        ll res=0;
        for(int i=1;i<=min(n-1,m);i++)
        {
            ll c1=c(i-1,m-1);
            ll c2=qp(m,n-i-1);
            ll c3=(f[n-2]*(ifa[n-1-i]))%mod;
            ll c4=1;
            if(i!=n-1)
                c4=((i+1)*qp(n,n-i-2))%mod;
            ll c5=(c1*c2)%mod;
            ll c6=(c3*c4)%mod;
            res=(res+(c5*c6))%mod;
        }
        db(res)
     
        return 0;
    }