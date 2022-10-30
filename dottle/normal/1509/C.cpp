#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;

int f[N][N],a[N],n;


main(){
	scanf("%lld",&n);
	memset(f,1,sizeof f); 
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),f[i][i]=0;
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		for(int j=1;j+i-1<=n;j++)	
			f[j][j+i-1]=min(f[j][j+i-2],f[j+1][j+i-1])+a[j+i-1]-a[j];
	printf("%lld",f[1][n]);
}