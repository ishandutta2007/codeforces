#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ull unsigned long long
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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
const int MOD=Mod;
const int maxn=500005;
//i_am_noob
inline char readchar(){
    const int maxn=1000000;
    static char buf[maxn],*p=buf,*q=buf;
    if(p==q&&(q=(p=buf)+fread(buf,1,maxn,stdin))==buf) return EOF;
    else return *p++;
}

inline int readint(){
    int c=readchar(),x=0,neg=0;
    while((c<'0'||c>'9')&&c!='-'&&c!=EOF) c=readchar();
    if(c=='-') neg=1,c=readchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c-'0'),c=readchar();
    if(neg) x=-x;
    return x;
}

int n,e[maxn][3],dist[maxn][2],_time,l[maxn][2],r[maxn][2],pos[maxn][2],maxx,p[2],q,x;
vector<int> adj[maxn];
 
void dfs(int u, int pa, int k){
    dist[u][k]=pa==-1?0:dist[pa][k]+1;
    l[u][k]=++_time;
    pos[_time][k]=u;
    for(auto v: adj[u]) if(v!=pa) dfs(v,u,k);
    r[u][k]=_time;
}
 
int minval[4*maxn][2],maxval[4*maxn][2],tag[4*maxn][2];
 
void pull(int k, int l, int r, int noob){minval[k][noob]=min(minval[k<<1][noob],minval[k<<1|1][noob]),maxval[k][noob]=max(maxval[k<<1][noob],maxval[k<<1|1][noob]);}
 
void push(int k, int l, int r, int noob){
    if(l!=r&&tag[k][noob]==-1){
        swap(minval[k<<1][noob],maxval[k<<1][noob]);
        minval[k<<1][noob]*=-1,maxval[k<<1][noob]*=-1;
        swap(minval[k<<1|1][noob],maxval[k<<1|1][noob]);
        minval[k<<1|1][noob]*=-1,maxval[k<<1|1][noob]*=-1;
        tag[k<<1][noob]*=-1,tag[k<<1|1][noob]*=-1;
    }
    tag[k][noob]=1;
}
 
void build(int k, int l, int r, int noob){
    tag[k][noob]=1;
    if(l==r){
        minval[k][noob]=maxval[k][noob]=dist[pos[l][noob]][noob];
        return;
    }
    build(k<<1,l,l+r>>1,noob),build(k<<1|1,(l+r>>1)+1,r,noob);
    pull(k,l,r,noob);
}
 
void invert(int k, int l, int r, int ql, int qr, int noob){
    if(l>qr||r<ql) return;
    if(l>=ql&&r<=qr){
        tag[k][noob]*=-1;
        swap(minval[k][noob],maxval[k][noob]);
        minval[k][noob]*=-1,maxval[k][noob]*=-1;
        return;
    }
    push(k,l,r,noob);
    invert(k<<1,l,l+r>>1,ql,qr,noob),invert(k<<1|1,(l+r>>1)+1,r,ql,qr,noob);
    pull(k,l,r,noob);
}
 
int query(int k, int l, int r, int ql, int qr, int noob){
    if(l>qr||r<ql) return -inf;
    if(l>=ql&&r<=qr) return maxval[k][noob];
    push(k,l,r,noob);
    return max(query(k<<1,l,l+r>>1,ql,qr,noob),query(k<<1|1,(l+r>>1)+1,r,ql,qr,noob));
}
 
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    n=readint();
    rep(n-1){
        e[i][0]=readint(),e[i][1]=readint(),e[i][2]=readint();
        e[i][0]--,e[i][1]--;
        adj[e[i][0]].pb(e[i][1]),adj[e[i][1]].pb(e[i][0]);
    }
    dfs(0,-1,0);
    maxx=-inf;
    rep(n) if(dist[i][0]>maxx) maxx=dist[i][0],p[0]=i;
    _time=0;
    dfs(p[0],-1,0);
    maxx=-inf;
    rep(n) if(dist[i][0]>maxx) maxx=dist[i][0],p[1]=i;
    _time=0;
    dfs(p[1],-1,1);
    rep(2) build(1,1,n,i);
    rep(n-1) if(e[i][2]) rep1(j,2){
        int u=e[i][0],v=e[i][1];
        if(dist[u][j]<dist[v][j]) invert(1,1,n,l[v][j],r[v][j],j);
        else invert(1,1,n,l[u][j],r[u][j],j);
    }
    q=readint();
    while(q--){
        x=readint();
        x--;
        int u=e[x][0],v=e[x][1];
        rep1(j,2){
            if(dist[u][j]<dist[v][j]) invert(1,1,n,l[v][j],r[v][j],j);
            else invert(1,1,n,l[u][j],r[u][j],j);
        }
        print(max(query(1,1,n,1,n,0),query(1,1,n,1,n,1)));
    }
    return 0;
}