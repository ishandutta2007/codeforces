#include<stdio.h>
#define R register int
int main(){
	int t,ct0,ct1,x,n;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		scanf("%d",&n);
		ct1=ct0=0;
		for(R i=0;i!=n;i++){
			scanf("%d",&x);
			if((x&1)==1){
				ct1++;
			}else{
				ct0++;
			}
		}
		if((ct1&1)==1||(ct1!=0&&ct0!=0)){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}