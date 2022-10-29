// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef ritick
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 100000000000000000
#define MOD 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb emplace_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef ritick
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<int>(l, r)(rng32)
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }


struct node{
    int nxt[26];
    node(){
        memset(nxt, -1, sizeof(nxt));
    }
    int& operator [](int x){
        return nxt[x];
    }
};
node tri[400100];
ll ts=1;

const ll n1=400106;//size of fenwick tree
ll bt[n1];
ll getSum(ll x)
{
    ll sum=0;
    for(;x>=1;x-=(x&-x))
        sum+=bt[x];
    return sum;
}
void update(ll x, ll d)
{
    // if(x==3)
    // {
    // trace(x,d);
    // }
    if(x==0)
    {
        return ;
    }
    for(;x<=n1;x+=(x&-x))
    {
        bt[x]+=d;
    }
}
ll get(ll l,ll r)
{
    return getSum(r)-getSum(l-1);
}

const int ALPHABET_SIZE=26;
const unsigned char MINIMAL_CHAR='a';

struct AhoCorasick {
    int NON_EXISTENT_NODE_ID = -1;
    int FAKE_NODE_ID = 0;
    int ROOT_ID = 1;

    int currentNode;

    vector<array<int, ALPHABET_SIZE>> edges;
    vector<int> suffixLink;
    vector<int> tind;


    AhoCorasick(const vector<string> &a) : currentNode(ROOT_ID), edges(2),
                                                               suffixLink(2, FAKE_NODE_ID)  {
        edges[FAKE_NODE_ID].fill(ROOT_ID);
        edges[ROOT_ID].fill(NON_EXISTENT_NODE_ID);
        for (const auto &p : a) {
            int node = ROOT_ID;
            for (unsigned char c : p) {
                c -= MINIMAL_CHAR;
                if (edges[node][c] == -1) {
                    edges[node][c] = edges.size();
                    edges.emplace_back();
                    edges.back().fill(NON_EXISTENT_NODE_ID);
                    suffixLink.push_back(NON_EXISTENT_NODE_ID);
                }
                node = edges[node][c];
            }
            tind.pb(node);
        }

        queue<int> q;
        q.push(ROOT_ID);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                int child = edges[node][i];
                if (child == NON_EXISTENT_NODE_ID) {
                    edges[node][i] = edges[suffixLink[node]][i];
                } else {
                    suffixLink[child] = edges[suffixLink[node]][i];
                    q.push(child);
                }
            }
        }
    }

    void setNode(int node) {
        currentNode = node;
    }

    void resetNode() {
        setNode(ROOT_ID);
    }


    void move(unsigned char c) {
        c -= MINIMAL_CHAR;
        currentNode = edges[currentNode][c];
    }
    ll getind(ll x) {
        return tind[x];
    }
    ll getsz()
    {
        return suffixLink.size();
    }

    ll getnext(ll x,int c)
    {
        return edges[x][c];
    }
    ll getSlink(ll x){
        return suffixLink[x];
    }
};

ll add_song(ll cur,ll x)
{
    if(tri[cur][x]==-1)
    {
        tri[ts]=node();
        tri[cur][x]=ts++;
    }
    return tri[cur][x];
}
vector<ll>song[400100];
ll trieind[400100];
vector<ll>q[400100];
// ll tind[400100];
ll ans[400100];
ll tin[400100];
ll tout[400100];
vector<ll>adj[400100];

ll tim=1;
void dfs0(ll x)
{
    tin[x]=tim++;
    for(auto z:adj[x])
    {
        dfs0(z);
    }
    tout[x]=tim-1;
}

vector<string>sx;
AhoCorasick ac(sx);
void dfs(ll x,ll cur)
{   
    // trace(x,cur);
    update(tin[cur],1);
    rep(i,26)
    {
        if(tri[x][i]!=-1)
            dfs(tri[x][i],ac.getnext(cur,i));
    }
    for(auto z1:song[x])
    {
        for(auto z:q[z1])
        {
            ll ti=ac.getind(z);
            // trace(ti);
            // trace(tin[ti]);
            // trace(tout[ti]);
            ans[z]+=get(tin[ti],tout[ti]);
        }
    }

    update(tin[cur],-1);
}
void solve() 
{   
    ll n;
    cin>>n;
    tri[0]=node();
    rep(i,n)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            char ch;
            cin>>ch;
            trieind[i+1]=add_song(0,ch-'a');
        }
        else
        {
            ll x;
            char ch;
            cin>>x>>ch;
            trieind[i+1]=add_song(trieind[x],ch-'a');
        }
        song[trieind[i+1]].pb(i+1);
    }
    ll m;
    cin>>m;
    rep(i,m)
    {
        ll x;
        cin>>x;
        string s;
        cin>>s;
        sx.pb(s);
        q[x].pb(i);
    }
    AhoCorasick ax(sx);
    ac=ax;
    ll n2=ac.getsz();
    for(ll i=2;i<n2;i++)
    {
        // trace(ac.getSlink(i));
        adj[ac.getSlink(i)].pb(i);
    }
    dfs0(1);
    dfs(0,1);
    rep(i,m)
    {
        cout<<ans[i]<<endl;
    }


}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
    #ifdef ritick
        cin.exceptions(cin.failbit);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    fr(i,1,t)
    {   
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}