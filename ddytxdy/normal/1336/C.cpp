#include<bits/stdc++.h>
using namespace std;
const int N=3030,mod=998244353;
int n,m,f[N][N],g[N][N],pw[N],ans;char s[N],t[N];
int main(){
	scanf("%s%s",s+1,t+1);pw[0]=1;
	n=strlen(s+1);m=strlen(t+1);
	for(int i=1;i<=n;i++)pw[i]=2*pw[i-1]%mod;
	for(int i=0;i<=m;i++)g[i+1][i]=1;
	for(int i=m;i;i--)
		for(int j=i;j<=m;j++){
			g[i][j]=0;
			if(t[i]==s[j-i+1])(g[i][j]+=g[i+1][j])%=mod;
			if(t[j]==s[j-i+1])(g[i][j]+=g[i][j-1])%=mod;
		}
	for(int i=1;i<=n;i++)
		for(int j=m;j;j--){
			f[i][j]=f[i-1][j];
			if(s[i]==t[j]){
				if(j==m)(f[i][j]+=pw[max(1,i-1)])%=mod;
				else (f[i][j]+=f[i-1][j+1])%=mod;
			}
			if(i<=m&&j==m-i+1)f[i][j]=g[m-i+1][m];
		}
	for(int i=m;i<=n;i++)(ans+=f[i][1])%=mod;
	cout<<ans;
	return 0;
}