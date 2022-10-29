#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
const int N=402;
int n,K,dp[N][N][N],f[N];
int C[N];

int main()
{
    scanf("%d%d",&n,&K);
    int m=min(n,2*K);
    dp[0][0][0]=1;
    C[0]=1;
    for(int i=0;i<=m;i++){
        if(i) C[i]=mul(C[i-1],mul(qpow(i,MOD-2),n-i+1));
        for(int j=0;j<=i;j++){
            Add(f[i-j],mul(C[i],dp[i][j][0]));
            for(int k=0;k<=i;k++) if(dp[i][j][k]){
                Add(dp[i+1][j][k],mul(2*k,dp[i][j][k]));
                if(k) Add(dp[i+1][j+1][k-1],mul(k,dp[i][j][k]));
                if(k>=2) Add(dp[i+1][j][k-1],mul(k*(k-1),dp[i][j][k]));
                Add(dp[i+1][j][k+1],dp[i][j][k]);
            }
        }
    }
    for(int i=max(m,K);i>=0;i--){
        for(int j=i+2;j<=max(m,K);j+=2) Add(f[j],f[i]);
    }
    for(int i=1;i<=max(m,K);i++){
        printf("%d ",f[i]);
        if(i>=K) break;
    }
    return 0;
}