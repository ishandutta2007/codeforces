#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char s[1000005],t[1000005];
int f[3][3][1000005];
int a[1000005],b[1000005];
ll ans;
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='R')a[i]=0;
		if(s[i]=='G')a[i]=1;
		if(s[i]=='B')a[i]=2;
	}
	for(int i=1;i<=m;i++){
		if(t[i]=='R')b[i]=0;
		if(t[i]=='G')b[i]=1;
		if(t[i]=='B')b[i]=2;
	}
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)
		for(int k=2;k<=m;k++)
			f[i][j][k]=f[i][j][k-1]+(b[k-1]==i&&b[k]==j);
	int l=1,r=1;
	while(r<m&&a[1]!=b[r])r++;
	ans+=r-l+1;
	for(int i=2;i<=n;i++){
		if(l<=m&&a[i-1]==b[l])l++;
		if(l>m)break;
		if(r<m){++r;while(r<m&&b[r]!=a[i])r++;}
		if(r<l)continue;
		ans+=r-l+1;
		if(a[i]!=a[i-1])ans-=f[a[i]][a[i-1]][r]-f[a[i]][a[i-1]][l-1];
	}
	printf("%lld",ans);
}