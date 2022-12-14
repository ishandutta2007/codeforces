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

const int INF = 1e9 + 7, M = 998244353, N = 2e5 + 7;

namespace bit {
	int bit[N];
	void add(int pos, int val) {
		for(; pos < N; pos += pos & -pos)
			bit[pos] += val;
	}
	int qry(int pos) {
		int res = 0;
		for(; pos; pos -= pos & -pos)
			res += bit[pos];
		return res;
	}
}

int f[N], inv[N], fi[N];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}
void mul(int& a, int b) {
	a = int(1LL * a * b % M);
}

int cnt[N];

signed main()
{
	IO_OP;


	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = int((ll) f[i - 1] * i % M);
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - int((ll) M / i * inv[M % i] % M);
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = int((ll) fi[i - 1] * inv[i] % M);

	int n, m, cur = 1;
	cin >> n >> m;

	multiset<int> s;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		s.insert(x);

		bit::add(x, 1);
		mul(cur, f[cnt[x]]);
		cnt[x]++;
		mul(cur, fi[cnt[x]]);
	}
	int ans = 0;

	vi t(m);
	for(int i = 0; i < m; i++) cin >> t[i];

	for(int i = 0; i < m; i++) {
		if(s.empty()) {
			add(ans, 1);
			break;
		}
		debug(int(1LL * cur * bit::qry(t[i] - 1) % M * f[SZ(s) - 1] % M));
		add(ans, int(1LL * cur * bit::qry(t[i] - 1) % M * f[SZ(s) - 1] % M));

		if(s.find(t[i]) == s.end()) break;
		s.erase(s.find(t[i]));
		mul(cur, f[cnt[t[i]]]);
		cnt[t[i]]--;
		mul(cur, fi[cnt[t[i]]]);
		bit::add(t[i], -1);
	}
	cout << ans << '\n';	
}