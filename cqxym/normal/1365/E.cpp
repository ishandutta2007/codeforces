#include<stdio.h>
#define R register int
#define L long long
L a[500];
int main(){
	int n;
	scanf("%d",&n);
	L ans=0,tem=0;
	for(R i=0;i!=n;i++){
		scanf("%lld",a+i);
		ans|=a[i];
	}
	if(n<4){
		printf("%lld",ans);
	}else{
		ans=0;
		for(R i=2;i!=n;i++){
			for(R j=1;j!=i;j++){
				for(R k=0;k!=j;k++){
					tem=a[i]|a[j]|a[k];
					ans=ans>tem?ans:tem;
				}
			}
		}
		printf("%lld",ans);
	}
	return 0;
}