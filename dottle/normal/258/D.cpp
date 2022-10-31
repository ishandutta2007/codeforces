#include<bits/stdc++.h>
const int N=1005;
using namespace std;

double f[N][N],a[N],ans;
int n,m;

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=a[i]>a[j];
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		for(int i=1;i<=n;i++)
			f[i][x]=f[i][y]=(f[i][x]+f[i][y])/2;
		for(int i=1;i<=n;i++)
			f[x][i]=f[y][i]=(f[x][i]+f[y][i])/2;
		f[x][y]=f[y][x]=.5;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=f[i][j];
	cout<<setprecision(12)<<ans;
}