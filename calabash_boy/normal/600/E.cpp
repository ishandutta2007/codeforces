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

const int maxn = 1e5+100;
int a[maxn],first[maxn],des[maxn*2],nxt[maxn*2],tot;
int n;
map<int,int> *cnt[maxn];
ll ans[maxn];
int mx[maxn];
int sz[maxn],wson[maxn];
inline void addEdge(int x,int y){
    tot ++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
}
inline void relax(int v,int t,int cnt){
    if (cnt>mx[v]){
        mx[v] = cnt;
        ans[v] = t;
    }else if (cnt == mx[v]){
        ans[v] +=t;
    }
}
void dfs(int node,int father){
    sz[node] = 1;
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v == father)continue;
        dfs(v,node);
        sz[node] += sz[v];
        if (sz[v] > sz[wson[node]]){
            wson[node] = v;
        }
    }
    if (wson[node]){
        cnt[node] = cnt[wson[node]];
        ans[node] = ans[wson[node]];
        mx[node] = mx[wson[node]];
    }else{
        cnt[node] = new map<int,int>();
    }
    (*cnt[node])[a[node]]++;
    relax(node,a[node],(*cnt[node])[a[node]]);
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v == father || v == wson[node])continue;
        for (auto pair : *cnt[v]){
            (*cnt[node])[pair.first] += pair.second;
            relax(node,pair.first,(*cnt[node])[pair.first]);
        }
    }

}
int main(){
    untie;
    cin>>n;
    REP(i,1,n)cin>>a[i];
    rep(i,1,n){
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
        addEdge(y,x);
    }
    dfs(1,0);
    REP(i,1,n)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}