#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define pre(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int n,q,k,a[MAXN],b[MAXN],l,r;
ll sum[MAXN];
int main(){
	scanf("%d%d%d",&n,&q,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);
	}
	rep(i,2,n-1){
		b[i]=a[i+1]-a[i-1]-2;
		sum[i]=sum[i-1]+b[i];
	}
	rep(i,1,q){
		scanf("%d%d",&l,&r);
		if(l==r){
			printf("%lld\n",(ll)k-1);
			continue;
		}
		ll c1=max(0,a[l+1]-2),c2=max(0,k-a[r-1]-1);
		if(l==r-1){
			printf("%lld\n",c1+c2);
			continue;
		}
		printf("%lld\n",c1+c2+sum[r-1]-sum[l]);
	}
	return 0;
}