#include <stdio.h>
#include <string.h>
int rm(int a){
	int n=1,m=0;
	while(a!=0){
		int d=a%10;
		a/=10;
		if(d==0)continue;
		m+=n*d;
		n*=10;
	}
	return m;
}
int main(){
	int a,b;
	scanf("%d\n%d",&a,&b);
	if(rm(a)+rm(b)-rm(a+b))
	printf("NO");
	else printf("YES");
}