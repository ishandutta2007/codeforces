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
const int N=2005;
double dp[N][N];
int n,m,visx[N],visy[N];

int main()
{
    n=read(); m=read();
    int numx=0,numy=0;
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        if(!visx[x]) numx++,visx[x]=1;
        if(!visy[y]) numy++,visy[y]=1;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]+1.0*n/i;
    for(int i=1;i<=n;i++) dp[0][i]=dp[0][i-1]+1.0*n/i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            double p1=1.0*i*j/(n*n),p4=1.0*(n-i)*(n-j)/(n*n);
            double p2=1.0*i*(n-j)/(n*n),p3=1.0*(n-i)*j/(n*n);
            dp[i][j]=(dp[i-1][j-1]*p1+dp[i-1][j]*p2+dp[i][j-1]*p3+1)/(1-p4);
        }
    }
    printf("%.8lf\n",dp[n-numx][n-numy]);
    return 0;
}