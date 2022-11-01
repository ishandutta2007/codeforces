#include<stdio.h>
#define R register int
inline void Solve(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("-1");
	}else{
		putchar('2');
		for(R i=1;i!=n;i++){
			putchar('9');
		}
		puts("");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}