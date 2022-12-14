#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2003;

int c[N];
int val[N];
vi G[N];

V<pi> dfs(int u) {
	V<pi> x;
	int mx = 0;
	for(int v:G[u]) {
		V<pi> y = dfs(v);
		if(y[0].F <= mx) {
			int add = mx - y[0].F + 1;
			for(pi& p:y) {
				p.F += add;
				val[p.S] += add;
			}
		}
		for(pi e:y) mx = max(mx, e.F);
		x.insert(x.end(), y.begin(), y.end());
	}
	sort(ALL(x));
	if(c[u] > (int)x.size()) {
		cout << "NO" << endl;
		exit(0);
	}
	if(c[u]) {
		val[u] = x[c[u]-1].F + 1;
		for(int i=c[u];i<(int)x.size();i++) {
			x[i].F++;
			val[x[i].S]++;
		}
	} else {
		val[u] = 1;
		for(pi&p:x) {
			p.F++;
			val[p.S]++;
		}
	}
	x.EB(val[u], u);
	sort(ALL(x));
	return x;
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	int s;
	for(int i=1;i<=n;i++){
		int p;
		cin >> p;
		G[p].PB(i);
		if(p == 0) s = i;
		cin >> c[i];
	}
	dfs(s);
	cout << "YES" << endl;
	for(int i=1;i<=n;i++)
		cout << val[i] << " \n"[i == n];
}