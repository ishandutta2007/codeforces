#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (ll i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/
const int maxn = 5e5+100;
int n,tot,first[maxn],des[maxn],nxt[maxn],m;
vector<pii> Q[maxn];
int cnt[maxn][26],Cnt[maxn];
int sz[maxn],dep[maxn],wson[maxn];
bool ans[maxn];
char s[maxn];
bool big[maxn];
inline void addEdge(int x,int y){
    tot++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
}
void get_sz(int node,int depth){
    dep[node] = depth;
    sz[node] = 1;
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        get_sz(v,depth+1);
        sz[node] += sz[v];
        if (sz[v] > sz[wson[node]]){
            wson[node] = v;
        }
    }
}
void add(int node,int sign){
    Cnt[dep[node]] -= cnt[dep[node]][s[node]-'a'];
    cnt[dep[node]][s[node]-'a'] ^=1;
    Cnt[dep[node]] += cnt[dep[node]][s[node]-'a'];
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (big[v])continue;
        add(v,sign);
    }
}
void dfs(int node,bool keep){
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v == wson[node])continue;
        dfs(v,0);
    }
    if (wson[node]){
        big[wson[node]]=1;
        dfs(wson[node],1);
    }
    add(node,1);
    for (auto q:Q[node]){
        ans[q.second] = Cnt[q.first] <=1;
    }
    if (wson[node])big[wson[node]] = 0;
    if (!keep)add(node,-1);
}
int main(){
    scanf("%d%d",&n,&m);
    REP(i,2,n){
        int p;
        scanf("%d",&p);
        addEdge(p,i);
    }
    scanf("%s",s+1);
    rep(i,0,m){
        int v,h;
        scanf("%d%d",&v,&h);
        Q[v].push_back({h,i});
    }
    get_sz(1,1);
    dfs(1,0);
    rep(i,0,m){
        printf("%s\n",ans[i]?"Yes":"No");
    }
    return 0;
}