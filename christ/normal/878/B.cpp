#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+5, MK = 6e4 + 5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1, SQRT = 315;
int a[MN];
int main () {
	int n,k,m;
	scanf ("%d %d %d",&n,&k,&m);
	deque<pii> dq;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		if (dq.empty() || dq.back().first != a[i]) dq.push_back({a[i],1});
		else dq.back().second++;
		if (dq.back().second == k) dq.pop_back();
	}
	if (dq.empty()) return !printf ("0\n");
	int sum = 0;
	for (pii p : dq) sum += p.second;
	ll ret = (ll)sum * m;
	while ((int)dq.size() > 1) {
		if (dq.front().first == dq.back().first && dq.front().second + dq.back().second >= k) {
			int tot = dq.front().second + dq.back().second;
			int rem = tot / k * k;
			ret -= (ll)rem * (m-1);
			dq.pop_front(); dq.pop_back();
			if (rem != tot) break;
		} else break;
	}
	assert(!dq.empty());
	if ((int)dq.size() == 1) {
		ll tot = (ll)dq.front().second * m;
		ll rem = tot / k * k;
		ret -= rem;
		if (tot == rem) {
			return !printf ("0\n");
		}
	}
	printf ("%lld\n",ret);
	return 0;
}