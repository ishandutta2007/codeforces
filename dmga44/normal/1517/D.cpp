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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e2+5)

vector<pip> g[MAXN][MAXN];
int dp[MAXN][MAXN][11];
bool mk[MAXN][MAXN];
pii mks[MAXN];
int sz_mk;
vector<pip> ds[MAXN][MAXN][6];
int best[MAXN][MAXN];

void push_back(pii p)
{
    mks[sz_mk]=p;
    sz_mk++;
}

void clear()
{
    sz_mk=0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m-1;j++)
        {
            int x;
            cin >> x;
            g[i][j].push_back(pip(x,pii(i,j+1)));
            g[i][j+1].push_back(pip(x,pii(i,j)));
        }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m;j++)
        {
            int x;
            cin >> x;
            g[i][j].push_back(pip(x,pii(i+1,j)));
            g[i+1][j].push_back(pip(x,pii(i,j)));
        }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int u=0;u<11;u++)
                dp[i][j][u]=1e9;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(auto e : g[i][j])
                dp[i][j][1]=min(e.f,dp[i][j][1]);
    for(int kk=1;kk<=k/2;kk++)
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(auto e : g[i][j])
                    dp[i][j][kk+1]=min(dp[e.s.f][e.s.s][kk]+e.f,dp[i][j][kk+1]);

    for(int i=0;i<n;i++,cout << '\n')
        for(int j=0;j<m;j++)
        {
            if(k&1)
                cout << "-1 ";
            else
            {
                int x=k/2;
                int d=dp[i][j][x];
                cout << 2*d << ' ';
            }
        }

    return 0;
}