#include<stdio.h>
#define R register int
int a[5000];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=2;i!=n;i++){
		for(R j=0;j+1!=i;j++){
			if(a[i]==a[j]){
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}