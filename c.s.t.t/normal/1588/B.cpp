#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
ll query(int l,int r){
	printf("? %d %d\n",l,r),fflush(stdout);
	ll x;scanf("%lld",&x);
	return x;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll all=query(1,n);
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(query(mid,n)==all)l=mid;else r=mid-1;
		}
		int p=l+(all-query(l+1,n));
		r=p+1+(query(p+1,n)-query(p+2,n));
		printf("! %d %d %d\n",l,p+1,r),fflush(stdout);
	}
	return 0;
}