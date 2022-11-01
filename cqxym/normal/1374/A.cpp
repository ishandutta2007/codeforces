#include<stdio.h>
inline void Solve(){
	int x,y,n;
	scanf("%d%d%d",&x,&y,&n);
	int k=n-y;
	k-=k%x;
	printf("%d\n",k+y);
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}