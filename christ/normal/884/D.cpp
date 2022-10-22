#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
int main() {
	int n;
	scanf ("%d",&n);
	multiset<ll> s;
	for (int i = 0,a; i < n; i++) {
		scanf ("%d",&a);
		s.insert(a);
	}
	ll ret = 0;
	if(n&1^1) {
		ll f = *s.begin(); s.erase(s.begin());
		ll se = *s.begin(); s.erase(s.begin());
		s.insert(f+se);
		ret = f+se;
	}
	while (s.size() > 1) {
		ll f = *s.begin(); s.erase(s.begin());
		ll se = *s.begin(); s.erase(s.begin());
		ll t = *s.begin(); s.erase(s.begin());
		s.insert(f+se+t);
		ret += f+se+t;
	}
	printf ("%lld\n",ret);
    return 0;
}