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

const int INF = 1e9 + 7, M = 998244353, N = 1e6 + 7;

int f[N], inv[N], fi[N];

int C(int n, int k) {
    assert(n < N); assert(k <= n);
	return (ll) f[n] * fi[k] % M * fi[n - k] % M;
}

int H(int n, int k) {
	return C(n + k - 1, k);
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;

	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (ll) f[i - 1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - (ll) M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = (ll) fi[i - 1] * inv[i] % M;

	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		if(count(ALL(s), '0') == 0) {
			cout << 1 << '\n';
			continue;
		}
		int lst = -1, unk = 1, sum = n;
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') {
				int len = i - lst - 1;
				unk++;
				sum--;
				if(len & 1) sum--;
				lst = i;
			}
		}
		sum /= 2;
		assert(sum >= 0);
		cout << H(unk, sum) << '\n';
	}

}