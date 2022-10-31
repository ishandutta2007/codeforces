#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300005;

vector<pair<int, int>> events[N];
map<int, int> tree;

int n, k, l[N], r[N];
auto split(int p) {
	auto it = tree.lower_bound(p);
	if (it->first == p) return it;
	return tree.emplace_hint(it, p, prev(it)->second);
}
void assign(int l, int r, int id) {
	auto R = split(r + 1), L = split(l);
	for (auto i = L; i != R; ++i) if (i->second != -1)
		events[id].emplace_back(i->second, next(i)->first - i->first);
	tree.erase(L, R), tree[l] = id;
}
void init() {for (int i = 0; i < n; ++i) assign(l[i], r[i], i);}

int cnt[N];
ll check(ll x) {
	int now = 0; ll tot = 0;
	for (int R = 0, L = 0; R < n; ++R) {
		now += cnt[R] = r[R] - l[R] + 1;
		for (auto e : events[R]) {
			if (e.first >= L)
				now -= e.second;
			cnt[e.first] -= e.second;
		}
		while (now >= x)
			now -= cnt[L++];
		tot += L;
	}
	return tot;
}
ll solve(int x) {
	int now = 0; ll sum = 0, ret = 0;
	for (int R = 0, L = 0; R < n; ++R) {
		now += cnt[R] = r[R] - l[R] + 1;
		for (auto e : events[R]) {
			cnt[e.first] -= e.second;
			if (e.first >= L)
				now -= e.second;
			else
				sum -= (ll) e.second * (e.first + 1);
		}
		while (now >= x)
			sum += (ll) (L + 1) * cnt[L], now -= cnt[L++];
		ret += sum + (ll) now * L;
	}
	return ret;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> l[i] >> r[i], --r[i];
	tree[1] = tree[1000000001] = -1, init();
	int l = 1, r = 1000000000, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid) < k) r = mid - 1;
		else l = mid + 1, ans = mid;
	}
	ll cnt = check(ans), sum = solve(ans);
	cout << sum - (ll) (cnt - k) * ans << '\n';
	return 0;
}