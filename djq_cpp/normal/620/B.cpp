#include <cstdio>
int mar[10]={6,2,5,5,4,5,6,3,7,6};
int getmar(int n){
	int sum=0;
	while(n){
		sum+=mar[n%10];
		n/=10;
	}
	return sum;
}
int main(){
	int f,t,ans=0;
	scanf("%d%d",&f,&t);
	for(int k=f;k<=t;k++)
	ans+=getmar(k);
	printf("%d",ans);
	return 0;
}