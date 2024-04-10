#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1505][1505],c[1505];
int u[2250005],v[2250005];
ll ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)c[j]=a[i][j];
		sort(c+1,c+n+1);
		for(int j=1;j<=n;j++)u[c[j]]=j;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)c[j]=a[j][i];
		sort(c+1,c+n+1);
		for(int j=1;j<=n;j++)v[c[j]]=j;
	}
	for(int i=1;i<=n*n;i++)
		ans+=(ll)(u[i]-1)*(n-v[i])+(ll)(v[i]-1)*(n-u[i]);
	printf("%lld",ans/2);
}