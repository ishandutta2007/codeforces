#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5;
const int M=1e4+5;
int n,m;
int dp0[N][M],dp1[N][M];
int a[N],b[N];
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>b[i];
	memset(dp0,0xf3,sizeof(dp0));
	memset(dp1,0xf3,sizeof(dp1));
	dp0[0][0]=dp1[0][0]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<n;j++){
			for(k=0;k+a[i]<M;k++)
				dp1[j+1][k+a[i]]=max(dp1[j+1][k+a[i]],dp0[j][k]+(b[i]<<1));
		}
		for(j=0;j<=n;j++){
			for(k=0;k<M;k++)
				dp1[j][k]=max(dp1[j][k],dp0[j][k]+b[i]);
		}
		memcpy(dp0,dp1,sizeof(dp1));
	}
	for(j=1;j<=n;j++){
		int mx=0;
		for(k=0;k<M;k++) mx=max(mx,min(dp1[j][k],(k<<1)));
		printf("%.9lf ",mx/2.0);
	}
	return 0;
}