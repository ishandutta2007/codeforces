#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6; int a[N];
ll S(int l,int r){ return (ll)(l+r)*(r-l+1)/2; }
int main(){
	int n; ll x,ans=0; scanf("%d%lld",&n,&x);
	rep(i,1,n){
		scanf("%d",&a[i]); a[n+i]=a[i];
	}
	ll s=0,v=0;
	for (int r=1,l=0;r<=2*n;++r){//(l,r]
		s+=a[r],v+=S(1,a[r]);
		while (s>x) s-=a[++l],v-=S(1,a[l]);
		if (x-s<=a[l]) ans=max(ans,v+S(a[l]-(x-s)+1,a[l]));
	}
	s=0,v=0;
	for (int l=2*n,r=2*n+1;l;--l){//[l,r)
		s+=a[l],v+=S(1,a[l]);
		while (s>x) s-=a[--r],v-=S(1,a[r]);
		if (x-s<=a[r]) ans=max(ans,v+S(1,x-s));
	}
	printf("%lld\n",ans);
	return 0;
}