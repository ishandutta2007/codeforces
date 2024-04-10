#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define mod (ll(1e9+7))
#define MAXN 200005

ll a[MAXN],fac[MAXN],fai[MAXN];

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

ll c(ll a,ll b)
{
    return (((fac[a]*fai[b])%mod)*fai[a-b])%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=1;
    fai[0]=1;
    for(ll i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        fai[i]=qp(fac[i],mod-2);
    }

    ll n,t;
    cin >> n >> t;
    ll sum=0,sc=1;
    pii res=pii(0,1);
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
//        db("")
//        db(sc)
//        db(sum)
//        cout << res.first << ' ' << res.second << '\n';
        if(sum>t)
        {
            sc=(sc*2)%mod;
            res=pii((res.first*2)%mod,(res.second*2)%mod);
            continue;
        }
        if(t-sum>i)
        {
            res=pii((res.first+res.second)%mod,res.second);
            res=pii((res.first*2)%mod,(res.second*2)%mod);
            sc=(sc*2)%mod;
            continue;
        }
        sc=(sc*2)%mod;
        for(ll j=min(i-1,t-sum+a[i]);j>=max(t-sum,0ll);j--)
            sc=(sc-(2*c(i-1,j))+(2*mod))%mod;
        sc=(sc+c(i-1,t-sum))%mod;
//        db(sc)
        res=pii((res.first*2)%mod,(res.second*2)%mod);
        res=pii((res.first+sc)%mod,res.second);
    }
//    cout << res.first << ' ' << res.second << '\n';
    db((res.first*qp(res.second,mod-2))%mod)
    return 0;
}