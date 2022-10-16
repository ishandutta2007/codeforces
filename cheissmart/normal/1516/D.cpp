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

void DBG() { cerr << "]" << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N], nxt[N][20], lst[N];

signed main()
{
	IO_OP;

	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];

	memset(lst, 0x3f, sizeof lst);
	nxt[n][0] = n;
	int r = n;
	for(int i = n - 1; i >= 0; i--) {
		int x = a[i];
		auto go = [&] (int j) {
			r = min(r, lst[j]);
			lst[j] = i;
		};
		for(int j = 2; j * j <= x; j++) {
			if(x % j == 0) {
				while(x % j == 0) x /= j;
				go(j);
			}
		}
		if(x != 1) go(x);
		nxt[i][0] = r;
	}
	for(int j = 1; j < 20; j++)
		for(int i = 0; i <= n; i++) if(nxt[i][j - 1]) 
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];

	while(q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		int ans = 0;
		for(int i = 19; i >= 0; i--) {
			if(nxt[l][i] <= r) {
				ans |= 1 << i;
				l = nxt[l][i];
			}
		}
		cout << ans + 1 << '\n';
	}

}