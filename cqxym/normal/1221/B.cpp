#include<stdio.h>
#define R register int
int main(){
	int n;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		for(R j=0;j<n;j++){
			if((i+j&1)==0){
				printf("W"); 
			}else{
				printf("B");
			}
		}
		puts("");
	}
	return 0;
}