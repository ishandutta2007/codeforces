#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 3;
const int INF = 1e5;

int n, a[MAXN], ans, d[256][MAXN], p[8][MAXN], l[8][MAXN], tl[8][MAXN];

bool ok(int mid){
	memset(l, -1, sizeof(l));
	memset(tl, -1, sizeof(tl));
	for (int w = 0; w < 8; w++){
		int cur = 0;
		for (int i = 1; i <= n; i++)
			if (p[w][i] >= mid){
				while (cur <= i && p[w][i] - p[w][cur] >= mid)	cur++;
				l[w][i] = cur-1;
			}
		cur = 0;
		for (int i = 1; i <= n; i++)
			if (p[w][i] >= mid+1){
				while (cur <= i && p[w][i] - p[w][cur] >= mid+1)	cur++;
				tl[w][i] = cur-1;
			}
	}
	memset(d, -10, sizeof(d));
	d[0][0] = 0;
	if (!mid)
		for (int i = 1; i < 256; i++)
			d[i][0] = 0;
	for (int i = 1; i <= n; i++){
		d[0][i] = 0;
		for (int mask = 1; mask < 256; mask++){
			int t = __builtin_popcount(mask);
			if (t * mid > i)	continue;
			for (int w = 0; w < 8; w++)
				if (mask>>w&1){
					if (~l[w][i])
						d[mask][i] = max(d[mask][i], mid+d[mask^1<<w][l[w][i]]);
					if (~tl[w][i])
						d[mask][i] = max(d[mask][i], mid+1+d[mask^1<<w][tl[w][i]]);
				}
		}
	}
	ans = max(ans, d[255][n]);
	return d[255][n] >= 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (int i = 0; i < n; i++)	cin >> a[i], a[i]--;
	for (int w = 0; w < 8; w++)
		for (int i = 0; i < n; i++)
			p[w][i + 1] = p[w][i] + (a[i]==w);
	int lo = -1, hi = n/8 + 1;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (ok(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << ans << endl;
	return 0;
}