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
const int maxn = 2e5+100;
int first[maxn],nxt[maxn],des[maxn],tot,n,m;
int sz[maxn],dep[maxn],wson[maxn];
bool big[maxn];
unordered_map<int,int> cnt[maxn];
vector<pii> Query[maxn];
int ans[maxn];
map<string,int> id;int idcnt;
int a[maxn];
inline int get_id(const string & str){
    if (id.find(str) == id.end()){
        id[str] = ++idcnt;
    }
    return id[str];
}
inline void addEdge(int x,int y){
    tot ++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
}
void get_sz(int node,int depth){
    sz[node] = 1;
    dep[node] = depth;
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        get_sz(v,depth+1);
        sz[node] += sz[v];
        if (sz[v] > sz[wson[node]]){
            wson[node] = v;
        }
    }
}
void add(int node){
    cnt[dep[node]][a[node]] ++;
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (big[v])continue;
        add(v);
    }
}
void rem(int node){
    auto it = cnt[dep[node]].find(a[node]);
    it->second --;
    if (!it->second){
        cnt[dep[node]].erase(it);
    }
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (big[v])continue;
        rem(v);
    }
}
void dfs(int node,bool keep){
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v == wson[node])continue;
        dfs(v,0);
    }
    if (wson[node]){
        big[wson[node]] = 1;
        dfs(wson[node],1);
    }
    add(node);
    rep(i,0,Query[node].size()){
        ans[Query[node][i].second] = cnt[dep[node] + Query[node][i].first].size();
    }
    if (wson[node]) big[wson[node]] = 0;
    if (!keep)rem(node);
}
int main(){
    untie;
    cin>>n;
//    scanf("%d",&n);
    REP(i,1,n){
        string name;
        int fa;
        cin>>name>>fa;
        a[i] = get_id(name);
        if (fa == 0){
            fa = n+1;
        }
        addEdge(fa,i);
    }
    cin>>m;
//    scanf("%d",&m);
    REP(i,1,m){
        int v,h;
        cin>>v>>h;
//        scanf("%d%d",&v,&h);
        Query[v].push_back({h,i});
    }
    get_sz(n+1,1);
    dfs(n+1,0);
    REP(i,1,m){
//        printf("%d\n",ans[i]);
        cout<<ans[i]<<'\n';
    }
    return 0;
}