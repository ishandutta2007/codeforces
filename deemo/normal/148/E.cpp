#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 100 + 2;
const int MAXM = 1e4 + 2;

int n, m, val[MAXN], sec[MAXN], p[MAXN], xx[MAXN], d[MAXN][MAXN];
int f[2][MAXM];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int t;	cin >> t;
		for (int j = 0; j < t; j++)	cin >> val[j];
		for (int j = 0; j < t; j++)
			p[j + 1] = p[j] + val[j];

		for (int j = 1; j <= t; j++)
			for (int w = 0; w <= j; w++)
				d[i][j] = max(d[i][j], p[w] + (p[t] - p[t - (j - w)]));
		xx[i] = t;
	}

	bool cur = 0;
	for (int i = 0; i < n; i++, cur = !cur)
		for (int j = 0; j < MAXM; j++)
			for (int w = 0; w <= j && w <= xx[i]; w++)
				f[!cur][j] = max(f[!cur][j], f[cur][j - w] + d[i][w]);
	printf("%d\n", f[cur][m]);
	return 0;
}