#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+5;
int n,r,a[N];LL dat[N],k;
bool check(LL x){
	LL now=0,res=0;
	for(int i=1;i<=n;i++)dat[i]=0;
	for(int i=1;i<=n;i++){
		if(i+r+1<=n)dat[i+r+1]-=(LL)a[i];
		dat[max(i-r,1)]+=(LL)a[i];
	}
	for(int i=1;i<=n;i++){
		now+=dat[i];if(now>=x)continue;
		res+=(x-now);if(i+(r<<1)<n)dat[i+(r<<1)+1]-=(x-now);
		now=x;if(res>k)return false;
	}
	return true;
}
LL binary(LL l,LL r){
	for(LL i=60,t;i>=0;i--){
		t=l+(1LL<<i);
		if(t<=r&&check(t))l=t;
	}
	return l;
}
int main(){
	scanf("%d%d%lld",&n,&r,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	printf("%lld\n",binary(0,2e18));
	return 0;
}