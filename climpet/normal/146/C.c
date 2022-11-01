#include <stdio.h>
int main(void){
	char s[100001],d[1000001];
	int i,c=0,n,a=0,b=0;
	scanf("%s %s",s,d);
	for(n=0;s[n];n++){
		if(s[n]!=d[n]){
			if(s[n]=='4')a++;
			else b++;
		}
	}
	printf("%d\n",a>b?a:b);
	return 0;
}