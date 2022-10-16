#include <iostream>
#include <cstring>
#include <random>
#include <ctime>
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

const int INF = 1e9 + 7, N = 21;
const int M = 31607;

int inv[M];
int a[N][N], vis[N][N], r[N];
int n, ans;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

void dfs(int i, int p, bool parity) {
	if(i == n + 2) {
		int mul = p;
		for(int j = 0; j < n; j++)
			mul = mul * (1 + M - r[j]) % M;
		if(parity) add(ans, M - mul);
		else add(ans, mul);
		return;
	}
	dfs(i + 1, p, parity);
	auto mark = [&] (int i, int j) {
		if(vis[i][j] == 0) {
			r[i] = r[i] * inv[a[i][j]] % M;
			p = p * a[i][j] % M;
		}
		vis[i][j]++;
	};
	auto unmark = [&] (int i, int j) {
		vis[i][j]--;
		if(vis[i][j] == 0)
			r[i] = r[i] * a[i][j] % M;
	};
	if(i < n) {
		for(int j = 0; j < n; j++)
			mark(j, i);
	} else if(i == n) {
		for(int j = 0; j < n; j++)
			mark(j, j);
	} else if(i == n + 1) {
		for(int j = 0; j < n; j++)
			mark(j, n - 1 - j);
	}
	dfs(i + 1, p, parity ^ 1);
	if(i < n) {
		for(int j = 0; j < n; j++)
			unmark(j, i);
	} else if(i == n) {
		for(int j = 0; j < n; j++)
			unmark(j, j);
	} else if(i == n + 1) {
		for(int j = 0; j < n; j++)
			unmark(j, n - 1 - j);
	}
}

signed main()
{
	IO_OP;

	inv[1] = 1;
	for(int i = 2; i < M; i++)
		inv[i] = M - M / i * inv[M % i] % M;

	cin >> n;
	for(int i = 0; i < n; i++) {
		r[i] = 1;
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j] = a[i][j] * inv[10000] % M;
			r[i] = r[i] * a[i][j] % M;
		}
	}

	dfs(0, 1, 0);

	ans = (M + 1 - ans) % M;

	cout << ans << '\n';

}