#include<cstdio> 
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }


const int N=2e3+10,P=1e9+7;

int n,m;
char s[N][N];
int cnt[N][N];
ll dp[N][N][2];

int Sum(int x1,int y1,int x2,int y2){
	return cnt[x2][y2]-cnt[x1-1][y2]-cnt[x2][y1-1]+cnt[x1-1][y1-1];
}

int main(){
	n=rd(),m=rd();
	if(n==1&&m==1) return puts("1"),0;
	rep(i,1,n) {
		scanf("%s",s[i]+1);
		rep(j,1,m) if(s[i][j]=='R') cnt[i][j]++;
	}
	rep(i,1,n) rep(j,1,m) cnt[i][j]+=cnt[i][j-1];
	rep(i,1,n) rep(j,1,m) cnt[i][j]+=cnt[i-1][j];
	dp[1][1][0]=dp[1][1][1]=1;
	dp[2][1][0]=-1;dp[1][2][1]=-1;
	rep(i,1,n) rep(j,1,m) {
		(dp[i][j][0]+=dp[i-1][j][0])%=P;
		(dp[i][j][1]+=dp[i][j-1][1])%=P;
		if(i<n) {
			//dp[i][j][1];
			int t=Sum(i+1,j,n,j);
			t=n-i-t;
			//cout<<"#0  "<<i<<' '<<j<<' '<<t<<endl;
			(dp[i+1][j][0]+=dp[i][j][1])%=P;
			(dp[i+t+1][j][0]-=dp[i][j][1])%=P;
		}
		if(j<m) {
			//dp[i][j][0];
			int t=Sum(i,j+1,i,m);
			t=m-j-t;
			//cout<<"#1   "<<i<<' '<<j<<' '<<t<<endl;
			(dp[i][j+1][1]+=dp[i][j][0])%=P;
			(dp[i][j+t+1][1]-=dp[i][j][0])%=P;
		}
	}
	//rep(i,1,n) rep(j,1,m) cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
	ll ans=(dp[n][m][0]+dp[n][m][1])%P;
	ans=(ans%P+P)%P;
	printf("%lld\n",ans);
}