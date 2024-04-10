#include <stdio.h>
#include <string.h>
int main(){
	long long int k,l;
	scanf("%I64d\n%I64d",&k,&l);
	long long int a=k,i=0;
	while(a<l){
	a*=k;i++;
	}
	if(a==l)printf("YES\n%I64d",i);
	else printf("NO");
}