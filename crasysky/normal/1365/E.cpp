#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5; ll a[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	ll ans=0;
	rep(i,1,n)
		rep(j,i,n)
			rep(k,j,n)
				ans=max(ans,a[i]|a[j]|a[k]);
	cout<<ans<<endl;
	return 0;
}