#include<stdio.h>
inline void Solve(){
	int x,y;
	scanf("%d%d",&x,&y);
	if(x>3||x>=y||(x==2&&y==3)){
		puts("YES");
	}else{
		puts("NO");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}