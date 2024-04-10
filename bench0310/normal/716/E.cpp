#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod=0;
const int N=100005;
vector<array<int,2>> v[N];
vector<set<int>> g(N);
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(17,0));
vector<ll> up(N,0);
vector<ll> down(N,0);
vector<int> sz(N,0);
vector<int> ch[N];
vector<int> st[N];
vector<ll> pw(N,1);
vector<ll> inv(N,1);
ll res=0;
int root=0;

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(auto [to,k]:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        down[to]=(10*down[a]+k)%mod;
        up[to]=(pw[depth[a]-1]*k+up[a])%mod;
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

int dist(int a,int b)
{
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}

ll h(int a,int b)
{
    int l=lca(a,b);
    ll x=(((up[a]-up[l]+mod)%mod)*inv[depth[l]-1])%mod;
    ll y=(((down[b]-pw[depth[b]-depth[l]]*down[l])%mod)+mod)%mod;
    ll z=(pw[depth[b]-depth[l]]*x+y)%mod;
    return z;
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
    int n=sz[a];
    int centroid=find_centroid(a,0,n);
    if(par==0) root=centroid;
    ch[par].push_back(centroid);
    for(int to:g[centroid])
    {
        g[to].erase(centroid);
        build_cd(to,centroid);
    }
}

ll fpow(ll b,ll e)
{
    ll x=1;
    while(e)
    {
        if(e&1) x=(x*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return x;
}

ll find_inv()
{
    ll x=mod;
    ll tmp=mod;
    for(ll i=2;i*i<=tmp;i++)
    {
        if((tmp%i)==0)
        {
            x/=i;
            x*=(i-1);
        }
        while((tmp%i)==0) tmp/=i;
    }
    if(tmp>1)
    {
        x/=tmp;
        x*=(tmp-1);
    }
    return fpow(10,x-1);
}

void solve(int a)
{
    map<int,int> m;
    for(int to:ch[a])
    {
        solve(to);
        for(int x:st[to])
        {
            m[h(x,a)]++;
            st[a].push_back(x);
        }
    }
    res+=m[0];
    st[a].push_back(a);
    for(int to:ch[a])
    {
        for(int x:st[to]) m[h(x,a)]--;
        for(int x:st[to])
        {
            ll z=h(a,x);
            if(z==0) res++;
            ll val=(((-z*inv[dist(a,x)])%mod)+mod)%mod;
            res+=m[val];
        }
        for(int x:st[to]) m[h(x,a)]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> mod;
    for(int i=0;i<n-1;i++)
    {
        int a,b,k;
        cin >> a >> b >> k;
        a++;
        b++;
        v[a].push_back({b,k});
        v[b].push_back({a,k});
        g[a].insert(b);
        g[b].insert(a);
    }
    for(int i=1;i<=n;i++) pw[i]=(10*pw[i-1])%mod;
    inv[1]=find_inv();
    for(int i=2;i<=n;i++) inv[i]=(inv[i-1]*inv[1])%mod;
    dfs(1);
    build_cd(1);
    solve(root);
    cout << res << "\n";
    return 0;
}