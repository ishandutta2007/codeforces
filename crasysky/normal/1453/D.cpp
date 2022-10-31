#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
int a[10004];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		ll n; scanf("%lld",&n);
		if (n&1){ puts("-1"); continue; }
		int m=0; a[++m]=1; n-=2;
		if (n&2) a[++m]=1;
		rep(i,1,59)
			if (n>>i+1&1){
				rep(j,1,i-1) a[++m]=0;
				a[++m]=1,a[++m]=1;
			}
		printf("%d\n",m);
		rep(i,1,m) printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}