#include<cstdio>
int m;long long a,b,s,t;
int main(){
	scanf("%d",&m);
	for(int j=1;j<=m+m;j++)scanf("%I64d%I64d",&a,&b),s+=a,t+=b;
	printf("%I64d %I64d",s/m,t/m);
	return 0; 
}