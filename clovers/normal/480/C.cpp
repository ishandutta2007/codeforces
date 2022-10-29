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
const int N=5005;
int n,A,B,dp[N][N],k,sum[N];
int L[N],R[N];

int main()
{
    n=read(); A=read(); B=read(); k=read();
    dp[0][A]=1;
    for(int i=1;i<=n;i++) L[i]=inf,R[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(_abs(i-j)<_abs(i-B)) 
                checkmin(L[j],i),checkmax(R[j],i);
        }
    } 
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) sum[j]=add(sum[j-1],dp[i-1][j]);
        for(int j=1;j<=n;j++){
            if(L[j]<=R[j]) dp[i][j]=sub(sum[R[j]],add(dp[i-1][j],sum[L[j]-1]));
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) Add(ans,dp[k][i]);
    cout<<ans<<endl;
    return 0;
}