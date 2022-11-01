#include<stdio.h>
#define R register int
#define L long long
int a[39];
inline void Calc(){
	L n=0,m=1;
	for(R i=0;i<39;i++){
		n+=m*a[i];
		m*=3;
	}
	printf("%lld\n",n);
}
inline void Solve(){
	L n;
	scanf("%lld",&n);
	for(R i=0;i<39;i++){
		a[i]=0;
	}
	R i=0;
	while(n>0){
		a[i]=n%3;
		n/=3;
		i++;
	}
	int r=-1;
	for(R i=38;i>-1;i--){
		if(a[i]==2){
			r=i;
			break;
		}
	}
	if(r==-1){
		Calc();
		return;
	}
	for(R i=0;i<r;i++){
		a[i]=0;
	}
	for(R i=r;i<38;i++){
		if(a[i]==2){
			a[i]=3;
		}
		a[i+1]+=a[i]/3;
		a[i]%=3;
	}
	Calc();
}
int main(){
	int q;
	scanf("%d",&q);
	for(R i=0;i<q;i++){
		Solve();
	}
	return 0;
}