#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[32];
int a[5][100004],b[5][100004];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&a[j][i]);
	for(int i=1;i<=m;i++)for(int j=0;j<n;j++)scanf("%d",&b[j][i]);
	for(int i=1;i<(1<<n);i++)f[i]=1e12;
	for(int i=1;i<m;i++){
		for(int j=0;j<(1<<n);j++)for(int k=0;k<n;k++)f[j^(1<<k)]=min(f[j^(1<<k)],f[j]+a[k][i]);
		for(int j=0;j<(1<<n);j++)for(int k=0;k<n;k++)if((j>>k&1)^(j>>((k+1)%n)&1))f[j]+=b[k][i+1];
	}
	printf("%I64d",f[(1<<n)-1]);
}