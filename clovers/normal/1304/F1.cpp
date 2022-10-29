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
const int N=55;
const int M=20005;
#define int long long
int n,m,k,a[N][M],sum[N][M],S[N][M];

int A[M];
struct Segment_Tree{
    int mx[M<<2],tag[M<<2];
    void pushup(int x){mx[x]=max(mx[x<<1],mx[x<<1|1]);}
    void pushdown(int x){
        if(!tag[x]) return;
        mx[x<<1]+=tag[x]; mx[x<<1|1]+=tag[x];
        tag[x<<1]+=tag[x]; tag[x<<1|1]+=tag[x];
        tag[x]=0;
    }
    void build(int x,int l,int r){
        tag[x]=0;
        if(l==r){mx[x]=A[l]; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void update(int x,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            mx[x]+=val; tag[x]+=val; 
            return;
        }
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=L) update(x<<1,l,mid,L,R,val);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
        pushup(x);
    }
}tree;

int query(int sx,int sy,int ex,int ey){
    return sum[ex][ey]-sum[sx-1][ey]-sum[ex][sy-1]+sum[sx-1][sy-1];
}
void init(){
    n=read(); m=read(); k=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) a[i][j]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j+k-1<=m;j++){
            if(i==n) S[i][j]=query(i,j,i,j+k-1);
            else S[i][j]=query(i,j,i+1,j+k-1);
        }
    }
}

int dp[N][M];
void solve(){
    for(int i=1;i<=m;i++) dp[1][i]=S[1][i];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            A[j]=dp[i-1][j]-(j>k ? 0 : query(i,j,i,k));
        }
        tree.build(1,1,m);
        dp[i][1]=tree.mx[1]+S[i][1];
        for(int j=2;j+k-1<=m;j++){
            tree.update(1,1,m,j,j+k-1,-a[i][j+k-1]);
            tree.update(1,1,m,max(1ll,j-k),j-1,a[i][j-1]);
            dp[i][j]=tree.mx[1]+S[i][j];
        }
    }    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         out(i); out(j); outln(dp[i][j]);
    //     }
    // }    
    int ans=0;
    for(int i=1;i<=m;i++) checkmax(ans,dp[n][i]);
    cout<<ans<<endl;
}

signed main()
{
    init(); solve();
    return 0;
}