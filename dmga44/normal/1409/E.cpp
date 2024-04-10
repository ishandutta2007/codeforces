#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int dp[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> xs(n);
        for(int i=0;i<n;i++)
            cin >> xs[i];
        int _;
        for(int i=0;i<n;i++)
            cin >> _;

        sort(all(xs));

        for(int i=0;i<n;i++)
        {
            dp[i+1]=i+1-(lower_bound(all(xs),xs[i]-k)-xs.begin());
            dp[i+1]=max(dp[i+1],dp[i]);
        }

        ll res=0;
        for(int i=0;i<n;i++)
        {
            int p=(lower_bound(all(xs),xs[i]-k)-xs.begin());
            ll v=i+1-p;
            res=max(res,dp[p]+v);
        }
        db(res)
    }

    return 0;
}