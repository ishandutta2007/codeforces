#include<stdio.h>
#define R register int
char s[1000];
inline void Solve(){
	int n,ct0=0,ct1=0;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		getchar();
		char c=getchar();
		s[i]=c;
		if(c=='0'){
			ct0++;
		}else{
			ct1++;
		}
	}
	int m=(n>>1)+(n>>1&1);
	if(ct0>=n>>1){
		printf("%d\n",n>>1);
		for(R i=0;i!=n>>1;i++){
			printf("0 ");
		}
		puts("");
	}else{
		printf("%d\n",m);
		for(R i=0;i!=m;i++){
			printf("1 ");
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