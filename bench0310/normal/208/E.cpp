#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> depth(N,0);
vector<int> sz(N,0);
vector<int> big(N,0);
vector<array<int,2>> queries[N];
vector<int> res(N,0);

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    sz[a]=1;
    for(int to:v[a])
    {
        p[to][0]=a;
        dfs(to);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

int up(int a,int d)
{
    for(int i=16;i>=0;i--) if(depth[p[a][i]]>=d) a=p[a][i];
    return a;
}

map<int,int> solve(int a)
{
    map<int,int> m;
    if(big[a]!=0) m=solve(big[a]);
    for(int to:v[a])
    {
        if(to==big[a]) continue;
        map<int,int> x=solve(to);
        for(auto [d,c]:x) m[d]+=c;
    }
    m[depth[a]]++;
    for(auto [d,id]:queries[a]) res[id]=m[d]-1;
    return m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> root;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        if(a==0) root.push_back(i);
        else v[a].push_back(i);
    }
    for(int a:root) dfs(a);
    int m;
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        int a,x;
        cin >> a >> x;
        if(depth[a]-x>=1) queries[up(a,depth[a]-x)].push_back({depth[a],i});
    }
    for(int a:root) solve(a);
    for(int i=1;i<=m;i++) cout << res[i] << " \n"[i==m];
    return 0;
}