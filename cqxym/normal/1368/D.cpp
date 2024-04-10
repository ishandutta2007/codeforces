#include<stdio.h>
#define R register int
int ct[20];
int main(){
	int n,x;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		for(R j=0;j!=20;j++){
			if((x>>j&1)==1){
				ct[j]++;
			}
		}
	}
	long long ans=0;
	for(R i=0;i!=n;i++){
		x=0;
		for(R j=0;j!=20;j++){
			if(ct[j]!=0){
				ct[j]--;
				x|=1<<j;
			}
		}
		ans+=(long long)x*x;
	}
	printf("%lld",ans);
	return 0;
}