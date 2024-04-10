#include <bits/stdc++.h>
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define cat(x) cerr << #x << " = " << x << endl
#define ss(x) (int) x.size()
using ll = long long;

using namespace std;

const int N = 1e6 + 101;
const int M = 1e6;

int F[N];

void add(int x, int del) {
	x++;
	for (; x < N; x += x & -x)
		F[x] += del;
}

int qw(int x) {
	x++;
	int res = 0;
	for (; x; x -= x & -x)
		res += F[x];
	return res;
}

int n, m;
ll out = 1;

vector <int> up[N], down[N], le[N], ri[N], del[N];

int main() {
	scanf ("%d%d", &n, &m);
	
	for (int i = 1; i <= n; ++i) {
		int y, xl, xr;
		scanf ("%d%d%d", &y, &xl, &xr);
		if (xl == 0 && xr == M) out++;
		if (xl == 0) le[y].pb(xr);
		else ri[y].pb(xl);
	}
		
	for (int i = 1; i <= m; ++i) {
		int x, ly, ry;
		scanf ("%d%d%d", &x, &ly, &ry);
		if (ly == 0 && ry == M) out++;
		
		if (ly == 0) up[x].pb(ry);
		else down[x].pb(ly);
	}	
		
	for (int i = 0; i <= M; ++i) {
		add(i, ss(down[i]));
		for (auto u : down[i])
			del[u - 1].pb(i);
	}
		
	for (int i = M; 0 <= i; --i) {
		for (auto u : del[i])
			add(u, -1);
		for (auto u : le[i]) {
			out += qw(u);
			//cout << u << " aa " << qw(u) << endl;
		}
		for (auto u : ri[i]) {
			out += qw(N - 2) - qw(u - 1);
			//cout << u << " aa " << qw(N - 1) - qw(u - 1) << endl;
		}
	}
		
	for (int i = 0; i <= M; ++i) del[i].clear();
	
	for (int i = 0; i <= M; ++i) {
		add(i, ss(up[i]));
		for (auto u : up[i])
			del[u + 1].pb(i);
	}	
	
	for (int i = 0; i <= M; ++i) {
		for (auto u : del[i])
			add(u, -1);
		for (auto u : le[i])
			out += qw(u);
		for (auto u : ri[i])
			out += qw(N - 2) - qw(u - 1);
	}
		
	printf ("%lld\n", out);
	
	return 0;
}