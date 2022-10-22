#include<cstdio>
int a,c;
int main(){
	scanf("%d",&a);
	for(;a;a-=a&-a)c++;
	printf("%d",c);
	return 0;
}