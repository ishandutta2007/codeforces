#include "stdio.h"

int main(){
	int a,b,c,r=0;
	scanf("%d %d %d",&a,&b,&c);
	if(b>=a){
		r++;
	}
	if(c>=a){
	r++;
	}
	if(r==2){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}