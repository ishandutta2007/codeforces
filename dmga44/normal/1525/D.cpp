#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)((1e18)+5);
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

ll dp[MAXN][MAXN*2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<2*MAXN;i++)
        dp[0][i]=oo;
    dp[0][MAXN]=0;
    // for(int j=-4;j<=4;j++)
    //     cout << dp[0][MAXN+j] << ' ';
    // cout << '\n';
    
    for(int i=0;i<n;i++)
    {
        if(a[i])
            for(int j=0;j<2*MAXN-1;j++)
                dp[i+1][j+1]=dp[i][j]+abs(MAXN-j);
        else
            for(int j=1;j<2*MAXN;j++)
                dp[i+1][j-1]=min(dp[i][j-1],dp[i][j]+abs(MAXN-j));
        // db("")
        // db(i)
        // for(int j=-4;j<=4;j++)
        //     cout << dp[i+1][MAXN+j] << ' ';
        // cout << '\n';
    }
    db(dp[n][MAXN])

    return 0;
}