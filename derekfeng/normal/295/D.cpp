#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int n,m,f[2005][2005],s[2005][2005],ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;i++)f[1][i]=1;
	for(int i=2;i<=n;i++)for(int j=2;j<=m;j++)
		f[i][j]=(((f[i-1][j]+f[i][j-1])%M+f[i][j-1])%M+M-f[i][j-2])%M;
	for(int i=1;i<=n;i++)for(int j=2;j<=m;j++)
		s[i][j]=(s[i-1][j]+f[i][j])%M;
	for(int i=1;i<=n;i++)for(int j=2;j<=m;j++)(ans+=(ll)f[i][j]*s[n+1-i][j]%M*(m+1-j)%M)%=M;
	printf("%d",ans);
}