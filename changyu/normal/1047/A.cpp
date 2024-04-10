#include<cstdio>
int a; 
int main(){
	scanf("%d",&a);
	if(a%3==0)return 0*printf("1 1 %d",a-2);
	if(a%3==1)return 0*printf("1 1 %d",a-2);
	if(a%3==2)return 0*printf("1 2 %d",a-3);
}