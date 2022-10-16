#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

V<ll> masks[11];

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	if(n == 1) return cout << "ACCEPTED\n", 0;

	V<ll> a({0LL}), b({0LL});
	for(int i = 1; i <= k; i++) {
		int q;
		cin >> q;
		masks[i].PB(0LL);
		for(int j = 0; j < q; j++) {
			int x;
			cin >> x;
			x--;
			for(ll& mask:masks[i])
				mask |= 1LL << x;
			masks[i].PB(0LL);
		}
		reverse(ALL(masks[i]));
		ll mask = masks[i].back();
		a.PB(mask);
		b.PB(mask | b.back());
	}

	ll full_mask = (1LL << n) - 1;
	if(b.back() != full_mask) return cout << "REJECTED\n", 0;

	bool ok = true;

	function<void(int, ll)> dfs = [&] (int i, ll mask) {
		if(i == k + 1) {
			int zero_cnt = n - __builtin_popcountll(mask);
			if(mask != (full_mask >> zero_cnt << zero_cnt))
				ok = false;
			return;
		}
		int more = __builtin_popcountll(b[i]) - __builtin_popcountll(b[i - 1]);
		int cnt = __builtin_popcountll(a[i] & b[i - 1] & mask);
		ll nmask = mask & (full_mask ^ a[i]);
		for(int j = cnt; j <= cnt + more; j++) {
			dfs(i + 1, nmask | masks[i][j]);
		}
	};

	dfs(1, 0LL);

	cout << (ok ? "ACCEPTED" : "REJECTED") << '\n';

}