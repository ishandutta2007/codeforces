#include<stdio.h>
#define R register int
#define L long long
long long f[51];
int main(){
	int n;
	scanf("%d",&n);
	L k;
	scanf("%lld",&k);
	f[0]=f[1]=1;
	for(R i=2;i<=n;i++)f[i]=f[i-1]+f[i-2];
	for(R i=1;i<=n;i++){
		if(k<=f[n-i]){
			printf("%d ",i);
		}else{
			k-=f[n-i];
			printf("%d %d ",i+1,i);
			i++;
		}
	}
}