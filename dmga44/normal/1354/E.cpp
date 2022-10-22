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
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define pi		3.14159265358979323846
#define MAXN 5005

vector<int> g[MAXN],nodes[MAXN];
int c[MAXN],res[MAXN],cant[2],ok;
int dp[MAXN][MAXN];
bool mk[MAXN];

void dfs(int u,int p)
{
    mk[u]=1;
    cant[c[u]]++;
    nodes[p].push_back(u);
    for(auto v : g[u])
    {
        if(!mk[v])
        {
            c[v]=1-c[u];
            dfs(v,p);
        }
        if(c[u]==c[v])
            ok=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pip> vp;
    bool ko=1;
    for(int i=0;i<n;i++)
        if(!mk[i])
        {
            ok=1;
            dfs(i,i);

            ko&=ok;
            vp.push_back(pip(i,pii(cant[0],cant[1])));
            cant[0]=cant[1]=0;
        }

    if(!ko)
        db("NO")
    else
    {
        for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXN;j++)
                dp[i][j]=-1;
//        for(int i=0;i<n;i++)
//            cout << c[i];
//        cout << '\n';
        dp[0][0]=0;
        for(int i=0;i<vp.size();i++)
        {
            int c0=vp[i].s.f;
            int c1=vp[i].s.s;
            for(int j=0;j<MAXN;j++)
            {
                if(dp[i][j]==-1)
                    continue;
                if(j+c0<MAXN && dp[i+1][j+c0]==-1)
                    dp[i+1][j+c0]=c0;
                if(j+c1<MAXN && dp[i+1][j+c1]==-1)
                    dp[i+1][j+c1]=c1;
            }
        }

        if(dp[vp.size()][n2]!=-1)
        {
            int act=n2;
            for(int i=vp.size();i>0;i--)
            {
//                db(dp[i][act])
//                db(nodes[vp[i-1].f].size())
//                db("")
                if(dp[i][act]!=vp[i-1].s.f)
                {
                    act-=dp[i][act];
                    continue;
                }
                for(auto v : nodes[vp[i-1].f])
                    c[v]=1-c[v];

                act-=dp[i][act];
            }

            db("YES")
            for(int i=0;i<n;i++)
            {
                if(c[i])
                    cout << 2;
                else if(n1)
                {
                    cout << 1;
                    n1--;
                }
                else
                    cout << 3;
            }

        }
        else
            db("NO")
    }
    return 0;
}
/**
6 3
2 2 2
3 1
5 4
2 5
**/