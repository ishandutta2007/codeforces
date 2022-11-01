#include<stdio.h>
int main(){
	int t,n,m;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d",&n,&m);
		if(n%m==0){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}