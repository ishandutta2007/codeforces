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
const int N=205;
int n,a[N],b[N];
int suma=0,sumb=0,dp[105][20005];

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read()*2,b[i]=read()*2;
    memset(dp,-1,sizeof(dp)); dp[0][0]=0;
    for(int x=1;x<=n;x++){
        for(int i=x-1;i>=0;i--){
            for(int j=0;j<=suma;j++) if(dp[i][j]!=-1){
                checkmax(dp[i+1][j+a[x]],dp[i][j]+b[x]);
                checkmax(dp[i+1][j],dp[i][j]);
            }
        }
        suma+=a[x]; sumb+=b[x];
    }
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=0;j<=suma;j++) if(dp[i][j]!=-1){
            int rest=(sumb-dp[i][j])/2;
            checkmax(mx,min(j,dp[i][j]+rest));
        }
        printf("%.2lf\n",mx/2.0);
    }
    return 0;
}