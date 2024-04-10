#include<cstdio>
int n; 
int main(){ 
	scanf("%d",&n);
	puts(n&1||n==2?"NO":"YES");
}