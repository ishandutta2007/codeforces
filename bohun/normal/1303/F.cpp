#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl

using namespace std;

const int N = 2 * 1e6 + 111;

int p[N];
int ilosc;

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

void unia(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		p[x] = y;
		ilosc--;
	}
}

int n, m, q;
int t[311][311];
int e[311][311];

struct gao {
	int r, c, t;
};

vector <gao> v[N];
vector <gao> del[N];

int ans[N];
int last[N];

int id(int r, int c) {
	return r * m + c;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in(int r, int c) {
	return 0 <= r && r < n && 0 <= c && c < m;
}

void add(int l, int r, int c) {
	if (l > r) return;
	ans[l] += c;
	ans[r + 1] -= c;
}

int main() {
	scanf ("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= q; ++i) {
		int a, b, c;
		scanf ("%d %d %d", &a, &b, &c);
		a--;
		b--;
		if (t[a][b] != c)
			del[t[a][b]].pb({a, b, i});
		t[a][b] = c;
		v[c].pb({a, b, i});
		last[c] = i;
	} 
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			del[t[i][j]].pb({i, j, q + 1});
	
	for (int color = 0; color < N; ++color) {
		for (auto it : v[color]) {
			p[id(it.r, it.c)] = id(it.r, it.c);
			e[it.r][it.c] = -1;
		}
		
		ilosc = 0;
		for (auto it : v[color]) {
			if (e[it.r][it.c] == color) {
				add(it.t, it.t, ilosc);
				continue;
			}
			ilosc++;
			for (int g = 0; g < 4; ++g) {
				int nr = it.r + dx[g];
				int nc = it.c + dy[g];
				if (in(nr, nc) && e[nr][nc] == color)
					unia(id(nr, nc), id(it.r, it.c));
			}
			e[it.r][it.c] = color;
			add(it.t, it.t, ilosc);
		}
		
		for (auto it : del[color]) {
			p[id(it.r, it.c)] = id(it.r, it.c);
			e[it.r][it.c] = -1;
		}
		
		ilosc = 0;
		for (int i = ss(del[color]) - 1; 0 <= i;) {
			int j = i;
			while (0 <= j && del[color][i].t == del[color][j].t) {
				ilosc++;
				int row = del[color][j].r;
				int col = del[color][j].c;
				for (int g = 0; g < 4; ++g) {
					int nr = row + dx[g];
					int nc = col + dy[g];
					if (in(nr, nc) && e[nr][nc] == color)
						unia(id(nr, nc), id(row, col));
				}
				e[row][col] = color;
				j--;
			}
			if (j == -1) add(last[color] + 1, del[color][i].t - 1, ilosc);
			else add(del[color][j].t, del[color][i].t - 1, ilosc);
			i = j;
		}
		
	}
	
	for (int i = 1; i <= q; ++i) {
		ans[i] += ans[i - 1];
		printf ("%d\n", ans[i]);
	}
	
	return 0;
}