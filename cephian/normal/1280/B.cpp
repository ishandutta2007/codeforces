#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 65;
int r, c;
string g[N];

inline bool all(int x, int y, int dx, int dy) {
	bool ok = true;
	while(x < r && y < c) {
		ok &= g[x][y] == 'A';
		x += dx, y += dy;
	}
	return ok;
}

int solve() {
	cin >> r >> c;
	int cnt_a = 0;
	for(int i = 0; i < r; ++i) {
		cin >> g[i];
		for(char c : g[i])
			cnt_a += c == 'A';
	}
	if(cnt_a == 0) return -1;
	if(cnt_a == r*c) return 0;

	if(all(0,0,1,0) || all(0,0,0,1) || all(0,c-1,1,0) || all(r-1,0,0,1)) {
		return 1;
	}
	if(g[0][0] =='A' ||
			g[0][c-1] == 'A' ||
			g[r-1][0] == 'A' ||
			g[r-1][c-1] == 'A') {
		return 2;
	}
	for(int i = 0; i < r; ++i) {
		if(all(i, 0, 0, 1))
			return 2;
	}
	for(int i = 0; i < c; ++i) {
		if(all(0, i, 1, 0))
			return 2;
	}
	for(int i = 0; i < r; ++i)
		if(g[i][0] == 'A' || g[i][c-1] == 'A')
			return 3;
	for(int j = 0; j < c; ++j)
		if(g[0][j] == 'A' || g[r-1][j] == 'A')
			return 3;
	return 4;
}


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int ans = solve();
		if(ans == -1) cout << "MORTAL\n";
		else cout << ans << '\n';
	}


}