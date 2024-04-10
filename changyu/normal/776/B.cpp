#include<cstdio>
inline bool prime(int a){
	if(a<2)return 0;
	for(int i=2;i*i<=a;i++)if(a%i==0)return 0;
	return 1;
}
int n;
int main(){
	scanf("%d",&n);
	puts(n<3?"1":"2");
	for(int i=2;i<=n+1;i++)printf("%d ",(prime(i)^1)+1);
	return 0;
}