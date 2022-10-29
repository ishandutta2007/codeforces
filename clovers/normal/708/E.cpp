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
const int MOD=1e9+7;
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
const int N=1505;
const int M=100005;
int n,m,p,q,t;
int dp[N],g[N][N];
int fac[M],ifac[M],f[M],s[N],sum[N];
int C(int n,int m){return mul(fac[n],mul(ifac[m],ifac[n-m]));}
void print(int val){
    for(int i=1;i<=30;i++){
        for(int j=1;j<=400;j++){
            if(mul(i,qpow(j,MOD-2))==val) {printf("%d/%d\n",i,j); return;}
        }
    }
}

int main()
{
    n=read(); m=read();
    int x=read(),y=read(); 
    p=mul(x,qpow(y,MOD-2)); q=(1+MOD-p)%MOD;
    t=read();
    fac[0]=1; for(int i=1;i<M;i++) fac[i]=mul(fac[i-1],i);
    ifac[M-1]=qpow(fac[M-1],MOD-2); 
    for(int i=M-2;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    for(int i=0;i<=t;i++) f[i]=mul(C(t,i),mul(qpow(p,i),qpow(q,t-i)));
    s[0]=f[0]; for(int i=1;i<=m;i++) s[i]=add(s[i-1],f[i]);
    dp[0]=1; g[0][m]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) sum[j]=add(sum[j-1],mul(f[j],g[i-1][j]));
        for(int j=1;j<=m;j++){
            int r=m-j;
            int tmp=mul(dp[i-1],mul(s[j-1],f[r]));
            Sub(tmp,mul(f[r],sum[j-1]));
            Sub(tmp,mul(f[r],mul(g[i-1][r],s[j-1])));
            g[i][j]=add(g[i][j-1],tmp);
        }
        dp[i]=g[i][m];
    }
    cout<<dp[n]<<endl;
    return 0;
}