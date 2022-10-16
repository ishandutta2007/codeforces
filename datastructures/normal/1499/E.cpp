#include <iostream>
#include <cstdio>
#include <cstring> 
#define mod 998244353
using namespace std;
int n,m,f[1005][1005][2],del[1005][2],ans;
char s[1005],t[1005];
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for (int i=m;i>=1;i--)
		f[n+1][i][1]=1+(t[i]!=t[i+1])*f[n+1][i+1][1];
	for (int i=n;i>=1;i--)
		f[i][m+1][0]=1+(s[i]!=s[i+1])*f[i+1][m+1][0];
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--){
			f[i][j][0]=(1+(s[i]!=s[i+1])*f[i+1][j][0]+(s[i]!=t[j])*f[i+1][j][1])%mod;
			f[i][j][1]=(1+(t[j]!=s[i])*f[i][j+1][0]+(t[j]!=t[j+1])*f[i][j+1][1])%mod;
			ans=(0ll+ans+f[i][j][0]+f[i][j][1])%mod;
		}
	for (int i=n;i>=1;i--)del[i][0]=1+(s[i]!=s[i+1])*del[i+1][0],ans=(ans-m*del[i][0]+mod)%mod;
	for (int i=m;i>=1;i--)del[i][1]=1+(t[i]!=t[i+1])*del[i+1][1],ans=(ans-n*del[i][1]+mod)%mod;
	cout<<ans<<endl;
	return 0;
}