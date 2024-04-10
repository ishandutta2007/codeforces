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
int n,a[N],l[N],nxt[N][20],f[N][20];
struct ST{
    int st[N][20],lg[N];
    int query(int l,int r){
        int sz=r-l+1;
        return max(st[l][lg[sz]],st[r-(1<<lg[sz])+1][lg[sz]]);
    }
    void init(){
        for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
        for(int i=1;i<=n;i++) st[i][0]=a[i]+l[i];
        for(int j=1;j<20;j++){
            for(int i=1;i<=n;i++){
                if(i+(1<<j)-1>n) break;
                int to=i+(1<<(j-1));
                st[i][j]=max(st[i][j-1],st[to][j-1]);
            }
        }
    }
}T;

struct Segment_Tree{
    int mx[N<<2];
    void pushup(int x){mx[x]=max(mx[x<<1],mx[x<<1|1]);}
    void update(int x,int l,int r,int pos,int val){
        if(l==r){mx[x]=val; return;}
        int mid=(l+r)>>1;
        if(mid>=pos) update(x<<1,l,mid,pos,val);
        else update(x<<1|1,mid+1,r,pos,val); 
        pushup(x);
    }
    int query(int x,int l,int r,int L,int R){
        if(L>R) return 0;
        if(L<=l&&r<=R) return mx[x];
        int mid=(l+r)>>1,ret=0;
        if(mid>=L) checkmax(ret,query(x<<1,l,mid,L,R));
        if(mid<R) checkmax(ret,query(x<<1|1,mid+1,r,L,R));
        return ret;
    }
}tree;

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),l[i]=read();
    T.init();
    for(int i=0;i<20;i++) nxt[n+1][i]=n+1; nxt[n][0]=n+1;
    tree.update(1,1,n,n,n+1);
    for(int i=n-1;i>=1;i--){
        int pos=upper_bound(a+1,a+n+1,a[i]+l[i])-a;
        nxt[i][0]=pos;
        if(pos<=n) checkmax(nxt[i][0],tree.query(1,1,n,i+1,pos-1));
        if(nxt[i][0]<=n){
            int to=nxt[i][0];
            f[i][0]=a[to]-T.query(i,to-1);
        }
        tree.update(1,1,n,i,nxt[i][0]);
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            int x=nxt[i][j-1];
            int y=nxt[x][j-1];
            nxt[i][j]=y; f[i][j]=f[i][j-1]+f[x][j-1];
        }
    }
    int q=read();
    while(q--){
        int L=read(),R=read(),ret=0;
        int x=L;
        for(int i=19;i>=0;i--) if(nxt[x][i]<=R){
            int to=nxt[x][i];
            ret+=f[x][i]; x=to;
        }
        printf("%d\n",ret);
    }
    return 0;
}