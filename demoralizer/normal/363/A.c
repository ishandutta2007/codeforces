#include <stdio.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	do{
		int d=n%10;
		printf("%s",d>4?"-O":"O-");
		d%=5;
		printf("|");
		for(int i=0;i<5;i++)
			printf("%c",i==d?'-':'O');
		n/=10;printf("\n");
	}while(n!=0);
}