//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1;
const int INF = 2e18;
const int mod = 1e9 + 7;

int T,n;
int a,b,q,l,r;
int lcm;

int GCD(int x,int y) {
	if(!y) return x;
	return GCD(y,x % y);
}

inline int calc(int x) {
	return (x / lcm) * (lcm - b) + max(0ll,x - x / lcm * lcm - b);
}

signed main () {
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld%lld%lld",&a,&b,&q);
		if(a > b) swap(a,b);
		lcm = a * b / GCD(a,b);
		//cout << lcm << endl;
		while(q--) {
			scanf("%lld%lld",&l,&r);
			l++,r++;
			printf("%lld\n",calc(r) - calc(l - 1));
		}
	}
	return 0;
}