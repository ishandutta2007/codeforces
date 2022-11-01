#include<stdio.h>
#define R register int
#define I inline void
I Max(int&x,int y){
	x=x>y?x:y;
}
I Solve(){
	int n,x,a,s=0;
	scanf("%d%d",&n,&x);
	int ans=-1,lt=1e6;
	for(R i=1;i<=n;i++){
		scanf("%d",&a);
		s=(s+a)%x;
		if(s==0){
			Max(ans,i-lt);
		}else{
			Max(ans,i);
			if(lt==1e6){
				lt=i;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}