#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll inf=(1ll<<60);

struct line
{
    ll k,n;
    mutable ll r;
    line(ll a,ll b){k=a;n=b;r=0;}
    bool operator<(const line &o)const{return (k>o.k);}
    bool operator<(const ll &o)const{return (r<o);}
};

struct cht
{
    set<line,less<>> s;
    double intersect(line a,line b) {return ((double)b.n-a.n)/(a.k-b.k);}
    void add(ll k,ll n)
    {
        line now(k,n);
        auto it=s.lower_bound(now);
        if(it!=s.end()&&it->k==k)
        {
            if(n<it->n) it=s.erase(it);
            else return;
        }
        if(it!=s.end()&&it!=s.begin()&&intersect(now,*prev(it))>intersect(now,*it)) return;
        s.insert(now);
        while(it!=s.end()&&next(it)!=s.end()&&intersect(now,*it)>intersect(*it,*next(it))) it=s.erase(it);
        it--;
        while(it!=s.begin()&&prev(it)!=s.begin()&&intersect(now,*prev(it))<intersect(*prev(it),*prev(prev(it)))) s.erase(prev(it));
        if(it!=s.begin()) prev(it)->r=floor(intersect(now,*prev(it)));
        if(next(it)!=s.end()) it->r=floor(intersect(now,*next(it)));
        else it->r=inf;
    }
    ll query(ll a)
    {
        line best=*s.lower_bound(a);
        return (best.k*a+best.n);
    }
};

const int N=100005;
vector<int> v[N];
vector<ll> one(N,0);
vector<ll> two(N,0);
vector<int> sz(N,0);
vector<int> big(N,0);
vector<ll> dp(N,inf);

void dfs(int a,int p=0)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

cht solve(int a,int p=0)
{
    cht c;
    if(big[a]==0) dp[a]=0;
    else
    {
        c=solve(big[a],a);
        for(int to:v[a])
        {
            if(to==p||to==big[a]) continue;
            cht tmp=solve(to,a);
            for(line l:tmp.s) c.add(l.k,l.n);
        }
        dp[a]=c.query(one[a]);
    }
    c.add(two[a],dp[a]);
    return c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> one[i];
    for(int i=1;i<=n;i++) cin >> two[i];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    solve(1);
    for(int i=1;i<=n;i++) cout << dp[i] << " \n"[i==n];
    return 0;
}