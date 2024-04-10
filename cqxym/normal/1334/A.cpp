#include<stdio.h>
#define R register int
inline void Solve(){
	int n,l1=0,l2=0,x,y;
	scanf("%d",&n);
	bool tag=false;
	for(R i=0;i!=n;i++){
		scanf("%d%d",&x,&y);
		if(x<l1||y<l2||x-l1<y-l2){
			tag=true;
		}
		l1=x;
		l2=y;
	}
	if(tag==true){
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