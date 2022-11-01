#include<stdio.h>
#define R register int
int f[2001][2001];
inline void Max(int &x,int y){
	x=x>y?x:y;
}
inline int Mod(int x,int &y){
	return (x+y)%y;
}
int main(){
	int n,h,l,r,x;
	scanf("%d%d%d%d",&n,&h,&l,&r);
	for(R i=0;i<=n;i++){
		for(R j=0;j<=h;j++){
			f[i][j]=-1e4;
		}
	}
	f[0][0]=0;
	for(R i=1;i<=n;i++){
		scanf("%d",&x);
		for(R j=0;j!=h;j++){
			Max(f[i][j],f[i-1][Mod(j-x,h)]);
			Max(f[i][j],f[i-1][Mod(j-x+1,h)]);
			if(j>=l&&j<=r){
				f[i][j]++;
			}
		}
	}
	int ans=0;
	for(R i=0;i!=h;i++){
		Max(ans,f[n][i]);
	}
	printf("%d",ans);
	return 0;
}