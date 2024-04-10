#include<stdio.h>
int main(){
	int t,a,b,c,n;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d%d%d",&a,&b,&c,&n);
		if((a+b+c+n)%3==0&&a+b+n>=c*2&&a+c+n>=b*2&&b+c+n>=a*2){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}