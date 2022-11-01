#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;
const int N=100005;
int n;
vector<int> v[N];
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> sz(N,0);
vector<int> big(N,0);
vector<int> head(N,0);
vector<int> pos(N,0);
int tcnt=1;
vector<int> tree(4*N,0);

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

void decompose(int a,int h)
{
    head[a]=h;
    pos[a]=tcnt++;
    if(big[a]!=0) decompose(big[a],h);
    for(int to:v[a]) if(to!=p[a][0]&&to!=big[a]) decompose(to,to);
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=16;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

void update(int idx,int l,int r,int x,int val)
{
    if(l==r) tree[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(x<=m) update(2*idx,l,m,x,val);
        else update(2*idx+1,m+1,r,x,val);
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

int up(int a,int b)
{
    int res=0;
    while(depth[head[b]]>depth[a])
    {
        res+=query(1,1,n,pos[head[b]],pos[b]);
        b=p[head[b]][0];
    }
    res+=query(1,1,n,pos[a],pos[b]);
    return res;
}

int qry(int a,int b)
{
    int l=lca(a,b);
    return up(l,a)+up(l,b)-query(1,1,n,pos[l],pos[l]);
}

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int all=10000000;
    vector<int> sieve(all+1,0);
    for(int i=1;i<=all;i++) sieve[i]=i;
    for(ll i=2;i<=all;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=all;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    auto factorise=[&](int a)->vector<array<int,2>>
    {
        vector<array<int,2>> primes;
        while(a>1)
        {
            primes.push_back({sieve[a],0});
            while(sieve[a]==primes.back()[0])
            {
                primes.back()[1]++;
                a/=sieve[a];
            }
        }
        return primes;
    };
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    decompose(1,1);
    vector<array<int,6>> events; //prime,power,tp,a,b,id
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        for(auto [prime,power]:factorise(a)) for(int pw=1;pw<=power;pw++) events.push_back({prime,pw,0,i,0,0});
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        int a,b,x;
        cin >> a >> b >> x;
        for(auto [prime,pw]:factorise(x)) events.push_back({prime,pw,1,a,b,i});
    }
    sort(events.begin(),events.end());
    int l=0;
    vector<ll> res(q+1,1);
    while(l<(int)events.size())
    {
        int prime=events[l][0];
        int r=l;
        while(r<(int)events.size()&&events[r][0]==prime)
        {
            while(r<(int)events.size()&&events[r][0]==prime&&events[r][2]==0)
            {
                update(1,1,n,pos[events[r][3]],1);
                r++;
            }
            while(r<(int)events.size()&&events[r][0]==prime&&events[r][2]==1)
            {
                int a=events[r][3];
                int b=events[r][4];
                int id=events[r][5];
                res[id]=(res[id]*fpow(prime,qry(a,b)))%mod;
                r++;
            }
        }
        for(int i=l;i<r;i++) if(events[i][2]==0) update(1,1,n,pos[events[i][3]],-1);
        l=r;
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}