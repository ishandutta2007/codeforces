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

string to_string(string s) {
	return s;
}

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

void solve() {
	int n, k;
	string a, b;
	cin >> n >> k >> a >> b;
	assert(a.size() == b.size());

	auto trans = [&] (string s) {
		vi res;
		int cnt = 0;
		for(int i:s) {
			if(i == '0')
				cnt++;
			else
				res.PB(cnt), cnt = 0;
		}
		res.PB(cnt);
		return res;
	};

	auto op = [&] (int l, int r) {
		cout << l + 1 << " " << r + 1 << '\n';
	};

	vi sa = trans(a), sb = trans(b);

	if(sa.size() != sb.size())
		return cout << -1 << '\n', void(0);

	if(int(sa.size()) <= k || k == 0)
		return cout << (a == b ? 0 : -1) << '\n', void(0);
	if(k % 2 == 0) {
		int sum_a = 0, sum_b = 0;
		for(int i = 0; i < int(sa.size()); i += 2)
			sum_a += sa[i], sum_b += sb[i];
		if(sum_a != sum_b)
			return cout << -1 << '\n', void(0);
	}

	if(int(sa.size()) == k + 1) {
		vi na = sa, nb = sb;
		if(sa[0] + sa.back() != sb[0] + sb.back())
			return cout << -1 << '\n', void(0);
		na.erase(na.begin()), na.erase(prev(na.end()));
		nb.erase(nb.begin()), nb.erase(prev(nb.end()));
		if(na == nb) {
			cout << 2 << '\n';
			op(sa[0], n - 1);
			op(sb[0], n - 1);
		} else {
			reverse(ALL(nb));
			if(na == nb) {
				cout << 3 << '\n';
				op(sa[0], n - 1);
				op(sb[0], n - 1);
				op(sb[0], n - 1 - sb.back());
			} else {
				cout << -1 << '\n';
			}
		}
		return;
	}

	assert(int(sa.size()) >= k + 2);

	auto get_op = [&] (string &s) -> V<pi> {
		vi ss = trans(s);
		V<pi> ops;
		for(int i = int(ss.size()) - 1; i > k + 1; i--) {
			int r = accumulate(ss.begin(), ss.begin() + i + 1, 0) + i;
			int cnt = 0, l = r - 1;
			while(cnt < k) {
				if(s[l--] == '1')
					cnt++;
			}
			l++;
			ops.EB(l, r - 1);
			assert(count(s.begin() + l, s.begin() + r, '1') == k);
			reverse(s.begin() + l, s.begin() + r);
			ss = trans(s);
		}
		for(int i = 0; i < k * 2; i++) {
			int l, r;
			if(i % 2 == 0) {
				if(k % 2)
					l = 0, r = accumulate(ss.begin(), ss.begin() + k, 0) + k;
				else
					l = ss[0], r = accumulate(ss.begin(), ss.begin() + k + 1, 0) + k;
			} else {
				l = ss[0] + 1;
				r = accumulate(ss.begin(), ss.begin() + k + 1, 0) + k + 1;
			}
			ops.EB(l, r - 1);
			assert(count(s.begin() + l, s.begin() + r, '1') == k);
			reverse(s.begin() + l, s.begin() + r);
			ss = trans(s);
		}
		return ops;
	};
	string aa = a, bb = b;
	V<pi> opa = get_op(a), opb = get_op(b);
	assert(a == b);
	reverse(ALL(opb));
	for(pi p:opb)
		opa.PB(p);
	cout << opa.size() << '\n';
	for(pi p:opa)
		op(p.F, p.S);
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}