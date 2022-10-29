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
const int N=1000005;
int a[N],n,b[N],top=0; ll dp[N][2];

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    b[++top]=0;
    for(int i=2;i<n;i++){
        if((a[i]>=a[i-1]&&a[i]>=a[i+1])||(a[i]<=a[i+1]&&a[i]<=a[i-1]))
            b[++top]=i;
    }
    b[++top]=n+1;
    memset(dp,0xc0,sizeof(dp));
    dp[1][0]=0; 
    for(int i=2;i<=top;i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++) if(dp[i-1][k]>=0){
                int ret;
                if(b[i]-b[i-1]==1&&k==0&&j==1) ret=0;
                else ret=_abs(a[b[i-1]+1-k]-a[b[i]-j]);
                checkmax(dp[i][j],dp[i-1][k]+ret);
            }
        }
    }
    cout<<dp[top][1]<<endl;
    return 0;
}