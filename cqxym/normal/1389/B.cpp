#include<stdio.h>
#define R register int
int a[100001],f[100001][6];
inline void Max(int&x,int y){
	x=x>y?x:y;
}
inline void Solve(){
	int n,k,z;
	scanf("%d%d%d",&n,&k,&z);
	for(R i=0;i<=k;i++){
		for(R j=0;j<=z;j++){
			f[i][j]=-2e9;
		}
	}
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	f[0][0]=a[1];
	for(R i=1;i<=k;i++){
		for(R j=0;j<=z&&j<=i;j++){
			f[i][j]=f[i-1][j];
			if(j!=0){
				Max(f[i][j],f[i][j-1]);
			}
			f[i][j]+=a[i-j+1];
		}
	}
	int ans=0;
	for(R i=0;i<=z;i++){
		Max(ans,f[k-i][i]);
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}