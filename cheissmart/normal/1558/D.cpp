#include <bits/stdc++.h>
#include <bits/extc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int INF = 1e9 + 7, M = 998244353, N = 5e5 + 7;

int f[N], inv[N], fi[N];

int C(int n, int k) {
    assert(n < N); assert(k <= n);
	return (ll) f[n] * fi[k] % M * fi[n - k] % M;
}

int H(int n, int k) {
	return C(n + k - 1, k);
}
int ways(int n, int k) { // k jumps
	assert(n > k);
	return H(n + 1, n - k - 1);
}

ordered_set<int> s;

bool bad[N];

void solve() {
	int n, m , k = 0;
	cin >> n >> m;
	vi x(m), y(m), undo, undo_bad;
	for(int i = 0; i < m; i++)
		cin >> x[i] >> y[i];

	for(int i = m - 1; i >= 0; i--) {
		auto it = s.find_by_order(y[i]);
		if(bad[*it])
			bad[*it] = false;
		else
			k++;
		if(it != s.begin()) {
			undo_bad.PB(*(prev(it)));
			bad[*(prev(it))] = true;
		}
		undo.PB(*it);
		s.erase(it);
	}

	cout << ways(n, k) << '\n';
	for(int i:undo)
		s.insert(i);
	for(int i:undo_bad)
		bad[i] = false;
}

signed main()
{
	IO_OP;

	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (ll) f[i - 1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - (ll) M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = (ll) fi[i - 1] * inv[i] % M;

	for(int i = 0; i < 200000; i++)
		s.insert(i);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	
}