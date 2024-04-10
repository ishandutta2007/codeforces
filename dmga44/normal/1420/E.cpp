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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(8e1+5)

int dp[MAXN][MAXN][(MAXN*MAXN)/2][2];
int pre[MAXN][MAXN][MAXN][2];
int ans[MAXN*MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s="";
    int c0=0;
    int c1=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        s.push_back('0'+x);
        if(s[i]=='0')
            c0++;
        if(s[i]=='1')
            c1++;
    }

    for(int i=0;i<=c0;i++)
        for(int j=0;j<=c1;j++)
        {
            for(int k=0;k<=n;k++)
                for(int u=0;u<2;u++)
                    pre[i][j][k][u]=oo;
            for(int k=0;k<=(c0*(c0-1))/2;k++)
                for(int u=0;u<2;u++)
                    dp[i][j][k][u]=oo;
        }

    for(int i=0;i<=c0;i++)
        for(int j=0;j<=c1;j++)
        {
            string res="";
            int cc0=0;
            int cc1=0;
            for(int k=0;k<n;k++)
            {
                if(s[k]=='0')
                {
                    if(cc0<i)
                        cc0++;
                    else
                        res.push_back('0');
                }
                if(s[k]=='1')
                {
                    if(cc1<j)
                        cc1++;
                    else
                        res.push_back('1');
                }
            }

            cc0=0;
            cc1=0;
            pre[i][j][0][0]=0;
            pre[i][j][0][1]=0;
//            db("")
//            cout << i << ' ' << j << '\n';
//            db(res)
            for(int k=0;k<n-i-j;k++)
            {
                if(res[k]=='0')
                {
                    cc0++;
                    pre[i][j][cc0][0]=pre[i][j][cc0-1][0]+cc1;
//                    cout << "0" << cc0 << ' ' << pre[i][j][cc0][0] << '\n';
                }
                else
                {
                    cc1++;
                    pre[i][j][cc1][1]=pre[i][j][cc1-1][1]+cc0;
//                    cout << "1" << cc1 << ' ' << pre[i][j][cc1][1] << '\n';
                }
            }
        }

    dp[0][0][0][0]=0;
    dp[0][0][0][1]=0;
    for(int i=0;i<=c0;i++)
        for(int j=0;j<=c1;j++)
        {
            if(i+j==n)
                break;
//            db("")
//            cout << i << ' ' << j << '\n';
            for(int k=0;k<=(c0*(c0-1))/2;k++)
                for(int u=0;u<2;u++)
                {
                    if(dp[i][j][k][u]>=oo)
                        continue;
//                    cout << k << ' ' << u << ' ' << dp[i][j][k][u] << '\n';
                    if(u==0)
                    {
                        int ma=c0-i;
                        for(int d=1;d<=ma;d++)
                            dp[i+d][j][k+((d*(d-1))/2)][1]=min(dp[i+d][j][k+((d*(d-1))/2)][1],dp[i][j][k][u]+pre[i][j][d][u]);
                    }
                    else
                    {
                        int ma=c1-j;
                        for(int d=1;d<=ma;d++)
                            dp[i][j+d][k][0]=min(dp[i][j+d][k][0],dp[i][j][k][u]+pre[i][j][d][u]);
                    }
                }
        }

    for(int i=0;i<=(n*(n-1)/2);i++)
        ans[i]=oo;
//    db("")
    for(int i=0;i<=(c0*(c0-1)/2);i++)
        for(int j=0;j<2;j++)
        {
            if(dp[c0][c1][i][j]>=oo)
                continue;
//            cout << i << ' ' << j << ' ' << dp[c0][c1][i][j] << '\n';
            ans[dp[c0][c1][i][j]]=min(ans[dp[c0][c1][i][j]],i);
        }
//    for(int i=0;i<=(n*(n-1)/2);i++)
//        cout << ans[i] << ' ';
//    cout << '\n';
    for(int i=1;i<=(n*(n-1)/2);i++)
        ans[i]=min(ans[i-1],ans[i]);
    for(int i=0;i<=(n*(n-1)/2);i++)
    {
        ans[i]=(c0*(c0-1))/2-ans[i];
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}