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

const int INF = 1e9 + 7, N = 1e6 + 7;

ll inv(vi a) {
	int n = int(a.size());
	vi b = a;
	sort(ALL(b));

	vi bit(n + 1);
	auto add = [&] (int pos, int val) {
		pos++;
		for(; pos < int(bit.size()); pos += pos & -pos)
			bit[pos] += val;
	};
	auto qry = [&] (int pos) {
		pos++;
		int res = 0;
		for(; pos; pos -= pos & -pos)
			res += bit[pos];
		return res;
	};

	ll res = 0;
	for(int i = n - 1; i >= 0; i--) {
		a[i] = int(lower_bound(ALL(b), a[i]) - b.begin());
		res += qry(a[i] - 1);
		add(a[i], 1);
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	sort(ALL(b));
	vi bit(m + 1);
	auto add = [&] (int pos, int val) {
		pos++;
		for(; pos < int(bit.size()); pos += pos & -pos)
			bit[pos] += val;
	};
	auto qry = [&] (int pos) {
		assert(0 <= pos && pos < m);
		pos++;
		int res = 0;
		for(; pos; pos -= pos & -pos)
			res += bit[pos];
		return res;
	};
	auto find_first_greater = [&] (int val) {
		int pos = 0, sum = 0;
		for(int i = 19; i >= 0; i--) {
			if(pos + (1 << i) < int(bit.size()) &&
			   bit[pos + (1 << i)] + sum <= val) {
				sum += bit[pos += (1 << i)];
			}
		}
		pos++;
		return pos - 1;
	};
	auto radd = [&] (int l, int r, int val) {
		add(l, val);
		add(r + 1, -val);
	};
	ll left_val = 0;
	for(int i = 0; i < n; i++) {
		int l = int(lower_bound(ALL(b), a[i]) - b.begin());
		int r = int(upper_bound(ALL(b), a[i]) - b.begin());
		if(l > 0) radd(0, l - 1, -1), left_val += l;
		if(r < m) radd(r, m - 1, 1);
		while(true) {
			int pos = find_first_greater(0);
			if(pos < m) {
				int val = qry(pos);
				add(pos, -val);
			} else {
				break;
			}
		}
	}
	for(int i = 0; i < m; i++)
		left_val += qry(i);
	cout << left_val + inv(a) << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

	
}