#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> depth(N,0);
vector<int> sz(N,0);

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    sz[a]=1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
        sz[a]+=sz[to];
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[a]<=depth[p[b][i]]) b=p[b][i];
    if(a==b) return a;
    for(int i=16;i>=0;i--)
    {
        if(p[a][i]!=p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}

int dist(int a,int b)
{
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}

int mv(int a,int x)
{
    x=max(0,x);
    for(int i=0;i<17;i++) if(x&(1<<i)) a=p[a][i];
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int m;
    cin >> m;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        if(depth[a]>depth[b]) swap(a,b);
        int d=dist(a,b);
        if(a==b) cout << n << "\n";
        else if(d&1) cout << "0\n";
        else if(depth[a]==depth[b]) cout << n-sz[mv(a,d/2-1)]-sz[mv(b,d/2-1)] << "\n";
        else cout << sz[mv(b,d/2)]-sz[mv(b,d/2-1)] << "\n";
    }
    return 0;
}