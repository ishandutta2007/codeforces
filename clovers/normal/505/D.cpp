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
const int N=100005;
int n,m;
pii E[N];
namespace DSU{
    int fa[N];
    void init(){for(int i=1;i<=n;i++) fa[i]=i;}
    int getfather(int x){return x==fa[x] ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){
        x=getfather(x); y=getfather(y);
        fa[y]=x;
    }
}
vector<int> v[N],P[N];
int vis[N],dfn[N],out[N],cnt=0,in[N];

int main()
{
    n=read(); m=read();
    DSU::init();
    for(int i=1;i<=m;i++){
        E[i].first=read(),E[i].second=read();
        DSU::unite(E[i].first,E[i].second);
        v[E[i].first].push_back(E[i].second);
    }
    for(int i=1;i<=n;i++){
        int x=DSU::getfather(i);
        P[x].push_back(i);
    }
    int ans=0;
    for(int rnd=1;rnd<=n;rnd++)if(rnd==DSU::getfather(rnd)){
        queue<int> q;
        int cnt=0;
        for(auto &u : P[rnd]){
            for(auto &to : v[u]) in[to]++;
        } 
        for(auto &u : P[rnd]) if(!in[u]) q.push(u);
        while(!q.empty()){
            int u=q.front(); q.pop(); cnt++;
            for(auto &to : v[u]){
                if(!--in[to]) q.push(to);
            }
        }
        if(cnt!=sz(P[rnd])) ans+=sz(P[rnd]);
        else ans+=sz(P[rnd])-1;
    }
    cout<<ans<<endl;
    return 0;
}