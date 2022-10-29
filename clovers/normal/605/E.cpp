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
const int N=1005;
int n,bl[N];
double vis[N],a[N][N],dp[N],sum[N];
void extend(int x){
    for(int i=1;i<=n;i++) if(!vis[i]&&a[i][x]!=0){
        if(!bl[i]){
            bl[i]=1; sum[i]=1-a[i][x];
            dp[i]=dp[x]+1.0/a[i][x];
        }
        else if(sum[i]!=0){
            double delta=dp[i]-dp[x];
            dp[i]-=delta/(1-sum[i]*(1.0-a[i][x]))*sum[i]*a[i][x];
            sum[i]*=(1-a[i][x]);
        }
    }
}

int main()
{
    n=read(); 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) a[i][j]=1.0*read()/100;
    }
    for(int i=1;i<=n;i++) sum[i]=1;
    for(int i=1;i<=n;i++) dp[i]=1e9; dp[n]=0;
    int pos=n;
    while("MYYAKAK"){
        vis[pos]=1; 
        if(pos==1) break;
        extend(pos);
        double mi=1e9;
        for(int i=1;i<=n;i++) if(!vis[i]&&dp[i]<mi) mi=dp[i],pos=i;
    }
    printf("%.8lf\n",dp[1]);
    return 0;
}