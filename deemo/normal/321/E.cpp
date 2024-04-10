#include<bits/stdc++.h>

using namespace std;

const int MAXN = 4e3 + 5;
const int MAXK = 800 + 4;

int n, k, a[MAXN][MAXN], d[MAXK][MAXN], p[MAXN][MAXN];

int get(int x, int y, int w){
	return d[w - 1][x] + p[y][x];
}

void solve(int l, int r, int tl, int tr, int w){
	if (r < l)	return;
	int mid = l+r>>1, opt = tl;
	for (int i = tl+1; i <= tr && i <= mid; i++)
		if (get(opt, mid, w) > get(i, mid, w))
			opt = i;
	
	d[w][mid] = get(opt, mid, w);
	solve(l, mid - 1, tl, opt, w);
	solve(mid + 1, r, opt, tr, w);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		string s;	getline(cin, s);
		if (!i)
			getline(cin, s);
		for (int j = 0, cnt = 0; cnt < n; j += 2, cnt++)
			a[i][cnt + 1] = a[i][cnt] + int(s[j] - '0');
	}
	
	for (int i = 1; i <= n; i++){
		int cur = 0;
		for (int j = i-2; j >= 0; j--){
			cur += a[j][i] - a[j][j];
			p[i][j] = cur;
		}
	}

	memset(d, 63, sizeof(d));
	d[0][0] = 0;
	for (int w = 1; w <= k; w++)
		solve(0, n, 0, n, w);

	cout << d[k][n] << "\n";
	return 0;
}