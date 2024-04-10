#include<stdio.h>
#define R register int
#define L long long
#define I inline
L sum[51][20001],f[51][20001],mx1[51][20002],mx2[51][20002];
int a[51][20001],n,m;
I int Min(int x,int y){
	return x<y?x:y;
}
I L GetSum(int z,int x,int y){
	if(z>n){
		return 0;
	}
	if(x>m){
		x=m;
	}
	if(y>m){
		y=m;
	}
	return sum[z][y]-sum[z][x-1]-sum[z-1][y]+sum[z-1][x-1];
}
I L GetMax1(int x,int y){
	if(x<1||y<1){
		return 0;
	}
	return mx1[x][y];
}
I L GetMax2(int x,int y){
	if(x<1||y<1){
		return 0;
	}
	return mx2[x][y];
}
I L Max(L x,L y){
	return x>y?x:y;
}
int main(){
	int k;
	scanf("%d%d%d",&n,&m,&k);
	for(R i=1;i<=n;i++){
		for(R j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=1;j<=m;j++){
			L S=GetSum(i,j,j+k-1)+GetSum(i+1,j,j+k-1);
			f[i][j]=Max(GetMax1(i-1,j-k),GetMax2(i-1,j+k))+S;
			for(R p=j-k+1>1?j-k+1:1;p<=j;p++){
				f[i][j]=Max(f[i][j],f[i-1][p]+S-GetSum(i,j,p+k-1));
			}
			for(R p=j+1;p<=Min(j+k-1,m);p++){
				f[i][j]=Max(f[i][j],f[i-1][p]+S-GetSum(i,p,j+k-1));
			}
		}
		for(R j=1;j<=m;j++){
			mx1[i][j]=Max(f[i][j],mx1[i][j-1]);
		}
		for(R j=m;j!=0;j--){
			mx2[i][j]=Max(f[i][j],mx2[i][j+1]);
		}
	}
	printf("%lld",mx1[n][m]);
	return 0;
}