#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
char a[1003],b[1003];
int f[1003][1003][2],ans;
int n,m,da[1003],db[1003];
int main(){
	scanf("%s%s",a+1,b+1);
	a[0]='*',b[0]='*';
	n=strlen(a+1),m=strlen(b+1);
	for(int i=1;i<=n;i++)da[i]=(a[i]!=a[i-1]?da[i-1]:0)+1;
	for(int i=1;i<=m;i++)db[i]=(b[i]!=b[i-1]?db[i-1]:0)+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		f[i][j][0]=(((a[i]!=b[j]?db[j]:0)+(a[i-1]!=a[i]?f[i-1][j][0]:0))%MOD+(b[j]!=a[i]?f[i-1][j][1]:0))%MOD;
		f[i][j][1]=(((b[j]!=a[i]?da[i]:0)+(b[j-1]!=b[j]?f[i][j-1][1]:0))%MOD+(b[j]!=a[i]?f[i][j-1][0]:0))%MOD;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		(ans+=(f[i][j][0]+f[i][j][1])%MOD)%=MOD;
	printf("%d",ans);
}