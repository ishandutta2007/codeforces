#include<stdio.h>
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(register int i=0;i<t;i++){
		scanf("%d%d",&a,&b);
		if((a+b)%3==0&&(a>=b&&b*2>=a||a<b&&a*2>=b)){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}