#include<stdio.h>
int main(){
	int a,k;
	scanf("%d%d",&a,&k);
	for(register int i=0;i<k;i++){
		if(a%10>0){
			a--;
		}else{
			a/=10;
		}
	}
	printf("%d",a);
	return 0;
}