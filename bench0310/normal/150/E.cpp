#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

const int N=100005;
const int inf=(1<<30);
vector<int> v[N];
vector<array<int,2>> g[N];
int liml,limr;
vector<int> d(N,0);
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> sz(N,0);
vector<bool> vis(N,0);
vector<int> ch[N];
vector<int> st[N];
vector<vector<int>> prelca(N,vector<int>(17,0));
vector<int> level(N,0);
int root=0;
array<int,2> res;

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=16;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

void recalc(int a,int lim)
{
    for(auto [to,w]:g[a])
    {
        if(to==p[a][0]) continue;
        d[to]=d[a]+(w>=lim);
        recalc(to,lim);
    }
}

array<int,2> dist(int a,int b)
{
    int l=prelca[b][level[a]];
    return {depth[a]+depth[b]-2*depth[l],d[a]+d[b]-2*d[l]};
}

void find_sz(int a,int par=0)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==par||vis[to]==1) continue;
        find_sz(to,a);
        sz[a]+=sz[to];
    }
}

int find_centroid(int a,int par,int nnow)
{
    for(int to:v[a])
    {
        if(to==par||vis[to]==1) continue;
        if(sz[to]>nnow/2) return find_centroid(to,a,nnow);
    }
    return a;
}

void pre(int a)
{
    st[a].push_back(a);
    for(int to:ch[a])
    {
        pre(to);
        for(int b:st[to])
        {
            st[a].push_back(b);
            prelca[b][level[a]]=lca(a,b);
        }
    }
    for(int to:ch[a]) sort(st[to].begin(),st[to].end(),[&](int x,int y){return dist(a,x)[0]>dist(a,y)[0];});
    sort(ch[a].begin(),ch[a].end(),[&](int x,int y){return (st[x].size()<st[y].size());});
}

void build_cd(int a,int par=0)
{
    find_sz(a);
    int centroid=find_centroid(a,0,sz[a]);
    if(par==0) root=centroid;
    else
    {
        ch[par].push_back(centroid);
        level[centroid]=level[par]+1;
    }
    vis[centroid]=1;
    for(int to:v[centroid])
    {
        if(vis[to]==0) build_cd(to,centroid);
    }
    if(par==0) pre(centroid);
}

void go(int a)
{
    for(int to:ch[a]) go(to);
    /*
    Distance from a to any node in one of the subtrees is bounded by that subtree's size (NOT a's subtree size)
    Therefore by sorting a's subtrees by size, you can process the rolling minimums in O(current subtree's size)
    Thus maintaining the time complexity
    */
    int sznow=st[a].size();
    vector<array<int,2>> best(sznow+1,{inf,0});
    for(int to:ch[a])
    {
        int req=st[to].size();
        deque<array<int,2>> deq; //val,node
        int l=1,r=1; //one to be removed next, one to be added next
        for(int b:st[to])
        {
            auto [x,c]=dist(a,b);
            if(liml<=x&&x<=limr&&2*c>=x) res={a,b};
            while(r<=req&&r<=limr-x)
            {
                while(!deq.empty()&&deq.back()[0]>best[r][0]) deq.pop_back();
                deq.push_back(best[r]);
                r++;
            }
            while(l<=req&&l<liml-x)
            {
                if(!deq.empty()&&deq.front()==best[l]) deq.pop_front();
                l++;
            }
            if(!deq.empty())
            {
                auto [val,id]=deq.front();
                if(2*c-x>=val) res={b,id};
            }
        }
        for(int b:st[to])
        {
            auto [x,c]=dist(a,b);
            best[x]=min(best[x],{x-2*c,b});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> liml >> limr;
    vector<int> opt;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        opt.push_back(c);
    }
    sort(opt.begin(),opt.end());
    dfs(1);
    build_cd(1);
    int l=0,r=n-1;
    while(l<r-1)
    {
        int m=(l+r)/2;
        recalc(1,opt[m]);
        res={0,0};
        go(root);
        if(res[0]!=0) l=m;
        else r=m;
    }
    recalc(1,opt[l]);
    go(root);
    cout << res[0] << " " << res[1] << "\n";
    return 0;
}