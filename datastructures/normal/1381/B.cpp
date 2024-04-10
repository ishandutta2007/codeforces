#include <iostream>
#include <cstdio>
using namespace std;
int t,n,p[10005],f[4005][4005],tot,a[10005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=2*n;i++)scanf("%d",&p[i]);
		for (int i=0;i<=2*n;i++)
			for (int j=0;j<=2*n;j++)
				f[i][j]=0;
		tot=0;
		for (int i=1;i<=2*n;i++){
			int j=i;
			while(p[j]<=p[i]&&j<=2*n)j++;
			a[++tot]=j-i;
			i=j-1;
		}
		f[0][0]=1;
		for (int i=1;i<=tot;i++)
			for (int j=0;j<=n;j++){
				f[i][j]|=f[i-1][j];
				if (j>=a[i])f[i][j]|=f[i-1][j-a[i]];
			}
		if (f[tot][n]==1)puts("YES");
		else puts("NO");
	}
	return 0;
}