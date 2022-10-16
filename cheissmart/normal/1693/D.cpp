#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], as_in[N], as_de[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		as_in[i] = -INF;
		as_de[i] = INF;
	}

	int cnt = 0;

	function<bool(int, int)> upd_in;
	function<bool(int, int)> upd_de;
	function<void(int)> cal;

	auto good = [&] (int i) {
		return as_in[i] != -INF || as_de[i] != INF;
	};

	upd_in = [&] (int i, int x) {
		if(as_in[i] == x) return false;
		cnt -= good(i);
		as_in[i] = x;
		cnt += good(i);
		return true;
	};

	upd_de = [&] (int i, int x) {
		if(as_de[i] == x) return false;
		cnt -= good(i);
		as_de[i] = x;
		cnt += good(i);
		return true;
	};

	cal = [&] (int i) {
		int new_as_in = -INF;
		if(a[i - 1] < a[i]) new_as_in = max(new_as_in, as_in[i - 1]);
		if(as_de[i - 1] < a[i]) new_as_in = max(new_as_in, a[i - 1]);

		int new_as_de = INF;
		if(a[i - 1] > a[i]) new_as_de = min(new_as_de, as_de[i - 1]);
		if(as_in[i - 1] > a[i]) new_as_de = min(new_as_de, a[i - 1]);

		bool he = upd_in(i, new_as_in);
		bool be = upd_de(i, new_as_de);
		if((he || be) && i + 1 < n)
			cal(i + 1);
	};

	ll ans = 0;

	for(int i = n - 1; i >= 0; i--) {
		// as_in[i] = INF
		// as_de[i] = -INF
		bool he = upd_in(i, INF);
		bool be = upd_de(i, -INF);
		if((he || be) && i + 1 < n)
			cal(i + 1);
		ans += cnt;
	}

	cout << ans << '\n';

}