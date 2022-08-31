#include <stdio.h>
#include <string.h>
int x(int a,int b){
	return a>b?a:b;
}
int in(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,m,max,min,t;
	scanf("%d %d",&n,&m);
	scanf("%d",&t);max=min=t;
	for(int i=0;i<n-1;i++){
		scanf("%d",&t);
		max=x(max,t);
		min=in(min,t);
	}
	max=x(max,2*min);
	scanf("%d",&t);min=t;
	for(int i=0;i<m-1;i++){
		scanf("%d",&t);
		min=in(min,t);
	}
	if(min>max)printf("%d",max);
	else printf("-1");
}