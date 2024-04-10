#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5; int a[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		ll s=0; rep(i,2,n) s+=max(a[i-1]-a[i],0);
		puts(s<=a[1]?"YES":"NO");
	}
	return 0;
}