#include <stdio.h>
#include <string.h>
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,m,t,a=0,b=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		if(t==1)a++;else b++;
	}
	t=min(a,b);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		a=b-a+1;
		if((a%2)||(a/2>t))printf("0\n");
		else printf("1\n");
	}
}