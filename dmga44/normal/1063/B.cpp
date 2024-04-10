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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

string s[MAXN];
int c[MAXN][MAXN];
vector<pii> g[MAXN*MAXN];
int d[MAXN*MAXN][2];
bool mk[MAXN*MAXN];
int sz[MAXN*MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    int r,cc;
    cin >> r >> cc;
    r--,cc--;
    int x,y;
    cin >> x >> y;
    for(int i=0;i<n;i++)
        cin >> s[i];

    int cont=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='*')
                continue;
            if(!i)
            {
                c[i][j]=cont;
                sz[cont]++;
                cont++;
            }
            else
            {
                if(s[i-1][j]=='.')
                {
                    c[i][j]=c[i-1][j];
                    sz[c[i][j]]++;
                }
                else
                {
                    c[i][j]=cont;
                    sz[cont]++;
                    cont++;
                }
            }
        }
    }

//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            cout << c[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='*')
                continue;
            if(j && s[i][j-1]=='.')
            {
                g[c[i][j]].push_back(pii(c[i][j-1],-1));
                g[c[i][j-1]].push_back(pii(c[i][j],1));
            }
        }
    }

    for(int i=0;i<cont;i++)
    {
        d[i][0]=d[i][1]=1e9+5;
    }

    priority_queue<pip,vector<pip>,greater<pip> > pq;
    pq.push(pip(0,pii(0,c[r][cc])));
    while(!pq.empty())
    {
        pip xxx=pq.top();
        pq.pop();
        int u=xxx.s.s;
        int cx=xxx.f;
        int cy=xxx.s.f;
        if(mk[u])
            continue;
        mk[u]=1;
        d[u][0]=cx;
        d[u][1]=cy;
        for(auto y : g[u])
        {
            int v=y.f;
            int w=y.s;
            if(mk[v])
                continue;
            int ccx=cx;
            int ccy=cy;
            if(w==-1)
                ccx++;
            else
                ccy++;
            pq.push(pip(ccx,pii(ccy,v)));
        }
    }

//    for(int i=0;i<cont;i++)
//    {
//        cout << i << ' ' << d[i][0] << ' ' << d[i][1] << '\n';
//    }

    int res=0;
    for(int i=0;i<cont;i++)
        if(d[i][0]<=x && d[i][1]<=y)
            res+=sz[i];
    db(res)

    return 0;
}