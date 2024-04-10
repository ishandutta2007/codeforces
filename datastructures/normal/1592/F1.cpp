#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
char s[505][505];
int a[505][505];
int c[505],d[505],e;
int val,ans;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++){
			if (s[i][j]=='W')a[i][j]=0;
			if (s[i][j]=='B')a[i][j]=1;
		}
	}
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--)
			a[i][j]=(a[i][j]^a[i][j-1]^a[i-1][j]^a[i-1][j-1]);
	e=a[1][1];
	for (int i=2;i<=n;i++)c[i]=a[i][1];
	for (int i=2;i<=m;i++)d[i]=a[1][i];
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++)
			if (a[i][j]==1)c[i]^=1,d[j]^=1,e^=1,val++;
	for (int i=2;i<=n;i++)
		if (c[i]==1)val++,e^=1;
	for (int i=2;i<=m;i++)
		if (d[i]==1)val++,e^=1;
	if (e==1)val++;
	ans=val;
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++)
			if (a[i][j]==1&&c[i]==1&&d[j]==1&&e==1)ans=val-1;
	cout<<ans<<endl;
	return 0;
}
//qwqqwqqwqqwqqwq