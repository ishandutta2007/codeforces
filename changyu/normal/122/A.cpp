#include<cstdio>
bool luck(int a){
	for(;a;a/=10)if(a%10!=4&&a%10!=7)return 0;
	return 1;
}
int a;
int main(){
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	  if(a%i==0&&luck(i))return 0*puts("YES");
	return 0*puts("NO");
}