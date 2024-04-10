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

void DBG() { cerr << "]" << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

bool link(int u, int v) {
	cout << 1 << ' ' << u << ' ' << v << endl;
	int res; cin >> res;
	return res;
}

void solve() {
	int n; cin >> n;
	vi path({0});
	for(int i = 1; i < n; i++) {
		if(link(i, path[0])) path.insert(path.begin(), i);
		else if(link(path.back(), i)) path.PB(i);
		else {
			int lb = 0, rb = int(path.size() - 1);
			while(rb - lb > 1) {
				int mb = (lb + rb) / 2;
				if(link(i, path[mb])) rb = mb;
				else lb = mb;
			}
			assert(rb - lb == 1);
			path.insert(path.begin() + rb, i);
		}
	}
	assert(int(path.size()) == n);

	auto ask = [&] (int i, int j) {
		cout << 2 << ' ' << path[i] << ' ' << j + 1;
		for(int x = 0; x <= j; x++) cout << ' ' << path[x];
		cout << endl;
		int res; cin >> res;
		return res;
	};
	V<vi> a(n, vi(n));
	for(int i = 0; i < n - 1; i++) a[path[i]][path[i + 1]] = 1;
	for(int i = n - 1, j = n - 1; i >= 0; i--) {
		if(j > i) j = i;
		while(j - 1 >= 0 && ask(i, j - 1)) j--;
		a[path[i]][path[j]] = 1;
	}
	for(int i = 0; i < n; i++) a[i][i] = 1;
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				a[i][j] |= a[i][k] & a[k][j];
	cout << 3 << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cout << a[i][j];
		cout << endl;
	}
	int ans; cin >> ans;
	if(ans != 1) exit(0);
}

signed main()
{
	IO_OP;

	int t; cin >> t;
	while(t--) solve();
	
}