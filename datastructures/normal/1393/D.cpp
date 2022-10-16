#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int n,m,f1[2005][2005],f2[2005][2005],f3[2005][2005],f4[2005][2005];
char a[2005][2005];
ll ans;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]==a[i-1][j]&&a[i][j]==a[i][j-1])f1[i][j]=min(f1[i-1][j],f1[i][j-1])+1;
			else f1[i][j]=1;
	for (int i=1;i<=n;i++)
		for (int j=m;j>=1;j--)
			if (a[i][j]==a[i-1][j]&&a[i][j]==a[i][j+1])f2[i][j]=min(f2[i-1][j],f2[i][j+1])+1;
			else f2[i][j]=1;
	for (int i=n;i>=1;i--)
		for (int j=1;j<=m;j++)
			if (a[i][j]==a[i+1][j]&&a[i][j]==a[i][j-1])f3[i][j]=min(f3[i+1][j],f3[i][j-1])+1;
			else f3[i][j]=1;
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--)
			if (a[i][j]==a[i+1][j]&&a[i][j]==a[i][j+1])f4[i][j]=min(f4[i+1][j],f4[i][j+1])+1;
			else f4[i][j]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ans+=min(min(f1[i][j],f2[i][j]),min(f3[i][j],f4[i][j]));
	cout<<ans<<endl;
	return 0;
}