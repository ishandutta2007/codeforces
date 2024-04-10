#include<cstdio> 
#include<cstring> 
#include<cctype>
#include<algorithm>
using namespace std;

/*
   void Exgcd(ll a,ll b,ll &x,ll &y){
   if(b==0){ 
   x=1,y=0;
   return;
   }
   Exgcd(b,a%b,y,x);y-=a/b*x;
   }
 */

#define reg register
typedef long long ll;
typedef unsigned ui;
#define rep(i,a,b) for(reg int i=a;i<=b;++i)
#define drep(i,a,b) for(reg int i=a;i>=b;--i)

char IO;
int rd(){
	int s=0;
	while(!isdigit(IO=getchar()));
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return s;
}


const ll P=19260817,K=5567891;
const ll P1=1e9+13,K1=6550879;
const int N=8010;

int n;
char s[N];
int Log[N];
int h[N][N],h1[N][N];
int dp[N];
int vis[N];


int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n) Log[i]=Log[i/10]+1;
	rep(i,1,n) rep(j,i,n) {
		h[i][j]=(1ll*h[i][j-1]*K+s[j])%P;
		h1[i][j]=(1ll*h1[i][j-1]*K1+s[j])%P1;
	}
	memset(dp,10,sizeof dp); dp[0]=0;
	rep(i,0,n-1) {
		rep(j,i+1,n) vis[j]=0;
		rep(j,i+1,n) {
			reg int len=j-i;
			reg int l=i-len+1,r=i,c=0;
			while(r+len<=n){
				l+=len,r+=len;
				if(h[l][r]!=h[i+1][j]||h1[l][r]!=h1[i+1][j]||vis[r]) break;
				vis[r]=1;
				dp[r]=min(dp[r],dp[i]+Log[++c]+len);
			}
		}
	}
	printf("%d\n",dp[n]);
}