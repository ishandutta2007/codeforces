#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int t,n,m,a[305][305],ans[305][305];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				cin>>a[i][j];
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				ans[i][j]=4;
		for (int i=1;i<=m;i++)ans[1][i]=ans[n][i]=3;
		for (int i=1;i<=n;i++)ans[i][1]=ans[i][m]=3;
		ans[1][1]=ans[1][m]=ans[n][1]=ans[n][m]=2;
		int fg=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (a[i][j]>ans[i][j])fg=0;
		if (fg==0)puts("NO");
		else{
			puts("YES");
			for (int i=1;i<=n;i++){
				for (int j=1;j<=m;j++)cout<<ans[i][j]<<' ';
				cout<<endl;
			}
		}
	}
	return 0;
}