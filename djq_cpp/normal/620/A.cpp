#include <cstdio>
long long __max(long long a,long long b){
	if(a<b)return b;
	return a;
}
long long __abs(long long n){
	if(n<0)return -n;
	return n;
}
int main(){
	long long bx,by,ex,ey;
	scanf("%I64d%I64d",&bx,&by);
	scanf("%I64d%I64d",&ex,&ey);
	printf("%I64d",__max(__abs(bx-ex),__abs(by-ey)));
	return 0;
}