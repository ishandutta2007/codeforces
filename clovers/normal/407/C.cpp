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
const int N=100205;
const int M=105;
int dp[M][N],n,m,a[N];
int C[N][M];

int main()
{
    for(int i=0;i<N;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<min(M,i);j++){
            C[i][j]=add(C[i-1][j-1],C[i-1][j]);
        }
    }
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++){
        int l=read(),r=read(),k=read();
        Add(dp[k][l],1); 
        for(int j=k;j>=0;j--) Sub(dp[j][r+1],C[r-l+k-j][k-j]);
    }
    for(int i=100;i>=1;i--){
        for(int j=1;j<=n;j++) 
            Add(dp[i][j],dp[i][j-1]),Add(dp[i-1][j],dp[i][j]);
    }
    for(int i=1;i<=n;i++) Add(dp[0][i],dp[0][i-1]),Add(a[i],dp[0][i]);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}