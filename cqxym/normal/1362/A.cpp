#include<stdio.h>
#define L long long
inline void Solve(){
	L a,b;
	scanf("%lld%lld",&a,&b);
	if(a>b){
		L t=a;
		a=b;
		b=t;
	}
	if(b%a==0){
		b/=a;
		int ans=0;
		while((b&1)==0){
			b>>=1;
			ans++;
		}
		if(b==1){
			printf("%d\n",ans/3+(ans%3!=0));
			return;
		}
	}
	puts("-1");
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}