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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
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
#define oo (ll)(2e18)
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

ll dp[MAXN][MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r,g,b;
    cin >> r >> g >> b;
    vector<int> rs(r);
    for(int i=0;i<r;i++)
        cin >> rs[i];
    vector<int> gs(g);
    for(int i=0;i<g;i++)
        cin >> gs[i];
    vector<int> bs(b);
    for(int i=0;i<b;i++)
        cin >> bs[i];

    sort(all(rs));
    sort(all(gs));
    sort(all(bs));

    for(int i=0;i<=r;i++)
        for(int j=0;j<=g;j++)
            for(int k=0;k<=b;k++)
            {
                dp[i][j][k]=0;
                if(i && j)
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+rs[i-1]*gs[j-1]);
                if(i && k)
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+rs[i-1]*bs[k-1]);
                if(k && j)
                    dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+bs[k-1]*gs[j-1]);
            }
    db(dp[r][g][b])

    return 0;
}