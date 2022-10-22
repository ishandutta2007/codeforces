#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define cat(x) cerr << #x << " = " << x << endl
#define fi first
#define se second
#define ss(x) (int) x.size()

using namespace std;

const int nax = 2010;
const int mod = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int n, m;
char s[nax][nax];

int Down[nax][nax];
int Right[nax][nax];

struct fen {
	int f[nax];
	
	void init() {
		for (int i = 0; i < nax; ++i)
			f[i] = 0;
	}
	
	void add2(int x, int c) {
		for (; x < nax; x += x & -x) 
			add(f[x], c);
	}
	
	int query(int x) {
		int res = 0;
		for (; 0 < x; x -= x & -x)
			add(res, f[x]);
		return res;
	}
	
	void addpoint(int l, int r, int c) {
		if (l > r) return;
		add2(l, c);
		add2(r + 1, -c + mod);
	}
} row[nax], col[nax];

int main() {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%s", s[i] + 1);
	}
	
	if (n == 1 && m == 1) {
		printf ("1\n");
		return 0;
	}
	
	for (int i = 1; i <= max(n, m); ++i) {
		row[i].init();
		col[i].init();
	}
	
	for (int i = n - 1; 1 <= i; --i)
		for (int j = 1; j <= m; ++j)
			Down[i][j] = Down[i + 1][j] + (s[i + 1][j] == 'R');
			
	for (int i = 1; i <= n; ++i)
		for (int j = m - 1; 1 <= j; --j)
			Right[i][j] = Right[i][j + 1] + (s[i][j + 1] == 'R');
			
	row[1].addpoint(1, 1, 1);
	col[1].addpoint(1, 1, 1);
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int Left = row[i].query(j);
			int Up = col[j].query(i);
			
			col[j].addpoint(i + 1, n - Down[i][j], Left);
			row[i].addpoint(j + 1, m - Right[i][j], Up);
		}
	printf ("%d\n", (row[n].query(m) + col[m].query(n)) % mod);
			
			
	
	return 0;
}