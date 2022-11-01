#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

const int N=200003;
vector<int> f(27,0);
vector<int> v[N];
vector<int> sz(N,0);

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r) {return uniform_int_distribution<int>(l,r)(gen);}

const ll pr=N;
const ll mod=rng(1000000007,2000000000);

map<ll,bool> dp[N];

void dfs(int a,int p,int k,vector<int> &opt)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a,k,opt);
        sz[a]+=sz[to];
    }
    if(sz[a]==f[k-1]||sz[a]==f[k-2]) opt.push_back(a);
}

void go(int a,int p,bool in,int x,vector<array<int,2>> &one,vector<array<int,2>> &two)
{
    if(in==0&&x!=a&&p!=0) one.push_back({a,p});
    if(in==1&&x!=a&&p!=0) two.push_back({a,p});
    for(int to:v[a])
    {
        if(to==p) continue;
        go(to,a,in|(a==x),x,one,two);
    }
}

ll get_h(vector<array<int,2>> &edges)
{
    ll h=0;
    for(auto &[a,b]:edges)
    {
        if(a>b) swap(a,b);
        h=(h*pr+a)%mod;
        h=(h*pr+b)%mod;
    }
    return h;
}

bool fib(vector<array<int,2>> &edges,int k)
{
    int n=edges.size()+1;
    if(n<=3) return 1;
    ll h=get_h(edges);
    if(dp[n].find(h)!=dp[n].end()) return dp[n][h];
//    cout << "in n=" << n << endl;
    int root=edges[0][0];
//    cout << "tree: ";
//    for(auto [a,b]:edges) cout << "[" << a << "," << b << "] ";
//    cout << endl;
    for(auto [a,b]:edges)
    {
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool chain=1;
    for(auto [a,b]:edges)
    {
        chain&=(v[a].size()<=2);
        chain&=(v[b].size()<=2);
    }
    if(chain==1)
    {
        for(auto [a,b]:edges)
        {
            v[a].clear();
            v[b].clear();
        }
        return (dp[n][h]=1);
    }
    vector<int> opt;
    dfs(root,0,k,opt);
//    cout << "opt=";
//    for(int a:opt) cout << a << " ";
//    cout << endl;
//    assert(opt.size()<=2);
    vector<array<int,2>> one[2];
    vector<array<int,2>> two[2];
    for(int i=0;i<(int)opt.size();i++)
    {
        int x=opt[i];
        go(root,0,0,x,one[i],two[i]);
//        cout << "go with x=" << x << endl;
    }
    for(auto [a,b]:edges)
    {
        v[a].clear();
        v[b].clear();
    }
    for(int i=0;i<(int)opt.size();i++)
    {
        if(one[i].size()<two[i].size()) one[i].swap(two[i]);
//        cout << "one: ";
//        for(auto [a,b]:one) cout << "[" << a << "," << b << "] ";
//        cout << endl;
//        cout << "two: ";
//        for(auto [a,b]:two) cout << "[" << a << "," << b << "] ";
//        cout << endl;
//        assert((int)one[i].size()+1==f[k-1]);
        bool ok=fib(two[i],k-2);
        if(ok==0) continue;
//        assert((int)two[i].size()+1==f[k-2]);
        ok&=(fib(one[i],k-1));
        if(ok) return (dp[n][h]=1);
    }
    return (dp[n][h]=0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[0]=f[1]=1;
    for(int i=2;i<27;i++) f[i]=f[i-2]+f[i-1];
//    cout << f.size() << endl;
//    for(int i=0;i<(int)f.size();i++) cout << f[i] << " ";
    int n;
    cin >> n;
    vector<array<int,2>> edges(n-1);
    for(int i=0;i<n-1;i++) cin >> edges[i][0] >> edges[i][1];
    int k=-1;
    for(int i=0;i<27;i++) if(n==f[i]) k=i;
    bool res=0;
    if(k!=-1) res=fib(edges,k);
    if(res) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}