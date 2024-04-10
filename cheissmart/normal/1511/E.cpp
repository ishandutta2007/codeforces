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

const int INF = 1e9 + 7, N = 3e5 + 7, M = 998244353;

int pw[N], aux[N];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;

	pw[0] = 1;
	for(int i = 1; i < N; i++) pw[i] = pw[i - 1] * 2 % M;

	int n, m, free = 0;
	cin >> n >> m;
	V<string> a(n, string(m, ' '));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'o') free++;
		}

	for(int i = 1; i <= free; i += 2) aux[i] = pw[free - i];
	for(int i = 1; i <= free; i++) add(aux[i], aux[i - 1]);

	int ans = 0;

	auto go = [&] () {
		for(int i = 0; i < n; i++) {
			int pre = 0;
			for(int j = 0; j + 1 < m; j++) {
				if(a[i][j] != 'o') {
					pre = 0;
					continue;
				}
				if(a[i][j + 1] == 'o') {
					if(pre > 0) {
						int l = 3, r = pre + 2;
						if(r % 2 == 0) r--;
						add(ans, aux[r]);
						add(ans, M - aux[l - 1]);
						debug(i, j, pre, aux[r] - aux[l - 1]);
					}
					if(pre % 2 == 0) {
						add(ans, pw[free - 2 - pre]);
						debug(i, j, pw[free - 2 - pre]);
					}
				}
				pre++;
			}
		}
	};

	for(int _ = 0; _ < 2; _++) {
		debug(_);
		go();
		swap(n, m);
		V<string> aa(n, string(m, ' '));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				aa[i][j] = a[j][i];
		swap(a, aa);
	}

	cout << ans << '\n';

}