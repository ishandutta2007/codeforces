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
int n,a[N],k,sum[N],ans[N*100];
int lst[N],dp[N][N];
int calc(int val){
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++) dp[i][j]=0;
    for(int i=1,j=1;i<=n;i++){
        while(i>=j&&a[i]-a[j]>=val) j++;
        lst[i]=j-1;
    }
    for(int i=1;i<=n;i++) sum[i]=0;
    for(int i=1;i<=n;i++){
        dp[1][i]=1; sum[i]=i;
    }
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=sum[lst[j]];
        }
        for(int j=1;j<=n;j++) sum[j]=add(sum[j-1],dp[i][j]);
    }
    int ret=0;
    for(int i=1;i<=n;i++) Add(ret,dp[k][i]);
    return ret;
}

int main()
{
    n=read(); k=read();
    int mx=0;
    for(int i=1;i<=n;i++) a[i]=read(),checkmax(mx,a[i]);
    sort(a+1,a+n+1);
    int pos=1;
    for(int i=1;i*(k-1)<=mx;i++) ans[i]=calc(i),pos=i;
    int ret=0;
    for(int i=pos;i>=1;i--){
        Add(ret,mul(i,sub(ans[i],ans[i+1])));
    }
    cout<<ret<<endl;
    return 0;
}