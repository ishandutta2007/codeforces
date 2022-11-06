#include<bits/stdc++.h>
using namespace std;
int f[10000];
long long n;
int max(int x,int y){
	return x>y?x:y;
}
long long work(long long x){
	if(x<=1LL)return x;
	if(2<=x&&x<=4LL)return x-1;
	if(x&1LL)return x-work(x-1);
	long long y=x>>1;
	if(y&1LL)return x-work(y);
	return x-work(x-1);
}
int main(){
	int T,i;
	long long ans=0;
	
	/*for(i=1;i<=50;++i){
		if(i&1)f[i]=i-f[i-1];
		else f[i]=i-min(f[i-1],f[i>>1]);
		printf("%d:%d\n",i,f[i]);
	}*/
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%lld",&n);
		printf("%lld\n",work(n));
	}
	return 0;
}