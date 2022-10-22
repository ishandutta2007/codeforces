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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(1.5e5+5)

int dp[MAXN][3][3];
pip pre[MAXN][3][3];

void solve(string s)
{
    int n=s.size();
    for(int i=0;i<=n;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                dp[i][j][k]=oo;
    dp[0][0][0]=0;
    string s1="one";
    string s2="two";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                if(dp[i+1][j][k]>dp[i][j][k]+1)
                {
                    dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]+1);
                    pre[i+1][j][k]=pip(1,pii(j,k));
                }
                int v1=j+(s1[j]==s[i]);
                int v2=k+(s2[k]==s[i]);
                if(v1==j)
                    v1=(s[i]==s1[0]);
                if(v2==k)
                    v2=(s[i]==s2[0]);
                if(v1!=3 && v2!=3 && dp[i+1][v1][v2]>dp[i][j][k])
                {
                    dp[i+1][v1][v2]=min(dp[i+1][v1][v2],dp[i][j][k]);
                    pre[i+1][v1][v2]=pip(0,pii(j,k));
                }
            }
    }

//    db("xxxx")
//    for(int i=0;i<=n;i++)
//    {
//        db("")
//        db(i)
//        for(int j=0;j<3;j++,cout << '\n')
//            for(int k=0;k<3;k++)
//                cout << dp[i][j][k] << ' ';
//    }

    int res=oo;
    pii best;
    vector<int> ps;
    for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
            if(res>dp[n][j][k])
            {
                best=pii(j,k);
                res=dp[n][j][k];
            }

    db(res)
    int p=n;
    while(p)
    {
        pip x=pre[p][best.f][best.s];
        if(x.f)
            cout << p << ' ';
        best=x.s;
        p--;
    }
    cout << '\n';
}

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
        solve(s);
    }

    return 0;
}