#include <stdio.h>
#include <string.h>
int main(){
	int p,c=0,k,i;
	scanf("%d",&p);
	for(int x=1;x<p;x++){
		k=1;
		for(i=1;i<p-1;i++){
			k=(k*x)%p;
			if(k==1)goto abc;
		}
		if((k*x)%p==1)c++;
		abc:;
	}
	printf("%d",c);
}