#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;
typedef unsigned long long ull;
#define MAXN 200005

vector <int> g[MAXN];
int level[MAXN],res[MAXN],p[MAXN];
bool mk[MAXN];

void dfs(int v)
{
    mk[v]=true;
    for(auto x : g[v])
    {
        if(!mk[x])
        {
            p[x]=v;
            level[x]=level[v]+1;
            dfs(x);
            res[v]=max(res[v],res[x]);
        }
    }
    res[v]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x,a,b;
    cin >> n >> x;
    x--;
    for(int i=0;i<n-1;i++)
    {
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);

    int y=(level[x]-1)/2;
    for(int i=0;i<y;i++)
        x=p[x];
    int sol=(level[x]+res[x]-1)*2;

    db(sol)

    return 0;
}