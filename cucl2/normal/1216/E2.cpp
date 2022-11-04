#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

ll N;

ll inline calclen(ll lim) {
	int len = 0;
	ll mii10 = 1;
	ll nlim = lim;
	while (nlim) {
		++len;
		nlim /= 10;
		mii10 *= 10;
	}
	mii10 /= 10;
	ll res = 0;
	ll cn = 9;
	repi(i, len - 1) {
		res += i * cn;
		cn *= 10;
	}
	lim -= mii10 - 1;
	res += lim * len;
	return res;
}

ll inline calcgr(ll lim) {
	ll len = 0;
	ll mii10 = 1;
	int wei = 1;
	while (1) {
		if (mii10 * 10 <= lim) len += wei * ((lim - mii10 + 1) + (lim - 10 * mii10 + 2)) * (9 * mii10) / 2;
		else {
			len += wei * (lim - mii10 + 2) * (lim - mii10 + 1) / 2;
			break;
		}
		mii10 *= 10;
		++wei;
	}
	return len;
}

void solve() {
	scanf("%lld", &N);
	ll l = 0, r = 2e9;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (calcgr(m) < N) l = m;
		else r = m;
	}
	N -= calcgr(l);
	ll L = 0, R = 2e17;
	while (R - L > 1) {
		ll m = (L + R) >> 1;
		if (calclen(m) < N) L = m;
		else R = m;
	}
	ll len = calclen(L);
	int wei = N - len;
	ll num = L + 1;
	vector<int> w;
	while (num) {
		w.push_back(num % 10);
		num /= 10;
	}
	reverse(w.begin(), w.end());
	printf("%d\n", w[wei - 1]);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}