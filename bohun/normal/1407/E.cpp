#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

const int N = 5e5 + 100;

int n, m;
vector <pair<int, int>> in[N];
int color[N];
bool done[N];
int cnt[N][2];

int main() {
	scanf ("%d%d", &n, &m);	
	rep(i, 1, m) {
		int u, v, w;
		scanf ("%d%d%d", &v, &u, &w);
		in[u].pb({v, w});
	}
	rep(i, 1, n) color[i] = -1;
	color[n] = 0;
	vector <int> a = {n};
	int dis = -1;
	while (true) {
		++dis;
		if (a.empty()) {
			printf ("-1\n");
			rep(i, 1, n) printf ("%d", max(0, color[i]));
			return 0;
		}
		vector <int> b;
		for (auto v : a) done[v] = true;
		
		if (done[1]) break;
		
		for (auto v : a)
			for (auto [u, w] : in[v]) {
				if (done[u]) continue;
				cnt[u][w]++;
				b.pb(u);
			}
		
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		
		vector <int> c;
		for (auto u : b) {
			if (color[u] == -1) {
				if (cnt[u][0] && cnt[u][1]) {
					c.pb(u);
					color[u] = 0;
				}
				else {
					color[u] = (cnt[u][0] ? 1 : 0);
				}
			}
			else {
				if (cnt[u][color[u]]) 
					c.pb(u);
			}
			cnt[u][0] = cnt[u][1] = 0;
		}
		a = c;
	}
	printf ("%d\n", dis);
	rep(i, 1, n) printf ("%d", max(0, color[i]));
	
		
	return 0;
}