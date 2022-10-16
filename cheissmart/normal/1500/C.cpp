#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1505;

V<pi> G[N];
int can[N], ok[N], used[N];

signed main()
{
	IO_OP;
		
	int n, m;
	cin >> n >> m;
	V<vi> a(n, vi(m)), b(n, vi(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> b[i][j];
	{
		auto a_tmp = a;
		auto b_tmp = b;
		sort(ALL(a_tmp)), sort(ALL(b_tmp));
		if(a_tmp != b_tmp) {
			cout << -1 << '\n';
			return 0;
		}
	}
	if(n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m; j++) {
			if(b[i][j] == b[i + 1][j]) {
				can[j]++;
				G[j].EB(i, 0);
			} else if(b[i][j] < b[i + 1][j]) {
				can[j]++;
				G[j].EB(i, 1);
			}
		}
	}
	int need = n - 1;
	vi ans;
	while(true) {
		int c = -1;
		for(int j = 0; j < m; j++) if(!used[j] && can[j] == need) {
			c = j;
			break;
		}
		if(c == -1) break;
		used[c] = 1;
		ans.PB(c);
		for(pi p:G[c]) {
			if(!ok[p.F]) {
				if(p.S == 1) {
					ok[p.F] = 1;
					int i = p.F;
					for(int j = 0; j < m; j++) {
						if(b[i][j] == b[i + 1][j]) {
							can[j]--;
						} else if(b[i][j] < b[i + 1][j]) {
							can[j]--;
						}
					}
					need--;
				}
			}
		}
	}
	V<vi> c(n, vi(int(ans.size()) + 1));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < int(ans.size()); j++) {
			c[i][j] = a[i][ans[j]];
		}
		c[i][int(ans.size())] = i;
	}
	sort(ALL(c));
	for(int i = 0; i < n; i++) {
		int j = c[i].back();
		if(a[j] != b[i]) {
			cout << -1 << '\n';
			return 0;
		}
	}
	reverse(ALL(ans));
	cout << ans.size() << '\n';
	for(int i:ans) cout << i + 1 << ' ';

}