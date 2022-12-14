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

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vi a(n), vis(n);
	V<vi> from(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		from[a[i]].PB(i);
	}

	vi in(n);

	vi b = a;
	int cnt = 1;
	for(int i = 0; i < n; i++) if(!vis[i]) {
		int j = i;
		while(!vis[j]) {
			vis[j] = cnt;
			j = a[j];
		}
		if(vis[j] == cnt) {
			vi cycle;
			int k = j;
			while(true) {

				int u = k, v = a[k];
				in[v] = 1;
				for(int i:from[v]) if(i != u)
					b[i] = -1;

				k = a[k];
				if(k == j) break;
			}

		}
		cnt++;
	}
	function<int(int)> dfs = [&] (int u) {
		if(from[u].empty()) return u;
		int res = dfs(from[u][0]), lst = from[u][0];
		for(int i = 1; i < int(from[u].size()); i++) {
			b[lst] = dfs(from[u][i]);
			lst = from[u][i];
		}
		return res;
	};
	for(int i = 0; i < n; i++) if(b[i] == -1) {
		b[i] = dfs(i);
	}

	for(int i = 0; i < n; i++) if(in[i]) {
		int lst = -1;
		for(int j:from[i]) if(in[j]) {
			lst = j;
		}
		assert(lst != -1);
		for(int j:from[i]) if(!in[j]) {
			b[lst] = b[j];
			b[j] = i;
			lst = j;
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += a[i] == b[i];
	cout << ans << '\n';
	for(int i = 0; i < n; i++)
		cout << b[i] + 1 << ' ';
	cout << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}