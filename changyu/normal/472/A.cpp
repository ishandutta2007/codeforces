#include<cstdio>
int n;
bool benp(int a){for(int i=2;i*i<=a;i++)if(a%i==0)return 1;return 0;}
int main(){
	scanf("%d",&n);
	for(int i=4;i*2<=n;i++)
	if(benp(i)&&benp(n-i))return 0*printf("%d %d",i,n-i);
}