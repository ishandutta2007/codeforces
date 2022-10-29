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
const int N=505;
const int M=22;
int dp[M][N][N],n,k,m;
int heng[N][N],shu[N][N];

int main()
{
    n=read(); m=read(); k=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++) heng[i][j]=read();
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++) shu[i][j]=read();
    }
    if(k&1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("-1 ");
            }  puts("");
        }
        return 0;
    }
    memset(dp,0x3f,sizeof(dp));
    memset(dp[0],0,sizeof(dp[0]));
    for(int rnd=0;rnd<k/2;rnd++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i!=n) checkmin(dp[rnd+1][i+1][j],dp[rnd][i][j]+shu[i][j]);
                if(i!=1) checkmin(dp[rnd+1][i-1][j],dp[rnd][i][j]+shu[i-1][j]);
                if(j!=m) checkmin(dp[rnd+1][i][j+1],dp[rnd][i][j]+heng[i][j]);
                if(j!=1) checkmin(dp[rnd+1][i][j-1],dp[rnd][i][j]+heng[i][j-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%d ",dp[k/2][i][j]*2);
        puts("");
    }
    return 0;
}