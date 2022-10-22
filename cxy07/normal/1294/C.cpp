//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,n,lim,cnt;
vector<int> v;

signed main () {
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld",&n);
		lim = sqrt(n);
		v.clear();
		cnt = 0;
		for(register int i = 2;i <= lim; ++i) {
			if(!(n % i)) {
				n /= i,cnt++;
				v.push_back(i);
			}
			if(cnt == 2) break;
		}
		if(cnt != 2) {puts("NO"); continue;}
		if(v[0] == n || v[1] == n || n <= 1) {puts("NO"); continue;}
		puts("YES");
		printf("%lld %lld %lld\n",v[0],v[1],n);
	}
	return 0;
}