#include<stdio.h>
#define R register int
inline void Solve(){
	int n,x;
	scanf("%d",&n);
	bool a=false,b=false;
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		if((x&1)==1){
			a=true;
		}else{
			b=true;
		}
	}
	if((a&b)==true){
		puts("NO");
	}else{
		puts("YES");
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