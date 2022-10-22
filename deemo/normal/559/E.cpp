#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 100 + 5;
const int INF = 1e9 + 5;

int n, sec[3 * MAXN], sz, d[3 * MAXN][3 * MAXN][MAXN];
int tl[MAXN], tmid[MAXN], tr[MAXN];
pair<int, int>	p[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p[i].F >> p[i].S;
		sec[sz++] = p[i].F, sec[sz++] = p[i].F - p[i].S, sec[sz++] = p[i].F + p[i].S;
	}
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		tl[i] = lower_bound(sec, sec + sz, p[i].F - p[i].S) - sec, tmid[i] = lower_bound(sec, sec + sz, p[i].F) - sec, tr[i] = lower_bound(sec, sec + sz, p[i].F + p[i].S) - sec;

	for (int i = 0; i < 3 * MAXN; i++)
		for (int j = 0; j < 3 * MAXN; j++)
			for (int w = 0; w < MAXN; w++)
				d[i][j][w] = -INF;

	d[0][0][0] = 0;
	for (int i = 0; i < sz - 1; i++)
		for (int j = 0; j < sz; j++)
			for (int w = 0; w <= n; w++){
				d[i + 1][j][w] = max(d[i + 1][j][w], d[i][j][w]);
				if (j > i)
					d[j][j][w] = max(d[j][j][w], d[i][j][w] + (sec[j] - sec[i]));

				if (w < n && tmid[w] <= i)	
					d[i][max(j, tr[w])][w + 1] = max(d[i][max(j, tr[w])][w + 1], d[i][j][w]);

				int mx = j;
				for (int c = w; c < n; c++){
					if (tmid[c] > i && tl[c] <= i)
						d[tmid[c]][mx][c + 1] = max(d[tmid[c]][mx][c + 1], d[i][j][w] + sec[tmid[c]] - sec[i]);
					mx = max(mx, tr[c]);
				}
			}

	int ans = 0;
	for (int i = 0; i < 3 * MAXN; i++)
		for (int j = 0; j < 3 * MAXN; j++)
			for (int w = 0; w < MAXN; w++)
				ans = max(ans, d[i][j][w]);

	cout << ans << "\n";
	return 0;
}