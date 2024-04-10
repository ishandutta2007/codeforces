#include<stdio.h>
inline void Solve(){
	int a,b,n,s=0;
	scanf("%d%d%d",&a,&b,&n);
	while(a<=n&&b<=n){
		s++;
		if(a<b){
			a+=b;
		}else{
			b+=a;
		}
	}
	printf("%d\n",s);
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}