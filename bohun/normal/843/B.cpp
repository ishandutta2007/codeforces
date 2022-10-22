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

const int N = 5e4 + 100;

int n, start, x;

int val[N];
int nex[N];

vector <int> f;
int ans = 2e9;

void q(int v) {
	printf ("? %d\n", v);
	fflush(stdout);
	int a, b;
	scanf ("%d%d", &a, &b);
	val[v] = a;
	nex[v] = b;
	if (a >= x) ans = min(ans, a);
}

void res() {
	if (ans != 2e9) printf ("! %d\n", ans);
	else printf ("! -1\n");
	fflush(stdout);
	exit(0);
}

int main() {	
	srand(1337);
	scanf ("%d%d%d", &n, &start, &x);
	vector <int> v;
	q(start);
	rep(i, 2, n) v.pb(i);
	random_shuffle(all(v));
	rep(i, 0, min(n - 2, 997)) q(v[i]);
		
	pair<int, int> best = {-1, 0};
	rep(i, 1, n) {
		if (val[i] == 0 && nex[i] == 0) continue;
		if (val[i] < x) best = max({best, {val[i], i}});
	}
	if (best.se == 0) res();
	int u = best.se;
	int T = 1000;
	while (T--) {
		q(u);
		if (nex[u] == -1) break;
		u = nex[u];
	}
	res();
		
		
	
	return 0;
}