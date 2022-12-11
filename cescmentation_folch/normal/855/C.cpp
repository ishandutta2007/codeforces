#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 100010;
ll D[3][11][N];
ll P[N];
vi G[N];
vi V;

void dfs(int x, int p = -1) {
	P[x] = p;
	for (int i = 0; i < (int)G[x].size(); ++i) {
		int y = G[x][i];
		if (y == p) continue;
		dfs(y, x);
	}
	V.push_back(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	ll mod = 1e9 + 7;
	cin >> n >> m;
	for (int i = 0; i < n -1; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ll k;
	cin >> k;
	ll ma;
	cin >> ma;
	dfs(0);
	for (int i = 0; i < n; ++i) {
		int x = V[i];
		bool first = true;
		for (int j = 0; j < (int)G[x].size(); ++j) {
			int y = G[x][j];
			if (y == P[x]) continue;
			if (first) {
				first = false;
				for (int w = 0; w <= ma; ++w) {
					D[0][w][x] = ((D[1][w][y] + D[0][w][y] + D[2][w][y])*(k - 1))%mod;
					D[2][w][x] = ((D[0][w][y] + D[2][w][y])*(m - k))%mod;
					if (w) D[1][w][x] = D[0][w - 1][y];
				}
			}
			else {
				vvi D1(3, vi(ma + 1, 0));
				for (int w = 0; w <= ma; ++w) {
					
					for (int tt = 0; tt <= w; ++tt) {
						D1[0][w] = (D1[0][w] + D[0][tt][x]*(D[1][w - tt][y] + D[0][w - tt][y] + D[2][w - tt][y]))%mod;
						D1[2][w] = (D1[2][w] + D[2][tt][x]*(D[0][w - tt][y] + D[2][w - tt][y]))%mod;
						if (tt) D1[1][w] = (D1[1][w] + D[1][tt][x]*(D[0][w - tt][y]))%mod;
					}
				}
				for (int w = 0; w <= ma; ++w) {
					D[0][w][x] = D1[0][w];
					D[1][w][x] = D1[1][w];
					D[2][w][x] = D1[2][w];
				}
			}
		}
		if (first) {
			D[0][0][x] = k - 1;
			D[1][1][x] = 1;
			D[2][0][x] = m - k;
		}
		
	}
	ll res = 0;
	for (int i = 0; i <= ma; ++i) res = (res + D[0][i][0] + D[1][i][0] + D[2][i][0])%mod;
	cout << res << endl;
}