#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

vector<pii> g[MAXN];
ll cant[MAXN][4],res;
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto y : g[u])
    {
        int v=y.first;
        int t=y.second;
        if(!mk[v])
        {
            dfs(v);
            if(!t)
            {
                cant[v][2]+=cant[v][1];
                cant[v][0]++;
                cant[v][3]=0;
                cant[v][1]=0;
            }
            else
            {
                cant[v][3]+=cant[v][0];
                cant[v][1]++;
                cant[v][2]=0;
                cant[v][0]=0;

            }
            res+=(2*cant[v][0]+2*cant[v][1]+cant[v][2]+cant[v][3]);
            res+=2*(cant[u][0]*(cant[v][0]));
            res+=2*(cant[u][1]*(cant[v][1]));
            res+=(cant[u][1]*(cant[v][3]+cant[v][0]));
            res+=(cant[u][3]*cant[v][1]);
            res+=(cant[u][0]*(cant[v][2]+cant[v][1]));
            res+=(cant[u][2]*(cant[v][0]));
            cant[u][0]+=cant[v][0];
            cant[u][1]+=cant[v][1];
            cant[u][2]+=cant[v][2];
            cant[u][3]+=cant[v][3];
        }
    }
//    cout << u+1 << '\n';
//    cout << cant[u][0] << ' ' << cant[u][1] << ' ' << cant[u][2]  <<' ' << cant[u][3] << '\n';
//    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int u,v,t;
        cin >> u >> v >> t;
        u--,v--;
        g[u].push_back(pii(v,t));
        g[v].push_back(pii(u,t));
    }

    dfs(0);

    db(res)

    return 0;
}