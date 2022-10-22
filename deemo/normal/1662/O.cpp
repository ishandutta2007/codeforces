#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using ll = long long;

const char nl = '\n';
const int MX = 50;
const int A = 720;

int vis[MX][A];

void addCircle() {
	int r, t[2];
	cin >> r;
	r *= 2;
	for(int i = 0; i < 2; i++) {
		cin >> t[i];
		t[i] *= 2;
	}
	for(int x = t[0]; x != t[1]; x = (x + 1) % A) {
		vis[r][x] = 2;
	}
}

void addLine() {
	int r[2], t;
	cin >> r[0] >> r[1] >> t;
	r[0] *= 2; r[1] *= 2; t *= 2;
	for(int x = r[0]; x <= r[1]; x++) {
		vis[x][t] = 2;
	}
}

void solve() {
	memset(vis, 0, sizeof(vis));
	int n;
	cin >> n;
	while(n--) {
		char ch;
		cin >> ch;
		if(ch == 'C') {
			addCircle();
		} else {
			addLine();
		}
	}
	queue<pair<int,int>> qu;
	qu.push({0, 0});
	vis[0][0] = 1;
	while(sz(qu)) {
		auto [x, y] = qu.front(); qu.pop();
		for(int dx = -1; dx <= 1; dx++) {
			if(x + dx >= 0 && x + dx < MX) {
				int r = x + dx;
				int c = y;
				if(!vis[r][c]) {
					vis[r][c] = 1;
					qu.push({r, c});
				}
			}
		}
		for(int dx = -1; dx <= 1; dx++) {
			int r = x;
			int c = (y + A + dx) % A;
			if(!vis[r][c]) {
				vis[r][c] = 1;
				qu.push({r, c});
			}
		}
	}
	for(int i = 0; i < A; i++) {
		if(vis[MX-1][i]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int te = 1;
	cin >> te;
	while(te--) {
		solve();
	}
}