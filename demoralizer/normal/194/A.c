#include <stdio.h>
#include <string.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	k-=2*n;
	printf("%d",max(0,n-k));
}