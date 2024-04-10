//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

int T;
int n,a,b,c,k;

signed main () {
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		if((n + a + b + c) % 3) {puts("NO"); continue;}
		k = (a + b + c + n) / 3;
		if(k < a || k < b || k < c) puts("NO");
		else puts("YES");
	}
	return 0;
}