#include<stdio.h>
#define R register int
#define L long long
int f[250001],m;
inline L Sqr(int x){
	return (L)x*x%m;
}
int main(){
	int n,s=0;
	scanf("%d%d",&n,&m);
	f[0]=1;
	for(R i=1;i<=n;i++){
		f[i]=(L)f[i-1]*i%m;
	}
	for(R i=1;i<=n;i++){
		s=(s+Sqr(n-i+1)*f[i]%m*f[n-i]%m)%m;
	}
	printf("%d",s);
	return 0;
}