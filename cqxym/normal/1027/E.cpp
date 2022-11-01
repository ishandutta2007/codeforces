#include<stdio.h>
#define R register int
#define P 998244353
int f[501],g[501];
int main(){
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	f[0]=f[1]=g[1]=1;
	for(R i=2;i<=n;i++){
		f[i]=f[i-1]<<1;
		if(f[i]>=P){
			f[i]-=P;
		}
		for(R j=i+1;j<=n;j++){
			f[j]=(f[j-1]<<1)-f[j-i-1];
			if(f[j]<0){
				f[j]+=P;
			}else if(f[j]>=P){
				f[j]-=P;
			}
		}
		g[i]=f[n];
	}
	for(R i=n;i!=0;i--){
		g[i]-=g[i-1];
		if(g[i]<0){
			g[i]+=P;
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=1;j<=n;j++){
			if(i*j<k){
				ans=(2ll*g[i]*g[j]+ans)%P;
			}
		}
	}
	printf("%d",ans);
	return 0;
}