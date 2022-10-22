#include<cstdio>
#define max(a,b)a>b?a:b
int n,x,s,a;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a),x=max(x,a),s+=a;
	printf("%d",n*x-s);
	return 0;
}