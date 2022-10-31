#include<stdio.h>
#define R register int
inline void Solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n*m%2==0){
		for(R i=1;i!=n;i++){
			for(R j=0;j!=m;j++){
				if(i%2!=j%2){
					putchar('B');
				}else{
					putchar('W');
				}
			}
			puts("");
		}
		if(n%2==0){
			putchar('B');
		}
		for(R i=1;i!=m;i++){
			if(i%2==1){
				putchar('B');
			}else{
				putchar('W');
			}
		}
		if(n%2==1){
			putchar('B');
		}
		puts("");
	}else{
		for(R i=0;i!=n;i++){
			for(R j=0;j!=m;j++){
				if(i%2==j%2){
					putchar('B');
				}else{
					putchar('W');
				}
			}
			puts("");
		}
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