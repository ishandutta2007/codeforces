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
const int MOD=1e9+9;
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
const int N=300005;
int f[N],n,m,a[N];
struct Segment_Tree{
    int a1[N<<2],a2[N<<2],sum[N<<2];
    void pushup(int x){sum[x]=add(sum[x<<1],sum[x<<1|1]);}
    void addsum(int x,int l,int r,int val1,int val2){
        int sz=r-l+1;
        Add(a1[x],val1); Add(a2[x],val2);
        Add(sum[x],add(mul(f[sz],val1),mul(sub(f[sz+1],1),val2)));
    }
    void pushdown(int x,int l,int mid,int r){
        if(!a1[x]&&!a2[x]) return;
        addsum(x<<1,l,mid,a1[x],a2[x]);
        int ad1=add(mul(f[mid-l],a1[x]),mul(f[mid-l+1],a2[x]));
        int ad2=add(mul(f[mid-l+1],a1[x]),mul(f[mid-l+2],a2[x]));
        addsum(x<<1|1,mid+1,r,ad1,ad2);
        a1[x]=0; a2[x]=0;
    }
    void update(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            addsum(x,l,r,f[l-L+1],f[l-L+2]); 
            return;
        }
        int mid=(l+r)>>1; pushdown(x,l,mid,r);
        if(mid>=L) update(x<<1,l,mid,L,R);
        if(mid<R) update(x<<1|1,mid+1,r,L,R);
        pushup(x);
    }
    int query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[x];
        int mid=(l+r)>>1,ret=0; pushdown(x,l,mid,r);
        if(mid>=L) Add(ret,query(x<<1,l,mid,L,R));
        if(mid<R) Add(ret,query(x<<1|1,mid+1,r,L,R));
        return ret;
    }
    void build(int x,int l,int r){
        if(l==r){sum[x]=a[l]; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
}tree;

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    tree.build(1,1,n);
    f[1]=1; f[2]=1;
    for(int i=3;i<=n+1;i++) f[i]=add(f[i-1],f[i-2]);
    while(m--){
        int opt=read(),l=read(),r=read();
        if(opt==1) tree.update(1,1,n,l,r);
        else printf("%d\n",tree.query(1,1,n,l,r));
    }
    return 0;
}