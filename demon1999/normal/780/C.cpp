#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int ma = 128 * 1024;
const ll mod = ll(1e9) + 7;
const int N = 5 * 100 * 1000;

int n, cl[N], nm = 1;
vector<int> e[N];


void dfs(int nu, int pr, int c) {
	int nuk = 1;
	for (int v : e[nu]) {
		if (pr != v) {
			while (nuk == cl[nu] || nuk == c)
				nuk++;
			cl[v] = nuk;
			nuk++;
			dfs(v, nu, cl[nu]);
		}
	}
	nm = max(nm, cl[nu]);
}

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//reopen("a.in", "r", stdin);
	scanf("%d", &n);
	forn (i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cl[0] = 1;
	dfs(0, -1, -1);
	printf("%d\n", nm);
	forn (i, n)
		printf("%d ", cl[i]);
}