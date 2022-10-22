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
#define MAXN (ll)(1<<24)

int times[10][10][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
                times[i][j][k]=-1;
            times[i][j][i]=0;
            times[i][j][j]=0;
            queue<int> q;
            q.push(i);
            q.push(j);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();

                int v1=(u+i)%10;
                int v2=(u+j)%10;
                if(times[i][j][v1]==-1)
                {
                    times[i][j][v1]=times[i][j][u]+1;
                    q.push(v1);
                }
                if(times[i][j][v2]==-1)
                {
                    times[i][j][v2]=times[i][j][u]+1;
                    q.push(v2);
                }
            }
        }

//    for(int i=0;i<10;i++)
//    {
//        for(int j=0;j<10;j++)
//        {
//        for(int _=0;_<10;_++)
//            cout << times[i][j][_] << ' ';
//        cout << '\n';
//        }
//        cout << '\n';
//    }

    string s;
    cin >> s;
    vector<vector<int> > dp(10,vector<int>(10));
    int last=0;
    int ini=0;
    if(s[0]=='0')
        ini=1;
    for(int i=ini;i<s.size();i++)
    {
        int v=(s[i]-'0'-last+10)%10;
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
            {
                if(dp[j][k]==-1 || times[j][k][v]==-1)
                {
                    dp[j][k]=-1;
                    continue;
                }
                dp[j][k]+=times[j][k][v];
            }
        last=s[i]-'0';
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }


    return 0;
}