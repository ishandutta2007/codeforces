#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2e5 + 100;
const int LOG = 17;

int T;
int n;
int p[N];
int c[N];
int d[N][LOG + 1];
bool odw[N];
int e[N];

vector <int> divi[N];

int g() {
	int best = 101010101;
	rep(i, 1, n) odw[i] = 0;
	rep(i, 1, n) {
		if (odw[i]) continue;
		int v = i;
		vector <int> nodes;
		while (!odw[v]) {
			nodes.pb(v);
			odw[v] = 1;
			v = d[v][0];
		}
		for (auto D : divi[ss(nodes)]) {
			if (best <= D) continue;
			for (auto it : nodes) {
				int f = it;
				rep(j, 0, LOG)
					if ((D >> j) & 1) f = d[f][j];
				e[it] = f;
			}
			//for (auto it : nodes) printf ("%d %d   ", it, e[it]	);
			//printf ("\n");
			for (auto it : nodes) odw[it] = 0;
			for (auto xd : nodes) {
				if (odw[xd]) continue;
				int v = xd;
				bool bad = 0;
				while (!odw[v]) {
					odw[v] = 1;
					if (c[v] != c[e[v]]) {
						bad = 1;
					} 
					v = e[v];
				}
				if (!bad) {
					best = min(best, D);
					break;
				}
			}
		}		
		for (auto it : nodes) odw[it] = 1;		
	}
	return best;
}
	
void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", p + i);
		d[i][0] = p[i];
	}
	rep(i, 1, n) scanf ("%d", c + i);
	rep(j, 1, LOG)
		rep(i, 1, n)
			d[i][j] = d[d[i][j - 1]][j - 1];
	printf ("%d\n", g());
}

int main() {
	rep(i, 1, N - 1)
		for (int j = i; j < N; j += i)
			divi[j].pb(i);
	scanf ("%d", &T);
	while (T--) solve();
	

	return 0;
}