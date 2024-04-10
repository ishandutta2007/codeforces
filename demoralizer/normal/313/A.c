#include <stdio.h>
#include <string.h>
int main(){
	int n,k;
	scanf("%d",&n);
	if(n<0){
		n*=-1;
		k=n%10;
		n/=10;
		k=(k<(n%10))?k:(n%10);
		n=n/10*10+k;
		n*=-1;
	}
	printf("%d",n);
}