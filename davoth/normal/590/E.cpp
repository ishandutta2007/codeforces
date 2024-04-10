#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1.5e3+10,LN=18,M=1e7+10,SQ=500,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
int n,match[N],VC[N],dist[N],mark[N],C[M][2],F[M],T,L,R,Q[M],K[M],A[M],adj[N][N],vt[N],tv[N];
string S[N];
vector<int> G[N],ans;
queue<int> q;
bool tof;
bool bfs(){
    memset(VC, 0, sizeof(VC));
    memset(dist, 31, sizeof(dist));
    for (int i=1; i<=n; i++) if (!match[i]){
        dist[i]=0;
        q.push(i);
    }
    bool res=0;
    while (q.size()){
        int v=q.front();
        q.pop();
        if (v<=n){
            VC[v]=1;
            for (int u:G[v]) if (dist[v]+1<dist[u]){
                dist[u]=dist[v]+1;
                q.push(u);
            }
            continue ;
        }
        if (!match[v]){
            res=1;
            continue ;
        }
        dist[match[v]]=dist[v]+1;
        q.push(match[v]);
    }
    return res;
}

bool dfs(int node){
    mark[node]=1;
    for (int v:G[node]) if (!match[v] || dist[node]+1==dist[v] && !mark[match[v]] && dfs(match[v])){
        match[node]=v;
        match[v]=node;
        return 1;
    }
    return 0;
}
void AddTrie(int i){
    int v=0;
    for(char c : S[i]){
        if(!C[v][c-'a']) C[v][c-'a']=++T;
        if(C[v][0] && C[v][1]) tof=1;
        v=C[v][c-'a'];
    }
    K[v]=i;
}
void BuildAho(){
    for(int i=0; i<2; i++) if(C[0][i]) Q[R++]=C[0][i];
    while(L<R){
        int v=Q[L++];
        if(F[v] && K[F[v]]) A[v]=F[v];
        else A[v]=A[F[v]];
        for(int i=0; i<2; i++){
            if(!C[v][i]) C[v][i]=C[F[v]][i];
            else{
                F[C[v][i]]=C[F[v]][i];
                Q[R++]=C[v][i];
            }
        }
    }
}
void AddEdge(int v, int u){
    G[v].pb(u);
    G[u].pb(v);
}
void BuildGraph(int i){
    int v=0;
    for(char c : S[i]){
        v=C[v][c-'a'];
        int u=v;
        while(u){
            if(K[u] && K[u]!=i){
                AddEdge(i,K[u]+n);
                adj[i][K[u]]=1;
            }
            u=A[u];
        }
    }
}
int main(){
    fast_io;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> S[i];
        AddTrie(i);
    }
    BuildAho();
    if(!tof) return cout << "1\n1", 0;
    for(int i=1; i<=n; i++) BuildGraph(i);
    while (bfs()){
        memset(mark, 0, sizeof(mark));
        for (int i=1; i<=n; i++) if (!match[i] && !mark[i]) dfs(i);
    }
    for(int i=1; i<=n+n; i++){
        if(!match[i]){
            vt[i]=-1;
            for(int u : G[i]) tv[u]=1;
        }
    }
    int f=1,k;
    while(f){
        f=k=0;
        for(int i=1; i<=n+n; i++){
            if(vt[i]) continue;
            k=i;
            if(tv[i]){
                f=vt[i]=1;
            }else if(vt[match[i]]){
                vt[i]=-1;
                f=1;
                for(int u : G[i]) tv[u]=1;
            }
        }
        if(!f && k){
            f=vt[k]=1;
        }
    }
    for(int i=1; i<=n; i++) if(vt[i]==-1 && vt[i+n]==-1) ans.pb(i);
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}