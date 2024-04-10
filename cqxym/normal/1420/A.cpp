#include<stdio.h>
#define R register int
inline void Solve(){
	int n,x,y;
	scanf("%d%d",&n,&x);
	bool tag=false;
	for(R i=1;i!=n;i++){
		scanf("%d",&y);
		if(x<=y){
			tag=true;
		}
		x=y;
	}
	if(tag==true){
		puts("Yes");
	}else{
		puts("No");
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