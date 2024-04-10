#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
map<int,int> cnt[11];
int log (ll x) {
	ll i = 1; int ret = 1;
	while (i*10 <= x) i *= 10, ret++;
	return ret;
}
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	vector<ll> a(n);
	for (auto &au : a) {
		scanf ("%llu",&au);
		++cnt[log(au)][(int)(au%k)];
	}
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		--cnt[log(a[i])][(int)(a[i]%k)];
		ll cur = a[i];
		for (int lg = 1; lg <= 10; lg++) {
			cur *= 10; int rem = (int)(cur%k);
			rem = k-rem;
			if (rem == k) rem = 0;
			ret += cnt[lg][rem];
		}
		++cnt[log(a[i])][(int)(a[i]%k)];
	}
	printf ("%llu\n",ret);
    return 0;
}
//a[i]+x == 0 mod k