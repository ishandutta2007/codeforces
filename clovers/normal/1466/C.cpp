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
const ll INdp=(ll)5e18;
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
const int N=100005;
char s[N];
int n,dp[N][2][2];
int main()
{
    int T=read();
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        if(n==1){
            puts("0");
            continue;
        }
        for(int i=1;i<=n;i++) dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=inf;
        if(s[2]!=s[1]) dp[2][0][0]=0;
        dp[2][1][0]=1; dp[2][0][1]=1;
        dp[2][1][1]=2;
        for(int i=3;i<=n;i++){
            if(s[i]==s[i-2])
			{
				dp[i][1][0]=dp[i-1][1][1];
				dp[i][1][1]=min(dp[i-1][1][1],dp[i-1][0][1])+1;
				dp[i][0][1]=min(dp[i-1][1][0],dp[i-1][0][0])+1;
				if(s[i]!=s[i-1]) dp[i][0][0]=dp[i-1][1][0];
			}
			else
			{
				dp[i][0][1]=min(dp[i-1][0][0],dp[i-1][1][0])+1;
				dp[i][1][0]=min(dp[i-1][1][1],dp[i-1][0][1]);
				dp[i][1][1]=min(dp[i-1][1][1],dp[i-1][0][1])+1;
				if(s[i]!=s[i-1]) dp[i][0][0]=min(dp[i-1][0][0],dp[i-1][1][0]);
			}
        }
        printf("%d\n",min(min(dp[n][0][1],dp[n][1][0]),min(dp[n][0][0],dp[n][1][1])));
    }
    return 0;
}