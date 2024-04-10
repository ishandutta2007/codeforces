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

const int INF = 1e9 + 7, N = 2e5 + 7;

int p[N], st[N][20];

signed main()
{
	IO_OP;

	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		p[x]++;
	}

	for(int i = 1; i <= m; i++) p[i] += p[i - 1];
	for(int j = 0; j < 20; j++) {
		for(int i = m - (1 << j); i >= 1; i--) {
			int l = i + (1 << j), r = min(l + (1 << j) - 1, m);
			st[i][j] = p[r] - p[l - 1];
			if(r + 1 <= m) st[i][j] += st[r + 1][j];
		}
	}

	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		r++;
		char ans = 'B';
		auto go = [&] (int bit) {
			int cnt = st[l][bit];
			if(r > m) return cnt;
			int r_block = (r - l) >> bit;
			int r_end = min(l + ((r_block + 1) << bit) - 1, m);
			if((r - l) >> bit & 1) cnt -= p[r_end] - p[r - 1];
			r_end++;
			if(r_end > m) return cnt;
			if((r_end - l) >> bit & 1) {
				int rb = min(r_end + (1 << bit) - 1, m);
				cnt -= p[rb] - p[r_end - 1];
				r_end = rb + 1;
			}
			if(r_end > m) return cnt;
			cnt -= st[r_end][bit];
			return cnt;
		};
		for(int i = 0; i < 20; i++) {
			if(go(i) & 1) {
				ans = 'A';
				break;
			}
		}
		cout << ans;
	}


}