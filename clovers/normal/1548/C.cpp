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
const int N=3000005;
int fac[N],ifac[N],inv[N];
int dp[N][4],n,q;

int main()
{
    int n=3000001;
    fac[0]=1; for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    ifac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]=mul(MOD-MOD/i,inv[MOD%i]);
    n=read(); q=read();
    dp[1][1]=mul(inv[2],mul(3*n-1,n));
    dp[1][2]=mul(inv[2],mul(3*n+1,n));
    dp[1][3]=mul(inv[2],mul(3*n+3,n));
    for(int i=2;i<=n*3;i++){
        int tmp=mul(fac[3*n+1],mul(ifac[3*n-i],inv[i+1]));
        int tmp1=mul(i,dp[i-1][1]),tmp2=mul(i,dp[i-1][2]);
        dp[i][1]=mul(sub(tmp,add(tmp1,add(tmp1,tmp2))),inv[3]);
        dp[i][2]=add(dp[i][1],tmp1);
        dp[i][3]=add(dp[i][2],tmp2);
    }
    for(int i=1;i<=n*3;i++) Mul(dp[i][3],ifac[i]);
    while(q--){
        printf("%d\n",dp[read()][3]);
    }
    return 0;
}