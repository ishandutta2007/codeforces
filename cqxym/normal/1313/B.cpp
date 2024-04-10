#include<stdio.h>
#define R register int
inline int Min(int x,int y){
	return x<y?x:y; 
}
inline int Max(int x,int y){
	return x>y?x:y;
}
inline void Solve(){
	int x,y,n;
	scanf("%d%d%d",&n,&x,&y);
	printf("%d %d\n",Min(Max(x+y+1-n,1),n),Min(n,x+y-1));
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}