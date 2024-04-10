#include <stdio.h>
#include <string.h>
int min(int a,int b,int c){
	int d=a<b?a:b;
	if(c<d)d=c;
	return d;
}
int main(){
	int n,k,l,c,d,p,nl,np;
	scanf("%d %d %d %d %d %d %d %d",&n,&k,&l,&c,&d,&p,&nl,&np);
	int r=min(k*l/nl,c*d,p/np)/n;
	printf("%d",r);
}