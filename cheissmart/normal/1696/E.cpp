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

const int INF = 1e9 + 7, M = 1e9 + 7, N = 4e5 + 7;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}
int ad(int a, int b) {
	add(a, b);
	return a;
}
int mu(int a, int b) {
	return int(1LL * a * b % M);
}
int mul(int& a, int b) {
	a = mu(a, b);
}

int f[N], fi[N], inv[N];

int C(int n, int k) { return mu(f[n], mu(fi[k], fi[n - k])); }

signed main()
{
	IO_OP;

	f[0] = 1;
	for(int i = 1; i < N; i++)
		f[i] = mu(f[i - 1], i);
	inv[1] = 1;
	for(int i = 2; i < N; i++)
		inv[i] = M - mu(M / i, inv[M % i]);
	fi[0] = 1;
	for(int i = 1; i < N; i++)
		fi[i] = mu(fi[i - 1], inv[i]);

	int n; cin >> n;

	int ans = 0;

	for(int i = 0; i <= n; i++) {
		int x; cin >> x;
		if(x) add(ans, C(i + x, i + 1));
	}

	cout << ans << '\n';

}