#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 1005;
const int M = 1e9+7;
int g[N][N] = {};

void mark(int i, int j, int v) {
	if(v != 0 && g[i][j] != 0 && g[i][j] != v) {
		cout << "0\n";
		exit(0);
	}
	g[i][j] = v;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int h, w;
	cin >> h >> w;
	for(int i = 0; i < h; ++i) {
		int r;
		cin >> r;
		for(int j = 0; j < r; ++j)
			mark(i, j, 1);
		mark(i, r, 2);
	}

	for(int j = 0; j < w; ++j) {
		int c;
		cin >> c;
		for(int i = 0; i < c; ++i)
			mark(i, j, 1);
		mark(c, j, 2);
	}

	int ans = 1;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(g[i][j] == 0) {
				ans = (ans * 2) % M;
			}
		}
	}
	cout << ans << '\n';
}