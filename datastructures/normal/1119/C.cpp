#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[505][505],b[505][505],c[505][505];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			c[i][j]=(a[i][j]^b[i][j]);
	int fg=1;
	for (int i=1;i<=n;i++){
		int num=0;
		for (int j=1;j<=m;j++)num+=c[i][j];
		if (num&1)fg=0;
	}
	for (int i=1;i<=m;i++){
		int num=0;
		for (int j=1;j<=n;j++)num+=c[j][i];
		if (num&1)fg=0;
	}
	if (fg==0)puts("No");
	else puts("Yes");
	return 0;
}