#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=405;
//i_am_noob
//#define wiwihorz  
int n,m,e[605][2],dis[maxn][maxn],ans[maxn][maxn],cnt[maxn];
vector<int> adj[maxn];
bool flag,vis[maxn];

void hhhhauraorz(){
    cin >> n >> m;
    rep(m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        e[i][0]=u,e[i][1]=v;
        adj[u].pb(v),adj[v].pb(u);
    }
    rep(n) rep1(j,n){
        if(i==j) dis[i][j]=0;
        else dis[i][j]=inf;
    }
    rep(m) dis[e[i][0]][e[i][1]]=dis[e[i][1]][e[i][0]]=1;
    rep1(k,n) rep(n) rep1(j,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    queue<int> que;
    int x,y;
    rep(n) rep2(j,i,n){
        /*
        que.push(i);
        rep1(k,n) vis[k]=0;
        vis[i]=1;
        while(!que.empty()){
            x=que.front(),que.pop();
            for(auto v: adj[x]) if((!vis[v])&&dis[i][x]!=dis[i][v]&&dis[j][x]!=dis[j][v]){
                que.push(v);
                vis[v]=1;
            }
            if(vis[j]) break;
        }
        if(!vis[j]){
            ans[i][j]=0;
            bug(i,j);
            continue;
        }
        while(!que.empty()) que.pop();
        */

        que.push(i);
        rep1(k,n) vis[k]=0;
        vis[i]=1;
        while(!que.empty()){
            x=que.front(),que.pop();
            for(auto v: adj[x]) if((!vis[v])&&dis[i][x]!=dis[i][v]&&dis[j][x]!=dis[j][v]&&dis[i][x]+dis[j][x]==dis[i][v]+dis[j][v]){
                que.push(v);
                vis[v]=1;
            }
        }
        y=0;
        rep1(k,n) if(vis[k]) y++;
        if((!vis[j])||y!=dis[i][j]+1){
            ans[i][j]=0;
            continue;
        }

        x=0;
        rep1(k,n) cnt[k]=0;
        rep1(k,m){
            if(dis[i][e[k][0]]==dis[i][e[k][1]]||dis[j][e[k][0]]==dis[j][e[k][1]]) continue;
            if(dis[i][e[k][0]]+dis[j][e[k][0]]==dis[j][e[k][1]]+dis[i][e[k][1]]);
            else if(dis[i][e[k][0]]>dis[i][e[k][1]]) cnt[e[k][0]]++;
            else cnt[e[k][1]]++;
        }

        ans[i][j]=1;
        rep1(k,n) if(!vis[k]) ans[i][j]=ans[i][j]*cnt[k]%MOD;
    }
    rep(n){
        rep1(j,n){
            if(i<=j) cout << ans[i][j] << ' ';
            else cout << ans[j][i] << ' ';
        }
        cout << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}