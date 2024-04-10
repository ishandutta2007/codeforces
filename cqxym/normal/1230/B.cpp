#include<stdio.h>
int main(){
	int n,k;
	scanf("%d%d\n",&n,&k);
	char c;
	if(n==1){
		if(k==1){
			printf("0"); 
		}else{
			c=getchar();
			printf("%c",c);
		}
		return 0;
	}
	for(register int i=0;i<n;i++){
		c=getchar();
		if(k>0){
			if(i==0){
				if(c!='1'){
					k--;
				}
				putchar('1');
			}else{
				if(c>'0'){
					k--;
				}
				putchar('0');
			}
		}else{
			printf("%c",c);
		}
	}
	return 0;
}