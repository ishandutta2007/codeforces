#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
using namespace std;
int n,f[2005][2005],g[2005][2005],ans;
char s[2005];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i;j++){
			if (s[i]=='('){
				if (j>0)f[i][j]=f[i-1][j-1];
				else f[i][j]=0;
			}
			if (s[i]==')')f[i][j]=f[i-1][j];
			if (s[i]=='?')f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
		}
	g[n+1][0]=1;
	for (int i=n;i>=1;i--)
		for (int j=0;j<=i;j++){
			if (s[i]=='(')g[i][j]=g[i+1][j];
			if (s[i]==')'){
				if (j>0)g[i][j]=g[i+1][j-1];
				else g[i][j]=0;
			}
			if (s[i]=='?')g[i][j]=(g[i+1][j-1]+g[i+1][j])%mod;
		}
	for (int i=1;i<n;i++)
		for (int j=1;j<=n;j++)
			ans=(ans+1ll*j*f[i][j]%mod*g[i+1][j]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}