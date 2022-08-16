#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define cin_desync()                      \
	do {                                  \
		ios_base::sync_with_stdio(false); \
		cin.tie(0);                       \
	} while (0)                           \

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

const int max_N = 1e6 + 10;

struct bit {
	ll arr[max_N];

	void update(int p, ll x) {
		for (; p < max_N; p += (p &-p)) {
			arr[p] += x;
		}
	}

	ll query(int p) {
		ll ans = 0;
		for (; p > 0; p -= (p & -p)) {
			ans += arr[p];
		}
		return ans;
	}

	ll query(int L, int R)
	{
		return query(R) - query(L - 1);
	}
};


bit ctr, cost;
vector<pair<int, pii>> events;

int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= m; ++i) {
		int l, r, c, p;
		cin >> l >> r >> c >> p;
		events.push_back({l, {c, p}});
		events.push_back({r + 1, {-c, p}});
	}
	events.push_back({n + 1, {0, 0}});
	sort(events.begin(), events.end());
	int eid = 0; ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (events[eid].first <= i) {
			ll c, p;
			tie(c, p) = events[eid].second;
			ctr.update(p, c);
			cost.update(p, p * c);
			++eid;
		}
		int l = 1, r = 1000000;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (ctr.query(1, mid) >= k) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		int last = r + 1;
		ans += cost.query(1, last - 1);
		ll need = k - ctr.query(1, last - 1);
		ans += min(need, ctr.query(last, last)) * last;
	}
	cout << ans << endl;
}