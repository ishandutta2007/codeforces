/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)2e9+5;
const ll INF=(ll)5e17;
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
const int N=1005;
struct node{
    int x,y;
}a[N];
int n,valx[N],valy[N],topx=0,topy=0;

bool insameline(int i,int j){
    return a[i].x==a[j].x||a[i].y==a[j].y;
}
namespace DSU{
    int fa[N],sz[N];
    vector<pii> v;
    void init(){for(int i=1;i<=n+1;i++) fa[i]=i,sz[i]=1; v.clear();}
    int getfather(int x){return fa[x]==x ? x : getfather(fa[x]);}
    bool same(int x,int y){return getfather(x)==getfather(y);}
    void unite(int x,int y){
        x=getfather(x),y=getfather(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        fa[y]=x; sz[x]+=sz[y];
        v.push_back(mk(x,y));
    }
    void back(){
        pii u=v.back(); v.pop_back();
        fa[u.second]=u.second; sz[u.first]-=sz[u.second];
    }
}

vector<int> seq[N];
struct Edge{
    int x,y,w;
    bool operator < (const Edge &rhs) const{return w<rhs.w;}
}E[N*N];
namespace solver0{
    int main(){
        int m=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i].x==a[j].x) E[++m]={i,j,_abs(valy[a[i].y]-valy[a[j].y])};
                if(a[i].y==a[j].y) E[++m]={i,j,_abs(valx[a[i].x]-valx[a[j].x])};
            }
        }
        sort(E+1,E+m+1); DSU::init();
        int pre=-1,now=-1;
        for(int i=1;i<=m;i++){
            int x=E[i].x,y=E[i].y,w=E[i].w;
            if(!DSU::same(x,y)){
                DSU::unite(x,y);
                pre=now; now=w;
            }
        }
        return max(now-now/2,pre);
    }
}
int m,vis[2][N][N],cnt,ans,bl[N][N];
vector<pii> vv[2][N][N];
int run(){
    int ret=0;
    sort(E+1,E+m+1); int num=0;
    for(int i=1;i<=m;i++){
        int x=E[i].x,y=E[i].y,w=E[i].w;
        if(!DSU::same(x,y)){
            DSU::unite(x,y);
            num++; ret=w;
        }
    }
    while(num--) DSU::back();
    return ret;
}
void Kruskal(vector<int> &v,int id){
    m=0;
    for(int i=0;i<sz(v);i++){
        for(int j=i+1;j<sz(v);j++){
            int x=v[i],y=v[j];
            if(a[x].x==a[y].x) E[++m]={x,y,_abs(valy[a[x].y]-valy[a[y].y])};
            if(a[x].y==a[y].y) E[++m]={x,y,_abs(valx[a[x].x]-valx[a[y].x])};
        }
    }
    sort(E+1,E+m+1); DSU::init();
    int p1[4]={0},p2[4]={0},w0,w1,w2,w3;
    for(int i=1;i<=m;i++){
        int x=E[i].x,y=E[i].y,w=E[i].w;
        if(!DSU::same(x,y)){
            DSU::unite(x,y);
            p1[3]=p1[2]; p2[3]=p2[2]; w3=w2;
            p1[2]=p1[1]; p2[2]=p2[1]; w2=w1; 
            p1[1]=p1[0]; p2[1]=p2[0]; w1=w0;
            p1[0]=x; p2[0]=y; w0=w;
        }
    }
    if(p1[0]) DSU::back(); if(p1[1]) DSU::back(); 
    if(p1[2]) DSU::back(); if(p1[3]) DSU::back();
    for(int i=1;i<=topx;i++) for(int j=1;j<=topy;j++) vis[id][i][j]=inf;
    for(auto &u : v){
        for(int i=a[u].x+1;i<=topx;i++){
            if(bl[i][a[u].y]) break;
            int w=_abs(valx[i]-valx[a[u].x]);
            vv[id][i][a[u].y].push_back(mk(u,w));
        }
        for(int i=a[u].x-1;i;i--){
            if(bl[i][a[u].y]) break;
            int w=_abs(valx[i]-valx[a[u].x]);
            vv[id][i][a[u].y].push_back(mk(u,w));
        }
        for(int i=a[u].y+1;i<=topy;i++){
            if(bl[a[u].x][i]) break;
            int w=_abs(valy[i]-valy[a[u].y]);
            vv[id][a[u].x][i].push_back(mk(u,w));
        }
        for(int i=a[u].y-1;i;i--){
            if(bl[a[u].x][i]) break;
            int w=_abs(valy[i]-valy[a[u].y]);
            vv[id][a[u].x][i].push_back(mk(u,w));
        }
    }
    for(int i=1;i<=topx;i++){
        for(int j=1;j<=topy;j++) if(sz(vv[id][i][j])){
            m=0;
            if(p1[0]) E[++m]={p1[0],p2[0],w0}; 
            if(p1[1]) E[++m]={p1[1],p2[1],w1}; 
            if(p1[2]) E[++m]={p1[2],p2[2],w2};
            if(p1[3]) E[++m]={p1[3],p2[3],w3};
            for(auto &e : vv[id][i][j]) E[++m]={n+1,e.first,e.second};
            vis[id][i][j]=run();
        }
    }
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        a[i].x=read(),a[i].y=read();
        valx[++topx]=a[i].x; valy[++topy]=a[i].y;
    }
    sort(valx+1,valx+topx+1); sort(valy+1,valy+topy+1);
    topx=unique(valx+1,valx+topx+1)-valx-1;
    topy=unique(valy+1,valy+topy+1)-valy-1;
    for(int i=1;i<=n;i++){
        a[i].x=lower_bound(valx+1,valx+topx+1,a[i].x)-valx;
        a[i].y=lower_bound(valy+1,valy+topy+1,a[i].y)-valy;      
        bl[a[i].x][a[i].y]=1; 
    }
    DSU::init();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) if(insameline(i,j)) DSU::unite(i,j);
    }
    for(int i=1;i<=n;i++) seq[DSU::getfather(i)].push_back(i);
    cnt=0; vector<int> qq;
    for(int i=1;i<=n;i++) if(!seq[i].empty()) cnt++,qq.push_back(i);
    if(cnt>2){puts("-1"); return 0;}
    
    int now=0; ans=inf;
    for(auto &u : qq) Kruskal(seq[u],now),now++;
    for(int i=1;i<=topx;i++){
        for(int j=1;j<=topy;j++) if(!bl[i][j]){
            int tmp=0;
            for(int k=0;k<now;k++) checkmax(tmp,vis[k][i][j]);
            checkmin(ans,tmp);
        }
    }
    if(cnt==1) checkmin(ans,solver0::main());
    if(ans>=inf) puts("-1");
    else printf("%d\n",ans);
    return 0;
}