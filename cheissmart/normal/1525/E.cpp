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

const int INF = 1e9 + 7, M = 998244353;

int a[20][500004];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}
void mul(int& a, int b) {
	a = (ll) a * b % M;
}
int inv(int i) {
	if(i == 1) return 1;
	return M - (ll) M / i * inv(M % i) % M;
}

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	int ans = 0, f = 1;
	for(int i = 1; i <= n; i++)
		mul(f, i);
	for(int i = 0; i < m; i++) {
		vi aux;
		for(int j = 0; j < n; j++)
			aux.PB(a[j][i]);
		sort(ALL(aux));
		int ways = 1;
		for(int j = 0; j < n; j++) {
			mul(ways, max(0, aux[j] - 1 - j));
		}
		add(ans, f);
		add(ans, M - ways);
	}
	mul(ans, inv(f));
	cout << ans << '\n';
}