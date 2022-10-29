/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=200005;
ll ans=0;
struct Edge{
    int x,y,c;
    bool operator < (const Edge &rhs) const{
        return c<rhs.c;
    }
}E[N];
int n,m;
set<int> st[N];
set<int> st2;
namespace DSU{
    int fa[N];
    void init(){for(int i=1;i<=n;i++) fa[i]=i;}
    int getfather(int x){return fa[x]==x ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){fa[getfather(x)]=getfather(y);}
    bool same(int x,int y){return getfather(x)==getfather(y);}
}
vector<pii> v[N];
int cnt=0,vis[N];
void dfs1(int u){
    queue<int> q;
    q.push(u); st2.erase(u);
    while(!q.empty()){
        int u=q.front(); q.pop();
        vector<int> used;
        for(auto &to : st2){
            if(st[u].count(to)) continue;
            q.push(to); used.push_back(to);
            v[u].push_back(mk(to,0)); 
            v[to].push_back(mk(u,0));
            cnt++; DSU::unite(u,to); q.push(to);
        }
        for(auto &to : used) st2.erase(to);
    }
}
int dep[N],fa[N],fe[N];
void dfs(int u){
    for(auto &to : v[u]){
        if(to.first==fa[u]) continue;
        fa[to.first]=u; fe[to.first]=to.second; 
        dep[to.first]=dep[u]+1;
        dfs(to.first);
    }
}

ll mi,sum=0;
int split(int x,int y){
    int ret=0;
    while(x!=y){
        if(dep[x]>dep[y]) ret|=(fe[x]==0),x=fa[x];
        else ret|=(fe[y]==0),y=fa[y];
    }
    return ret;
}
int main()
{
    n=read(); m=read();
    DSU::init();
    for(int i=1;i<=m;i++){
        E[i].x=read(),E[i].y=read(),E[i].c=read();
        st[E[i].x].insert(E[i].y); st[E[i].y].insert(E[i].x);
        sum^=E[i].c;
    }
    mi=sum;
    for(int i=1;i<=n;i++) st2.insert(i);
    while(!st2.empty()){
        int u=*st2.begin();
        dfs1(u);
    }
    sort(E+1,E+m+1);
    for(int i=1;i<=m;i++){
        int x=E[i].x,y=E[i].y;
        if(DSU::same(x,y)) continue;
        v[x].push_back(mk(y,E[i].c));
        v[y].push_back(mk(x,E[i].c));
        DSU::unite(x,y); ans+=E[i].c; vis[i]=1;
    }
    ll rest=1ll*n*(n-1)/2-m;
    if(rest>cnt){
        printf("%lld\n",ans);
        return 0;
    }
    dfs(1);
    for(int i=1;i<=m;i++) if(!vis[i]){
        if(split(E[i].x,E[i].y)) checkmin(mi,E[i].c);
    }
    cout<<ans+mi<<endl;
    return 0;
}