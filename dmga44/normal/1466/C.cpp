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
typedef complex<ll> point;
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
        string s;
        cin >> s;
        int n=s.size();
        if(n==1)
        {
            db(0)
            continue;
        }
        vector<int> dp[n+1];
        for(int i=0;i<n+1;i++)
            dp[i]=vector<int>(4,1e6);
        if(s[0]!=s[1])
        {
            dp[2][0]=0;
            dp[2][1]=1;
            dp[2][2]=1;
            dp[2][3]=2;
        }
        else
        {
            dp[2][0]=1e6;
            dp[2][1]=1;
            dp[2][2]=1;
            dp[2][3]=2;
        }
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(j==0)
                {
                    if(s[i]==s[i-1] || s[i]==s[i-2])
                    {
                        dp[i+1][0]=min(dp[i+1][0],dp[i][0]+(int)1e6);
                        dp[i+1][2]=min(dp[i+1][2],dp[i][0]+1);
                    }
                    else
                    {
                        dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
                        dp[i+1][2]=min(dp[i+1][2],dp[i][0]+1);
                    }
                }
                if(j==1)
                {
                    if(s[i]==s[i-1])
                    {
                        dp[i+1][0]=min(dp[i+1][0],dp[i][1]+(int)1e6);
                        dp[i+1][2]=min(dp[i+1][2],dp[i][1]+1);
                    }
                    else
                    {
                        dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
                        dp[i+1][2]=min(dp[i+1][2],dp[i][1]+1);
                    }
                }
                if(j==2)
                {
                    if(s[i]==s[i-2])
                    {
                        dp[i+1][1]=min(dp[i+1][1],dp[i][2]+(int)1e6);
                        dp[i+1][3]=min(dp[i+1][3],dp[i][2]+1);
                    }
                    else
                    {
                        dp[i+1][1]=min(dp[i+1][1],dp[i][2]);
                        dp[i+1][3]=min(dp[i+1][3],dp[i][2]+1);
                    }
                }
                if(j==3)
                {
                    dp[i+1][1]=min(dp[i+1][1],dp[i][3]);
                    dp[i+1][3]=min(dp[i+1][3],dp[i][3]+1);
                }
            }
        }
        int res=min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3]));
        db(res)
    }

    return 0;
}