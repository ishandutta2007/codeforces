#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 200 + 10;

int n, c[MAXN][MAXN];
ll tt[MAXN][MAXN], dd[MAXN][MAXN];
int par[MAXN][MAXN];
int p[MAXN];

void go(int l, int r, int pp = -1) {
	if (r-l <= 0) return;
	int rt = par[l][r];
	p[rt] = pp;
	go(l, rt, rt);
	go(rt+1, r, rt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j];
	
	for (int l = 0; l < n; l++) {
		ll sm = 0;
		for (int r = l; r < n; r++) {
			for (int i = 0; i < n; i++)
				if (i < l || i > r)
					sm += c[r][i];
				else
					sm -= c[r][i];
			tt[l][r+1] = sm;
		}
	}

	memset(dd, 63, sizeof(dd));
	for (int i = 0; i <= n; i++) dd[i][i] = 0;
	for (int l = n-1; ~l; l--)
		for (int r = l+1; r <= n; r++) {
			if (r-l == 1) {
				dd[l][r] = 0;
				par[l][r] = l;
			}
			else {
				ll best = 1e18;
				int ind = -1;
				for (int i = l; i < r; i++) {
					ll tmp = dd[l][i] + dd[i+1][r] + tt[l][i] + tt[i+1][r];
					if (tmp < best) {
						best = tmp;
						ind = i;
					}
				}
				dd[l][r] = best;
				par[l][r] = ind;
			}
		}

	go(0, n);

	for (int i = 0; i < n; i++)
		cout << p[i]+1 << " ";
	cout << "\n";
	return 0;
}