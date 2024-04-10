#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<set<int>> v(N);
vector<array<int,2>> g[N];
vector<int> depth(N,0);
vector<int> d(N,0);
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> sz(N,0);
vector<vector<int>> ch(N);
vector<vector<int>> st(N);
vector<int> tree(4*N,0);
ll res=0;
int root=0;
int limd=0,limdepth=0;

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(auto [to,c]:g[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        d[to]=d[a]+c;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
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

void find_sz(int a,int par=0)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==par) continue;
        find_sz(to,a);
        sz[a]+=sz[to];
    }
}

int find_centroid(int a,int par,int n)
{
    for(int to:v[a])
    {
        if(to==par) continue;
        if(sz[to]>n/2) return find_centroid(to,a,n);
    }
    return a;
}

void build_cd(int a,int par=0)
{
    find_sz(a);
    int n=sz[a];
    int centroid=find_centroid(a,0,n);
    if(par==0) root=centroid;
    ch[par].push_back(centroid);
    for(int to:v[centroid])
    {
        v[to].erase(centroid);
        build_cd(to,centroid);
    }
}

array<int,2> dist(int a,int b)
{
    int l=lca(a,b);
    return {d[a]+d[b]-2*d[l],depth[a]+depth[b]-2*depth[l]};
}

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

ll go(vector<array<int,2>> x)
{
    ll cnt=0;
    sort(x.begin(),x.end());
    int m=x.size();
    int mx=0;
    for(int i=0;i<m;i++) mx=max(mx,x[i][1]);
    int idx=0;
    for(int i=m-1;i>=0;i--)
    {
        auto [one,two]=x[i];
        while(idx<m&&x[idx][0]<=limd-one)
        {
            update(1,0,mx,x[idx][1],1);
            idx++;
        }
        cnt+=query(1,0,mx,0,min(limdepth-two,mx));
    }
    for(int i=0;i<idx;i++) update(1,0,mx,x[i][1],-1);
    return cnt;
}

void solve(int a)
{
    st[a].push_back(a);
    vector<array<int,2>> now;
    now.push_back({0,0});
    for(int to:ch[a])
    {
        solve(to);
        vector<array<int,2>> tmp;
        for(int b:st[to])
        {
            tmp.push_back(dist(a,b));
            st[a].push_back(b);
        }
        res-=go(tmp);
        for(array<int,2> x:tmp) now.push_back(x);
    }
    res+=(go(now)-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> limdepth >> limd;
    for(int i=2;i<=n;i++)
    {
        int up,w;
        cin >> up >> w;
        v[up].insert(i);
        v[i].insert(up);
        g[up].push_back({i,w});
        g[i].push_back({up,w});
    }
    dfs(1);
    build_cd(1);
    solve(root);
    cout << res/2 << "\n";
    return 0;
}