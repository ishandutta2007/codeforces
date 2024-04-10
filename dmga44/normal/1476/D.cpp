#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> dp[2];
        vector<int> dp1[2];
        dp[0].push_back(0);
        dp[1].push_back(0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
            {
                dp[0].push_back(1+dp[1].back());
                dp[1].push_back(0);
            }
            else
            {
                dp[1].push_back(1+dp[0].back());
                dp[0].push_back(0);
            }
        }
        dp1[0].push_back(0);
        dp1[1].push_back(0);
        for(int i=0;i<n;i++)
        {
            if(s[n-i-1]=='R')
            {
                dp1[0].push_back(1+dp1[1].back());
                dp1[1].push_back(0);
            }
            else
            {
                dp1[1].push_back(1+dp1[0].back());
                dp1[0].push_back(0);
            }
        }
        reverse(all(dp1[0]));
        reverse(all(dp1[1]));

        for(int i=0;i<n+1;i++)
            cout << 1+dp[0][i]+dp1[0][i] << ' ';
        cout << '\n';
    }

    return 0;
}