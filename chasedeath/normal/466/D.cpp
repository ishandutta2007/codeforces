#include<bits/stdc++.h>
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


const int N=2e3+10,P=1e9+7;

int n,h;
int a[N];
ll dp[N][N];


int main(){
	n=rd(),h=rd();
	dp[0][0]=1;
	rep(i,1,n) {
		a[i]=rd();
		if(a[i]>h) return puts("0"),0;
		rep(j,0,n) {
			if(j) dp[i][j]=dp[i-1][j-1]%P;
			(dp[i][j]+=(1+j)*dp[i-1][j]%P)%=P;
			(dp[i][j]+=dp[i-1][j+1]*(j+1))%=P;
		}
		rep(j,0,n) if(j!=h-a[i]) dp[i][j]=0;
	}
	//rep(i,0,n) rep(j,0,n) cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	ll t=(dp[n][0]+dp[n][1])%P;
	printf("%lld\n",t);
}