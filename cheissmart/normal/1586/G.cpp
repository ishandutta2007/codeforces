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

const int INF = 1e9 + 7, N = 4e5 + 7, M = 1e9 + 7;

void madd(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

int bit[N];

void add(int pos, int val) {
	for(; pos < N; pos += pos & -pos)
		madd(bit[pos], val);
}

int qry(int pos) {
	int res = 0;
	for(; pos; pos -= pos & -pos)
		madd(res, bit[pos]);
	return res;
}

int p[N], dp[N], a[N], b[N], vis[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		p[b[i]] = a[i];
	}
	for(int i = 1; i <= n * 2; i++) {
		if(p[i]) {
			dp[i] = (1LL + qry(2 * n) - qry(p[i]) + M) % M;
			add(p[i], dp[i]);
		}
	}
	int t;
	cin >> t;
	vi s(t);
	for(int i = 0; i < t; i++) {
		cin >> s[i];
		s[i] = b[s[i]];
		vis[s[i]] = 1;
	}
	sort(ALL(s));
	int ans = 0;
	for(int i = 1; i <= s.back(); i++)
		madd(ans, dp[i]);
	int l = p[s.back()];
	for(int i = s.back() - 1; i > l; i--) {
		if(p[i]) {
			if(p[i] < l) continue;
			if(vis[i]) {
				l = p[i];
			} else {
				madd(ans, M - dp[i]);
			}
		}
	}

	cout << ans << '\n';
}