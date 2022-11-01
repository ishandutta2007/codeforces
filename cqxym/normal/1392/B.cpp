#include<stdio.h>
#define R register int
#define I inline void
int a[200000];
I Do(int&n){
	int maxa=-2e9;
	for(R i=0;i!=n;i++){
		maxa=maxa>a[i]?maxa:a[i];
	}
	for(R i=0;i!=n;i++){
		a[i]=maxa-a[i];
	}
}
I Print(int&n){
	for(R i=0;i!=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
}
I Solve(){
	int n;
	scanf("%d",&n);
	long long k;
	scanf("%lld",&k);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	Do(n);
	if(k==1){
		return Print(n);
	}
	Do(n);
	if((k&1)==1){
		Do(n);
	}
	Print(n);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}