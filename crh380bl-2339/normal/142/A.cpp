#include<cstdio>
//Behold the magic of Brute-Force
inline long long max(long long x,long long y){
	return x>y?x:y;
}
inline long long min(long long x,long long y){
	return x<y?x:y;
}
int main(){
	long long n,i,j,k,m;
	long long maxn=-1,minn=1ll<<62;
	scanf("%lld",&n);
	//n=1e9;
	for(i=1;i*i<=n;i++){
		if(n%i)continue;
		m=n/i;
		for(j=1;j*j<=m;j++){
			if(m%j)continue;
			k=m/j;
			maxn=max(maxn,(i+1)*(j+2)*(k+2));
			maxn=max(maxn,(i+2)*(j+1)*(k+2));
			maxn=max(maxn,(i+2)*(j+2)*(k+1));
			
			minn=min(minn,(i+1)*(j+2)*(k+2));
			minn=min(minn,(i+2)*(j+1)*(k+2));
			minn=min(minn,(i+2)*(j+2)*(k+1));
		}
	}
	printf("%lld %lld",minn-n,maxn-n);
	return 0;
}