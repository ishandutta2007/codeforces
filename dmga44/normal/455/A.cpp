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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

ll sum[MAXN];
ll dp[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        sum[a]+=a;
    }

    for(int i=0;i<MAXN-1;i++)
    {
        dp[i+1][0]=max(dp[i][0],dp[i][1]);
        dp[i+1][1]=dp[i][0]+sum[i+1];
    }

    db(dp[MAXN-1][0])

    return 0;
}