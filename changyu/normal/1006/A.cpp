#include<cstdio>
int n,a;
int main(){
	scanf("%d%d",&n,&a);printf("%d",a&1?a:a-1);
	for(;--n;)scanf("%d",&a),printf(" %d",a&1?a:a-1);
	return 0;
}