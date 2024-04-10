#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define fi first
#define se second
#define ll long long 
using namespace std;
const int N=1e6+6; int n; ll a[N],c[N];
ll Q(ll x){ return x>=0?x+1>>1:x/2; }
int main(){
	scanf("%d",&n); ll s=0;
	rep(i,1,n) scanf("%lld",&a[i]),s+=i>1?max(c[i]=a[i]-a[i-1],0LL):0;
	printf("%lld\n",Q(s+a[1]));
	int q; scanf("%d",&q);
	while (q--){
		int l,r,x; scanf("%d%d%d",&l,&r,&x);
		if (l>1) s-=max(c[l],0LL),s+=max(c[l]+=x,0LL);
		if (r<n) s-=max(c[r+1],0LL),s+=max(c[r+1]-=x,0LL);
		if (l==1) a[1]+=x;
		printf("%lld\n",Q(s+a[1]));
	}
	return 0;
}