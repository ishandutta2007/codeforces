#include<stdio.h>
#include<algorithm>
#define R register int
struct Cust{
	int T,l,r;
	inline friend bool operator<(Cust x,Cust y){
		return x.T<y.T;
	}
}p[100];
inline void Solve(){
	int n,lf,rt,now=0;
	scanf("%d%d",&n,&lf);
	rt=lf;
	for(R i=0;i!=n;i++){
		scanf("%d%d%d",&p[i].T,&p[i].l,&p[i].r);
	}
	std::sort(p,p+n);
	for(R i=0;i!=n;i++){
		int tem=p[i].T-now;
		rt+=tem;
		lf-=tem;
		if(p[i].l>rt||p[i].r<lf){
			puts("NO");
			return;
		}
		if(lf<p[i].l){
			lf=p[i].l;
		}
		if(rt>p[i].r){
			rt=p[i].r;
		}
		now=p[i].T;
	}
	puts("YES");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve(); 
	}
	return 0;
}