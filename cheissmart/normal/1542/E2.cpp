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

const int INF = 1e9 + 7, N = 505;

int C[N][N], f[N];

signed main()
{
	IO_OP;

	int n, M;
	cin >> n >> M;
	if(M == 1) return cout << 0 << '\n', 0;

	auto add = [&] (int& a, int b) {
		assert(b >= 0);
		assert(b <= M);
		a += b;
		if(a >= M) a -= M;
	};

	for(int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
	}
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		f[i] = (ll) f[i - 1] * i % M;

	int ans = 0;

	vi ways({1});
	for(int k = 2; k <= n; k++) {
		vi aux1 = ways;
		for(int i = 1; i < int(aux1.size()); i++)
			add(aux1[i], aux1[i - 1]);
		vi aux2 = aux1;
		for(int i = 0; i < int(aux2.size()); i++)
			aux2[i] = (ll) aux2[i] * i % M;
		for(int i = 1; i < int(aux1.size()); i++)
			add(aux1[i], aux1[i - 1]);
		for(int i = 1; i < int(aux2.size()); i++)
			add(aux2[i], aux2[i - 1]);
		int to_add = 0;
		for(int i = 2; i < int(ways.size()); i++) {
			int lb = i - min(i, k), rb = i - 2;
			assert(lb <= rb);
			int tt = 0;
			add(tt, aux2[rb]);
			if(lb) add(tt, M - aux2[lb - 1]);
			int mul = (M + (k - i + 1) % M) % M;
			add(tt, (ll) aux1[rb] * mul % M);
			if(lb) add(tt, M - (ll) aux1[lb - 1] * mul % M);
			add(to_add, (ll) tt * ways[i] % M);
		}
		add(ans, (ll) to_add * C[n][k] % M * f[n - k] % M);

		vi nways(k * (k - 1) / 2 + 1);
		for(int i = 0; i < int(ways.size()); i++) {
			add(nways[i], ways[i]);
			if(i + k < int(nways.size()))
				add(nways[i + k], M - ways[i]);
		}
		for(int i = 1; i < int(nways.size()); i++)
			add(nways[i], nways[i - 1]);
		swap(ways, nways);
	}

	cout << ans << '\n';

}