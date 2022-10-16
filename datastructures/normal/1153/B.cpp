#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m,h,a[105],b[105],c[105][105],ans[105][105];
signed main(){
	cin>>n>>m>>h;
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)cin>>c[i][j];
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++)
			if (c[j][i]==1)ans[j][i]=a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			if (c[i][j]==1)ans[i][j]=min(ans[i][j],b[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)cout<<ans[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}