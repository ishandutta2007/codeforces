#include<stdio.h>
void Solve(){
	long long n,m,ans=0;
	scanf("%lld%lld",&n,&m);
	n/=m;
	int s=0;
	for(int i=1;i<10;i++){
		s+=m*i%10;
		if(i==n%10){
			ans=s;
		}
	}
	ans+=n/10*s;
	printf("%lld\n",ans);
}
int main(){
	int q,i;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		Solve();
	}
	return 0;
}