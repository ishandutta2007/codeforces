#include<stdio.h>
#include<algorithm>
#define R register int
#define I inline
#define N 500001
int C[N],val[N],a[N];
I int GetSum(int x){
	int res=0;
	for(R i=x;i!=0;i&=i-1){
		res+=C[i];
	}
	return res;
}
I void Add(int x,const int n){
	for(R i=x;i<=n;i+=i&-i){
		C[i]++;
	}
}
I void Solve(){
	int n,x;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		C[i]=0;
	}
	for(R i=1;i<=n;i++){
		val[i]=i-1-(GetSum(a[i])<<1);
		Add(a[i],n);
	}
	for(R i=1;i<=n;i++){
		C[i]=0;
	}
	long long sum=0;
	for(R i=n;i!=0;i--){
		x=GetSum(a[i]);
		sum+=x;
		val[i]-=x<<1;
		Add(a[i],n);
	}
	std::sort(val+1,val+n+1);
	printf("%lld",sum);
	for(R i=n;i!=0;i--){
		sum-=val[i]+n-i;
		printf(" %lld",sum);
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