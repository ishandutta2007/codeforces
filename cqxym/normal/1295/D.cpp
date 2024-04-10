#include<stdio.h>
#include<cmath>
#define R register int
#define L long long
#define I inline
I L Gcd(L x,L y){
	return y==0?x:Gcd(y,x%y);
}
I void Dev(L &n,int x){
	do{
		n/=x;
	}while(n%x==0);
}
I void Solve(){
	L a,m,ans;
	scanf("%lld%lld",&a,&m);
	m/=Gcd(a,m);
	a=sqrt(m);
	ans=m;
	if((m&1)==0){
		ans>>=1;
		Dev(m,2);
	}
	for(R i=3;i<=a&&m!=1;i+=2){
		if(m%i==0){
			ans-=ans/i;
			Dev(m,i);
		}
	}
	if(m!=1){
		ans-=ans/m;
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}