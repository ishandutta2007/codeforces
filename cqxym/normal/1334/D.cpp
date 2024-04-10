#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define L long long
I int Get(L x,int ans){
	L sum=0;
	while(sum<x){
		ans--;
		sum+=ans<<1;
	}
	return ans;
}
I void Solve(){
	int n;
	L l,r;
	scanf("%d",&n);
	scanf("%lld%lld",&l,&r);
	L tot=(L)n*(n-1)+1;
	bool tag=false;
	if(l==tot){
		puts("1");
		return;
	}else if(r==tot){
		r--;
		tag=true;
	}
	int a=Get(l,n);
	L tem=(L)(a+n)*(n-a-1);
	for(register L i=l;i<=r;i++){
		if(i-tem>a<<1){
			tem+=a<<1;
			a--;
		}
		if((i&1)==1){
			printf("%d ",n-a);
		}else{
			printf("%d ",(i-tem>>1)+n-a);
		}
	}
	if(tag==true){
		putchar('1');
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}