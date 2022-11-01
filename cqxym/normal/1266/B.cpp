#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	long long s;
	for(register int i=0;i!=t;i++){
		scanf("%lld",&s);
		if(s%14>6||s<15||s%14==0){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}