#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

int IO;
int rd(){
	int s=0;
	while((IO=getchar())<48);
	do s=(s<<1)+(s<<3)+(IO^'0');
	while((IO=getchar())>47);
	return s;
}

const int N=110;
const ll P=1e9+7;

int n;
char s[N];
ll dp[N][26*N];


int main(){
	dp[0][0]=1;
	rep(i,1,101) {
		rep(j,1,2600) (dp[i-1][j]+=dp[i-1][j-1])%=P;
		rep(j,1,2600) {
			if(j>=27) dp[i][j]=(dp[i-1][j-1]-dp[i-1][j-27]+P)%P;
			else dp[i][j]=dp[i-1][j-1];
		}
	}
	rep(kase,1,rd()) {
		scanf("%s",s+1); n=strlen(s+1);
		int m=0;
		rep(i,1,n) m+=s[i]-'a'+1;
		//cout<<n<<' '<<m<<endl;
		//cout<<dp[n][m]<<' '<<dp[n][m-1]<<endl;
		ll ans=(P+P-1+dp[n][m]-dp[n][m-1])%P;
		printf("%lld\n",ans);
	}
}