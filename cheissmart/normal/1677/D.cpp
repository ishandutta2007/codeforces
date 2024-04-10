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

const int INF = 1e9 + 7, M = 998244353;

void mul(int& a, int b) {
	a = int(1LL * a * b % M);
}
void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

int solve() {
	int n, k;
	cin >> n >> k;
	vi v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = 0; i < k; i++)
		if(v[n - 1 - i] != 0 && v[n - 1 - i] != -1)
			return 0;

	int ways = 1;
	for(int i = 0; i < k; i++)
		mul(ways, i + 1);
	for(int i = 0; i < n - k; i++) {
		if(v[i] == -1) {
			mul(ways, i + k + 1);
		} else if(v[i] == 0) {
			mul(ways, k + 1);
		}
	}
	return ways;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		cout << solve() << '\n';

}