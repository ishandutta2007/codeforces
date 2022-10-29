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
const ll INF=(ll)2e18;
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
const int N=500005;
int n,a[N],b[N];

struct Segment_Tree{
    int mx[N<<2];
    void pushup(int x){
        mx[x]=(b[mx[x<<1]]>b[mx[x<<1|1]] ? mx[x<<1] : mx[x<<1|1]);
    }
    void build(int x,int l,int r){
        if(l==r){mx[x]=l; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void del(int x,int l,int r,int pos){
        if(l==r){mx[x]=0; return;}
        int mid=(l+r)>>1;
        if(mid>=pos) del(x<<1,l,mid,pos);
        else del(x<<1|1,mid+1,r,pos);
        pushup(x);
    }
    int find(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return mx[x];
        int mid=(l+r)>>1;
        int ret=0;
        if(mid<R) ret=find(x<<1|1,mid+1,r,L,R);
        if(mid>=L){
            int ret1=find(x<<1,l,mid,L,R);
            if(b[ret1]>b[ret]) ret=ret1;
        }
        return ret;
    }
}T;
int tt[N],vis[N],cnt=0,ans[N];
void dfs(int u){
    int tmp=b[u];
    T.del(1,1,n,u); vis[u]=1; b[u]=-inf;
    if(tmp!=n+1&&!vis[tmp]) dfs(tmp);
    if(a[u]>1) while(true){
        int x=T.find(1,1,n,1,a[u]-1);
        if(b[x]<=u) break;
        dfs(x);
    }
    tt[++cnt]=u;
}

int main()
{
    n=read(); b[0]=-inf;
    for(int i=1;i<=n;i++) b[i]=n+1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]!=-1) b[a[i]]=i;
        else a[i]=n+1;
    }
    T.build(1,1,n);
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    for(int i=1;i<=n;i++) ans[tt[i]]=i;
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}