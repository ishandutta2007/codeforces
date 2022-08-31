#include <stdio.h>
#include <string.h>
int max(int a,int b){
	if(a<0)a*=-1;
	if(b<0)b*=-1;
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int r1,c1,r2,c2;
scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	if(r1==r2&&c1==c2){
		printf("0 0 0");return 0;
	}
	printf((r1==r2||c1==c2)?"1":"2");
	if(((r1+c1)%2)==((r2+c2)%2))
	printf((((r1+c1)==(r2+c2))||((r1-c1)==(r2-c2)))?" 1":" 2");
	else printf(" 0");
	printf(" %d",max(r1-r2,c1-c2));
}