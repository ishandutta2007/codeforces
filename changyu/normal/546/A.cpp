#include<cstdio>
#define max(a,b)a>b?a:b
int k,n,w;
int main(){
	scanf("%d%d%d",&k,&n,&w);
	printf("%d",max(w*(w+1)/2*k-n,0));
	return 0;
}