#include <iostream>
#include <cstdio>
#define inf 1000000000
using namespace std;
int t,n,a[3005],val[3005][3005],f[3005][3005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		for (register int i=1;i<=n;i++)
			for (register int j=1;j<=n;j++)
				val[i][j]=f[i][j]=inf;
		for (register int i=1;i<n;i++)val[i+1][i]=0;
		for (register int i=1;i<=n;i++)
			for (register int j=i;j>=1;j--)
				val[j][i]=val[j+1][i]+(j+a[j]>i);
		for (register int i=1;i<=n;i++)f[1][i]=0;
		for (register int i=1;i<=n;i++){
			for (register int j=1;j<i;j++)
				if (j+a[j]>=i)f[i][j+a[j]]=min(f[i][j+a[j]],f[j][i-1]+val[j+1][i-1]);
			for (register int j=i;j<i+a[i];j++)f[i][j]=min(f[i][j],f[i][j-1]);
		}
		cout<<f[n][n]<<endl;
	}
	return 0;
}