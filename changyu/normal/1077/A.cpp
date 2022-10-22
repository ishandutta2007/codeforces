#include<cstdio>
typedef long long ll;
int n;ll a,b;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%I64d%I64d%d",&a,&b,&n);
	printf("%I64d\n",(n>>1)*(a-b)+(n&1)*a);
	}return 0;
}