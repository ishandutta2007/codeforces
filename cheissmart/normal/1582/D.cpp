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

void solve() {
	int n;
	cin >> n;
	vi a(n), b(n);
	map<int, int> cnt;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	if(n % 2 == 0) {
		for(int i = 0; i < n; i++) {
			b[i] = a[i ^ 1];
			if(i & 1)
				b[i] *= -1;
			cout << b[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if(int(cnt.size()) < n) {
		int num = -1;
		for(auto[x, y]:cnt)
			if(y > 1)
				num = x;
		int i = int(find(ALL(a), num) - a.begin());
		int j = int(find(1 + i + ALL(a), num) - a.begin());
		vi pos;
		for(int k = 0; k < n; k++) if(k != i)
			pos.PB(k);
		assert(pos.size() % 2 == 0);
		for(int k = 0; k < int(pos.size()); k++) {
			b[pos[k]] = a[pos[k ^ 1]];
			if(k & 1)
				b[pos[k]] *= -1;
		}
		if(b[j] > 0) {
			b[j]++;
			b[i]--;
		} else {
			b[j]--;
			b[i]++;
		}
	} else {
		int x = a[0], y = a[1], z = a[2];
		b[0] = -y, b[1] = x - z, b[2] = y;
		for(int i = 3; i < n; i += 2) {
			b[i] = a[i + 1];
			b[i + 1] = a[i];
			b[i] *= -1;
		}
	}
	ll dot = 0;
	for(int i = 0; i < n; i++) {
		dot += 1LL * a[i] * b[i];
		cout << b[i] << ' ';
	}
	cout << '\n';
	assert(dot == 0);
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}