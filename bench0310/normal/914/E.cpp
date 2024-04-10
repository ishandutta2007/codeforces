#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<set<int>> g(N);
vector<int> val(N,0);
vector<int> x(N,0);
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(18,0));
vector<ll> diff(N,0);
vector<ll> res(N,0);
vector<int> sz(N,0);
vector<int> ch[N];
vector<int> st[N];
vector<int> cnt((1<<20),0);
vector<int> tmp(N,0);
int root=0;

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    x[a]=(x[p[a][0]]^(1<<val[a]));
    for(int i=1;i<18;i++) p[a][i]=p[p[a][i-1]][i-1];
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
    for(int i=17;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=17;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

int pathx(int a,int b,int l)
{
    return (x[a]^x[b]^(1<<val[l]));
}

void find_sz(int a,int par=0)
{
    sz[a]=1;
    for(int to:g[a])
    {
        if(to==par) continue;
        find_sz(to,a);
        sz[a]+=sz[to];
    }
}

int find_centroid(int a,int par,int n)
{
    for(int to:g[a])
    {
        if(to==par) continue;
        if(sz[to]>n/2) return find_centroid(to,a,n);
    }
    return a;
}

void build_cd(int a,int par=0)
{
    find_sz(a);
    int centroid=find_centroid(a,0,sz[a]);
    ch[par].push_back(centroid);
    if(par==0) root=centroid;
    for(int to:g[centroid])
    {
        g[to].erase(centroid);
        build_cd(to,centroid);
    }
}

void add(int a,int b,ll c,int l)
{
    diff[a]+=c;
    diff[b]+=c;
    diff[l]-=(2*c);
    res[l]+=c;
}

void go(int a)
{
    st[a].push_back(a);
    for(int to:ch[a])
    {
        go(to);
        for(int b:st[to]) st[a].push_back(b);
    }
    for(int to:ch[a])
    {
        for(int b:st[to])
        {
            tmp[b]=lca(a,b);
            cnt[pathx(a,b,tmp[b])]++;
        }
    }
    ll now=0;
    for(int to:ch[a])
    {
        for(int b:st[to]) cnt[pathx(a,b,tmp[b])]--;
        for(int b:st[to])
        {
            int z=pathx(a,b,tmp[b]);
            if(__builtin_popcount(z)<=1) add(a,b,1,tmp[b]);
            z^=(1<<val[a]);
            now+=cnt[z];
            add(a,b,cnt[z],tmp[b]);
            for(int j=0;j<20;j++)
            {
                now+=cnt[z^(1<<j)];
                add(a,b,cnt[z^(1<<j)],tmp[b]);
            }
        }
        for(int b:st[to]) cnt[pathx(a,b,tmp[b])]++;
    }
    add(a,a,-now/2+1,a);
    for(int to:ch[a]) for(int b:st[to]) cnt[pathx(a,b,tmp[b])]--;
}

ll solve(int a)
{
    ll now=diff[a];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        now+=solve(to);
    }
    res[a]+=now;
    return now;
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
        g[a].insert(b);
        g[b].insert(a);
    }
    string s;
    cin >> s;
    s="$"+s;
    for(int i=1;i<=n;i++) val[i]=(s[i]-'a');
    dfs(1);
    build_cd(1);
    go(root);
    solve(1);
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}