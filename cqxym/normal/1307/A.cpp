#include<stdio.h>
#define R register int
inline void Solve(){
	int n,d,x,h;
	scanf("%d%d%d",&n,&d,&x);
	for(R i=1;i!=n;i++){
		scanf("%d",&h);
		if(d>=h*i){
			x+=h;
			d-=h*i;
		}else{
			x+=d/i;
			d=0;
		}
	}
	printf("%d\n",x);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}