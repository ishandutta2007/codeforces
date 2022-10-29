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
const int N=1005;
int n,k,ans=0,a[N][N];
void add_edge(int sl,int sr,int tol,int tor,int col){
    for(int i=sl;i<=sr;i++){
        for(int j=tol;j<=tor;j++) a[i][j]=col;
    }
}
void run(int l,int r,int dep){
    if(l==r) return;
    checkmax(ans,dep);
    int sz=r-l+1;
    int blk=(sz+k-1)/k;
    for(int i=l;i<=r;i+=blk){
        for(int j=i+blk;j<=r;j+=blk){
            add_edge(i,i+blk-1,j,min(r,j+blk-1),dep);
        }
    }
    for(int i=l;i<=r;i+=blk) run(i,min(i+blk-1,r),dep+1);
}
int main()
{
    n=read(); k=read();
    run(1,n,1);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) printf("%d ",a[i][j]);
    }
    return 0;
}