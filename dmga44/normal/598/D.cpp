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
typedef unsigned long long ull;
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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

vector<int> qs[MAXN][MAXN];
int res[MAXN*MAXN];
bool mk[MAXN][MAXN];
vector<pii> nodes;
string s[MAXN];
int n,m;

void dfs(int i,int j)
{
    nodes.push_back(pii(i,j));
    mk[i][j]=1;
    if(i && !mk[i-1][j] && s[i-1][j]=='.')
        dfs(i-1,j);
    if(j && !mk[i][j-1] && s[i][j-1]=='.')
        dfs(i,j-1);
    if(i+1<n && !mk[i+1][j] && s[i+1][j]=='.')
        dfs(i+1,j);
    if(j+1<m && !mk[i][j+1] && s[i][j+1]=='.')
        dfs(i,j+1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        qs[x][y].push_back(i);
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(!mk[i][j] && s[i][j]=='.')
            {
                dfs(i,j);

                int x=0;
                for(auto y : nodes)
                {
                    int i=y.f;
                    int j=y.s;
                    if(i && s[i-1][j]=='*')
                        x++;
                    if(j && s[i][j-1]=='*')
                        x++;
                    if(i+1<n && s[i+1][j]=='*')
                        x++;
                    if(j+1<m && s[i][j+1]=='*')
                        x++;
                }

                for(auto y : nodes)
                    for(auto p : qs[y.f][y.s])
                        res[p]=x;
                nodes.clear();
            }
        }

    for(int i=0;i<k;i++)
        cout << res[i] << '\n';
//    cout << '\n';

    return 0;
}