#include<stdio.h>
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
inline void Solve(){
	int m,d,w;
	scanf("%d%d%d",&m,&d,&w);
	int q=Gcd(w,d-1);
	int t=w/q,k=m<d?m:d,s;
	s=k/t;
	long long ans=(long long)s*(s-1)/2*t;
	ans+=k%t*s;
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