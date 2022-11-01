#include<stdio.h>
inline void Solve(){
	long long n,a,b,s;
	scanf("%lld%lld%lld%lld",&a,&b,&n,&s);
	if(n*a<=s){
		if(n*a+b<s){
			puts("NO");
		}else{
			puts("YES");
		}
	}else{
		if(b<s%n){
			puts("NO");
		}else{
			puts("YES");
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i<t;i++){
		Solve();
	}
	return 0;
}