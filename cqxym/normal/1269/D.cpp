#include<stdio.h>
int main(){
	int n,x;
	scanf("%d",&n);
	long long a=0,b=0;
	for(register int i=0;i!=n;i++){
		scanf("%d",&x);
		if((i&1)==1){
			a+=x>>1;
			b+=x+1>>1;
		}else{
			b+=x>>1;
			a+=x+1>>1;
		}
	}
	printf("%lld",a<b?a:b);
	return 0;
}