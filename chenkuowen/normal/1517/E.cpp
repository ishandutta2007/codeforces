#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+2e5,MOD=998244353;
int a[N];
ll s[N],s2[N];
ll calc(int l,int r){ return l>r?0:(s[r]-s[l-1]); }
ll calc2(int l,int r){ return l>r?0:((s2[r]-s2[l-1])*(r&1?-1:1)); }
int solve(int l,int r,ll s){
//	printf("[%d %d %lld]\n",l,r,s);
	int left=-1,right=r-l+1>>1;
	while(left<right){
		int mid=left+right+1>>1;
		if(s+calc2(l,l+mid*2-1)-calc(l+mid*2,r)<0) left=mid;
		else right=mid-1;
	}
	return left+1;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
		s2[i]=s2[i-1]+(i&1?-a[i]:a[i]);
	}
	ll ans=0;
	for(int i=0;i<=n+n-2;++i){
		int d; ll s=0;
		if(i==0) d=0;
		else if(i<=n) s+=calc(1,i),d=i;
		else s+=calc(2,i-n+2)-calc(1,1),d=i-n+2;
		ll key=0;
		key+=solve(d+1,n,s);
		if(n>2) key+=solve(d+1,n-3,s+calc(n,n)-calc(n-2,n-1));
		ans+=key;
	}
	for(int i=2;i<=n-2;++i)
		if(calc(1,i)>calc(i+1,n)) ++ans;
	printf("%lld\n",ans%998244353);
	}
	return 0;
}