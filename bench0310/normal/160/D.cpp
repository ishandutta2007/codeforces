#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> p(N,0);
vector<int> sz(N,1);
vector<array<int,2>> v[N];
vector<int> res(N,1); //none,some,all
vector<int> depth(N,0);
vector<int> low(N,0);
vector<int> up(N,0); //edge id of p-i

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

void merge_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
}

void dfs(int a,int par=0)
{
    depth[a]=depth[par]+1;
    low[a]=depth[a];
    int cnt=0;
    for(auto [to,id]:v[a])
    {
        if(to==par)
        {
            cnt++;
            continue;
        }
        if(depth[to]==0)
        {
            up[to]=id;
            dfs(to,a);
            low[a]=min(low[a],low[to]);
        }
        else low[a]=min(low[a],depth[to]);
    }
    if(par!=0&&low[a]==depth[a]&&cnt==1) res[up[a]]=2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,4>> edges; //w,a,b,i
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c,a,b,i});
    }
    for(int i=1;i<=n;i++) p[i]=i;
    sort(edges.begin(),edges.end());
    int l=0;
    while(l<m)
    {
        int r=l;
        while(r+1<m&&edges[r+1][0]==edges[l][0]) r++;
        vector<int> now;
        for(int i=l;i<=r;i++)
        {
            int a=find_set(edges[i][1]);
            int b=find_set(edges[i][2]);
            int id=edges[i][3];
            if(a==b) res[id]=0;
            else
            {
                v[a].push_back({b,id});
                v[b].push_back({a,id});
                now.push_back(a);
                now.push_back(b);
            }
        }
        for(int a:now) if(depth[a]==0) dfs(a);
        for(int a:now)
        {
            v[a].clear();
            depth[a]=low[a]=up[a]=0;
        }
        for(int i=l;i<=r;i++) merge_sets(edges[i][1],edges[i][2]);
        l=r+1;
    }
    for(int i=0;i<m;i++)
    {
        if(res[i]==0) cout << "none\n";
        else if(res[i]==1) cout << "at least one\n";
        else cout << "any\n";
    }
    return 0;
}