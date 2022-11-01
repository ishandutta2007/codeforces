#include<stdio.h>
#define L long long 
#define I inline
I int Abs(int x){
	return x<0?-x:x;
}
I int Dis(int x1,int y1,int x2,int y2){
	return Abs(x1-x2)+Abs(y1-y2);
}
I void Min(L &x,L y){
	x=x<y?x:y;
}
I void Solve(){
	int x,y,a,b;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	L ans=(L)Dis(x,y,0,0)*a;
	x=Abs(x);
	y=Abs(y);
	Min(ans,(L)Dis(x,y,x,x)*a+(L)x*b);
	Min(ans,(L)Dis(x,y,y,y)*a+(L)y*b);
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}