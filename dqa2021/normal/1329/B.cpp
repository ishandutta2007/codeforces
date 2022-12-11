#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

void solve()
{
	//init
	int d=read(),Mod=read();
	static int dp[50]; int btw=0;
	while (btw+1<31&&(1<<btw+1)<=d) btw++;
	for (int i=0;i<=btw;i++) dp[i]=(i==btw?(d^(1<<i))+1:(1<<i)),dp[i]%=Mod;
	int ans=0;
	for (int i=0;i<=btw;i++){
		for (int j=i+1;j<=btw;j++) dp[j]=(dp[j]+1LL*dp[i]*(j==btw?(d^(1<<j))+1:(1<<j)))%Mod;
//		printf("dp %d: %d\n",i,dp[i]);
		ans=(ans+dp[i])%Mod;
	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}