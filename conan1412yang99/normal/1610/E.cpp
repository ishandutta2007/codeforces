#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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

const int INF = 1e9 + 7, N = 2e5 + 7;

int n;
int a[N];

void solve() {
	int mx = 1;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; ) {
		int j = upper_bound(a, a + n, a[i]) - a;
		int tmp = j;
		if(j == n) {
			mx = max(mx, j - i);
			break;
		}
		int cur = j - i + 1;
		while(j + 1 < n) {
			ll val = ll(a[j] - a[i]) * 2 + a[i];
			if(val > int(1e9)) break;
			int pos = int(lower_bound(a + j + 1, a + n, val) - a);
			if(pos == n) break;
			assert(a[pos] >= val);
			cur++;
			j = pos;
		}
		mx = max(mx, cur);
		i = tmp;
	}
	cout << n - mx << '\n';
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