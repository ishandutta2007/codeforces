#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
int n;
vector<int> v[N];
vector<int> sz(N,0);
vector<int> level(N,0);
vector<vector<int>> d(N,vector<int>(18,0));
vector<bool> vis(N,0);
vector<int> dad(N,0);
vector<int> sub(N,0);
int root=0;
vector<int> chip(N,-1);
vector<int> val[N];

void find_sz(int a,int p=0)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p||vis[to]==1) continue;
        find_sz(to,a);
        sz[a]+=sz[to];
    }
}

int find_centroid(int a,int p,int nnow)
{
    for(int to:v[a])
    {
        if(to==p||vis[to]==1) continue;
        if(sz[to]>nnow/2) return find_centroid(to,a,nnow);
    }
    return a;
}

void find_d(int a,int p,int lvl)
{
    for(int to:v[a])
    {
        if(to==p||vis[to]==1) continue;
        d[to][lvl]=d[a][lvl]+1;
        find_d(to,a,lvl);
    }
}

void build_cd(int a,int p=0)
{
    find_sz(a);
    int centroid=find_centroid(a,0,sz[a]);
    vis[centroid]=1;
    if(p!=0) level[centroid]=level[p]+1;
    sub[centroid]=1;
    dad[centroid]=p;
    if(p==0) root=centroid;
    find_d(centroid,0,level[centroid]);
    for(int to:v[centroid]) if(vis[to]==0) build_cd(to,centroid);
    sub[p]+=sub[centroid];
}

void one(int b)
{
    int a=b;
    while(a)
    {
        int t=chip[b]-d[b][level[a]]-1;
        t=min(t,sub[a]-1);
        if(t>=0) val[a][t]=max(val[a][t],chip[b]);
        a=dad[a];
    }
}

int two(int b)
{
    int a=b;
    int res=0;
    while(a)
    {
        res=max(res,val[a][d[b][level[a]]]);
        a=dad[a];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    build_cd(1);
    int k;
    cin >> k;
    queue<int> q;
    for(int i=0;i<k;i++)
    {
        int a;
        cin >> a;
        chip[a]=0;
        q.push(a);
    }
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a])
        {
            if(chip[to]==-1)
            {
                chip[to]=chip[a]+1;
                q.push(to);
            }
        }
    }
    for(int i=1;i<=n;i++) val[i].assign(sub[i],0);
    for(int i=1;i<=n;i++) one(i);
    for(int i=1;i<=n;i++) for(int j=sub[i]-2;j>=0;j--) val[i][j]=max(val[i][j],val[i][j+1]);
    for(int i=1;i<=n;i++) cout << two(i) << " \n"[i==n];
    return 0;
}