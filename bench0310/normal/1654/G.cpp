#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
int h[N];
bool flip[N];
const int bad=(1<<30);
int one[N][18];
int two[N][18];
int lvl[N];
vector<int> ch[N];
vector<int> st[N];
int sz[N];
bool vis[N];
int res[N];
int opt[N];

void find_sz(int a,int p)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(vis[to]||to==p) continue;
        find_sz(to,a);
        sz[a]+=sz[to];
    }
}

int find_centroid(int a,int p,int n)
{
    for(int to:v[a]) if(!vis[to]&&to!=p&&sz[to]>n/2) return find_centroid(to,a,n);
    return a;
}

void dfs_one(int a,int p,int l,int s,int m)
{
    if(m-s>=0) one[a][l]=-s;
    for(int to:v[a])
    {
        if(vis[to]||to==p) continue;
        if(h[to]<h[a]) continue;
        int ns=s+((h[to]==h[a])?1:-1);
        int nm=min(m,ns);
        dfs_one(to,a,l,ns,nm);
    }
}

void dfs_two(int a,int p,int l,int s,int m)
{
    two[a][l]=m;
    for(int to:v[a])
    {
        if(vis[to]||to==p) continue;
        if(h[to]>h[a]) continue;
        int ns=s+((h[to]==h[a])?-1:1);
        int nm=min(m,ns);
        dfs_two(to,a,l,ns,nm);
    }
}

void build_cd(int a,int p)
{
    find_sz(a,0);
    int centroid=find_centroid(a,0,sz[a]);
    lvl[centroid]=(p!=0?lvl[p]+1:0);
    ch[p].push_back(centroid);
    dfs_one(centroid,0,lvl[centroid],0,0);
    dfs_two(centroid,0,lvl[centroid],0,0);
    vis[centroid]=1;
    for(int to:v[centroid]) if(!vis[to]) build_cd(to,centroid);
}

void go(int a)
{
    int l=lvl[a];
    st[a]={a};
    for(int b:ch[a])
    {
        go(b);
        for(int to:st[b]) st[a].push_back(to);
    }
    int n=st[a].size();
    for(int i=0;i<=n;i++) opt[i]=bad;
    for(int to:st[a]) if(two[to][l]!=bad&&flip[to]) opt[-two[to][l]]=min(opt[-two[to][l]],h[to]);
    for(int i=1;i<=n;i++) opt[i]=min(opt[i],opt[i-1]);
    for(int to:st[a]) if(one[to][l]!=bad) res[to]=min(res[to],opt[one[to][l]]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) h[i]=-1;
    queue<int> q;
    auto add=[&](int a,int d)
    {
        if(h[a]==-1)
        {
            q.push(a);
            h[a]=d;
        }
    };
    for(int i=1;i<=n;i++)
    {
        int l;
        cin >> l;
        if(l==1) add(i,0);
    }
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a])
        {
            add(to,h[a]+1);
            if(h[to]==h[a]) flip[a]=1;
        }
    }
    for(int i=1;i<=n;i++) for(int j=0;j<18;j++) one[i][j]=two[i][j]=bad;
    build_cd(1,0);
    for(int i=1;i<=n;i++) res[i]=h[i];
    go(ch[0][0]);
    for(int i=1;i<=n;i++) cout << 2*h[i]-res[i] << " \n"[i==n];
    return 0;
}