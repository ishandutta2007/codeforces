#include <bits/stdc++.h>
#ifdef _WIN32
#define lld I64d
#endif
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 33;
ll a[N],b[N],k[N],p[N],pinv[N],n,u,r;
ll t[N];

inline void O1() {
	for(int i = 1; i <= n; ++i)
		a[i] ^= b[i];
}

inline void O2_f() {
	for(int i = 1; i <= n; ++i)
		t[i] = a[p[i]] + r;
	swap(a,t);
}

inline void O2_b() {
	for(int i = 1; i <= n; ++i)
		t[i] = a[pinv[i]] - r;
	swap(a,t);
}

ll go(int u, bool just_xor) {
	ll ans = -(1LL<<60);
	if(u % 2 == 0) {
		ll w = 0;
		for(int i = 1; i <= n; ++i)
			w += a[i] * k[i];
		ans = w;
	}
	if(u > 0) {
		if(!just_xor) {
			O1();
			ans = max(ans, go(u-1,true));
			O1();
		}
		O2_f();
		ans = max(ans,go(u-1,false));
		O2_b();
	}
	return ans;
}

int main() {
	scanf("%lld%lld%lld",&n,&u,&r);
	for(int i = 1; i <= n; ++i) scanf("%lld",a+i);
	for(int i = 1; i <= n; ++i) scanf("%lld",b+i);
	for(int i = 1; i <= n; ++i) scanf("%lld",k+i);
	for(int i = 1; i <= n; ++i) scanf("%lld",p+i);
	for(int i = 1; i <= n; ++i) pinv[p[i]] = i;

	printf("%lld\n",go(u,false));
}