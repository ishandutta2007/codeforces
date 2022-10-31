#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5; int c[50];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n){
		int x; scanf("%d",&x);
		rep(j,0,19) if (x>>j&1) ++c[j];
	}
	ll ans=0;
	rep(i,1,n){
		int x=0;
		rep(j,0,19) if (c[j]) x+=1<<j,--c[j];
		ans+=(ll)x*x;
	}
	printf("%lld\n",ans);
	return 0;
}