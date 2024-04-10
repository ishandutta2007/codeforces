#include <stdio.h>
#include <string.h>
int main(){
	long long int n,k;
	scanf("%I64d %I64d",&n,&k);
	if(k<=(n+1)/2){
		printf("%I64d",2*k-1);
	}
	else{
	k-=(n+1)/2;
	printf("%I64d",2*k);
	}
}