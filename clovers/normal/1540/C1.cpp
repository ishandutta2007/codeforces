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
const int N=105;
int n,a[N],b[N],dp[N][N*N],sum1[N],sum2[N];

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++) b[i]=read();
    int q=read(),x=read();
    for(int i=1;i<n;i++) sum1[i]=sum1[i-1]+b[i];
    for(int i=1;i<n;i++) sum2[i]=sum2[i-1]+sum1[i];
    int tot=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        tot+=a[i];
        int lim=x*i+sum2[i-1];
        for(int k=0;k<=a[i];k++)
            for(int j=tot;j>=k;j--) Add(dp[i][j],dp[i-1][j-k]);
        for(int j=0;j<min(lim,tot+1);j++) dp[i][j]=0;
    }
    int ans=0;
    for(int i=0;i<=tot;i++) Add(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}