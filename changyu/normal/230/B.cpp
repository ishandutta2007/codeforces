#include<cstdio>
#include<cmath>
long long a;
bool prime(int a){
	if(a<2)return 0;
	for(int i=2;i*i<=a;i++)if(a%i==0)return 0;
	return 1;
}
int main(){
	int T;scanf("%d",&T);while(T--){
	  scanf("%I64d",&a);
	  puts(sqrt(a)==floor(sqrt(a))&&prime(sqrt(a))?"YES":"NO");
	}
	return 0;
}