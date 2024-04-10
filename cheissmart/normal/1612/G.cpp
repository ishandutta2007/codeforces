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

const int INF = 1e9 + 7, M = 1e9 + 7, N = 1e6 + 7;

int f[N], inv[N], fi[N];

void add(int& a, int b) {
	a += b;
	if(a >= M)
		a -= M;
}

int* aux;
int _aux[N * 2];

signed main()
{
	aux = _aux + N;

	IO_OP;
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (ll) f[i - 1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - (ll) M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = (ll) fi[i - 1] * inv[i] % M;

	int m;
	cin >> m;

	for(int i = 0; i < m; i++) {
		int c;
		cin >> c;
		c--;
		aux[-c]++;
		aux[c + 2]--;
	}

	int ans2 = 0, ans = 1, cnt = 0;
	for(int i = -N + 4; i < N; i++) {
		aux[i] += aux[i - 2];
		ans = int(1LL * ans * f[aux[i]] % M);
		int sum_pos = int((2LL * cnt + 1 + aux[i]) * aux[i] / 2 % M); 
		add(ans2, int(1LL * (i + M) * sum_pos % M));
		add(cnt, aux[i]);
	}
	cout << ans2 << ' ' << ans << '\n';;

}