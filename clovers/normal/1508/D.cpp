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
const int N=2005;
struct node{
    int x,y;
}p[N];
int a[N],n,m,top=0,bel[N],id[N],pos;
namespace DSU{
    int fa[N];
    void init(){for(int i=1;i<=top;i++) fa[i]=i;}
    int getfather(int x){return fa[x]==x ? x : fa[x]=getfather(fa[x]);} 
    void unite(int x,int y){fa[getfather(x)]=getfather(y);}
    bool same(int x,int y){return getfather(x)==getfather(y);}
}
vector<pii> ans;
void Swap(int x,int y){
    swap(a[x],a[y]);
    ans.push_back(mk(x,y));
}
bool cmp(int x,int y){
    return atan2(p[x].y-p[pos].y,p[x].x-p[pos].x)<
            atan2(p[y].y-p[pos].y,p[y].x-p[pos].x);
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) p[i].x=read(),p[i].y=read(),a[i]=read();
    for(int i=1;i<=n;i++) if(!bel[i]){
        int x=a[i]; bel[i]=++top;
        while(!bel[x]) bel[x]=top,x=a[x];
    }
    pos=-1;
    for(int i=1;i<=n;i++) if(a[i]!=i&&(pos==-1||p[i].x<p[pos].x)){
        pos=i;
    }
    if(pos==-1){puts("0"); return 0;}
    int cnt=0;
    for(int i=1;i<=n;i++) if(i!=pos) id[++cnt]=i;
    sort(id+1,id+n,cmp); DSU::init();
    int pre=-1;
    for(int i=1;i<n;i++) if(a[id[i]]!=id[i]){
        if(pre!=-1){
            if(!DSU::same(bel[id[i]],bel[id[pre]])){
                Swap(id[i],id[pre]);
                DSU::unite(bel[id[i]],bel[id[pre]]);
            }
        }
        pre=i;
    }
    while(a[pos]!=pos){Swap(pos,a[pos]);}
    for(int i=1;i<=n;i++) assert(a[i]==i);
    printf("%d\n",sz(ans));
    for(auto &u : ans) printf("%d %d\n",u.first,u.second);
    return 0;
}