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
const int N=81;
const int M=6505;
int n,a[N],dp[N][N][M],b[N],cnt1=0,cnt0=0,m=0,s[N];
int _abs(int x){return x<0 ? -x : x;}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    int now=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1) b[++cnt1]=now,now=0;
        else cnt0++,now++;
    }
    b[cnt1+1]=now; int m=cnt1+1;
    for(int i=1;i<=m;i++) s[i]=s[i-1]+b[i];
    int ans=cnt0*(cnt0-1)/2;
    for(int i=1;i<=m;i++) ans-=b[i]*(b[i]-1)/2;
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=m;i++){
        dp[i][s[i]][0]=0;
        if(i) dp[i][s[i]][0]=dp[i-1][s[i-1]][0]+(s[i]-s[i-1])*(s[i]-s[i-1]);
        //cout<<dp[0][s[i]][0]<<endl;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<=s[m];j++){
            for(int k=0;k<=n*(n-1)/2;k++){
                if(dp[i][j][k]>10000000) continue;
                //out(i); out(j); out(k); outln(dp[i][j][k]);
                for(int l=j;l<=s[m];l++){
                    int dis=_abs(l-s[i+1]);
                    if(dis+k>n*(n-1)/2) continue;
                    checkmin(dp[i+1][l][dis+k],dp[i][j][k]+(l-j)*(l-j));
                    //if(i==2&&j==4&&k==1&&l==j) cout<<dis<<endl;
                }
            }
        }
    }
    ans=inf;
    for(int i=0;i<=n*(n-1)/2;i++){
        checkmin(ans,dp[m][s[m]][i]);
        printf("%d ",(s[m]*s[m]-ans)/2);
    }
    return 0;
}