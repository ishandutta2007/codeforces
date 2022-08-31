#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;
const int W = 16;

int C[50][50];

int dp[W][W+1][W][2];
int dp2[W][W+1][W][2];

void relax(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int res[1<<W][W+1][W];
int res2[1<<W][W+1][W];

int bp(int x, int y) {
	if (y==0) return 1%mod;
	if (y==1) return x%mod;

	if (y%2) return ((ll) x * bp(x, y-1)) % mod;
	int t = bp(x, y/2);

	return ((ll) t * t) % mod; 

}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 50; ++i) {
		C[i][0] = 1;
		C[i][i] = 1;

		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j];
			relax(C[i][j], C[i-1][j-1]);
		}

	}

	int n, k, c;
	cin >> n >> k >> c;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	vector<int> ans(1<<c);

	int def_val = 0;
	vector<vector<int> > dist(W);

	for (auto x : v) {
		int rem = x % W;
		int bp = x / W;

		if (bp == 0) dist[0].pb(x);
		else {
			int steps = 0;
			while (bp % 2 == 0) {
				bp /= 2;
				steps++;
			}
			def_val ^= ((x >> 4) << 4);
			dist[steps + 1].pb(x);
		}
	}

	for (int i = 0; i < 16; ++i) {
		dp[i][0][0][0] = 1;
		for (int val : dist[i]) {
			int rem = val % W;
			for (int j = 0; j <= W; ++j) for (int k = 0; k < W; ++k) for (int e = 0; e < 2; ++e) dp2[i][j][k][e] = 0;
			
			for (int spent = 0; spent <= W; ++spent) {
				for (int xr = 0; xr < W; ++xr) {
					for (int e = 0; e < 2; ++e) {
						for (int tr = 0; tr + spent <= W; ++tr) {
							if (tr <= rem) {
								//cout << rem << " " << tr << endl;
								//assert(rem - tr != 16);
								relax(dp2[i][spent + tr][xr ^ (rem - tr)][e], ((ll) dp[i][spent][xr][e] * C[tr+spent][spent]) % mod);
							}
							else {
								relax(dp2[i][spent + tr][xr ^ (rem - tr + W)][e^1], ((ll) dp[i][spent][xr][e] * C[tr+spent][spent]) % mod);
							}
						}
					}
				}
			}

			for (int j = 0; j <= W; ++j) for (int k = 0; k < W; ++k) for (int e = 0; e < 2; ++e) dp[i][j][k][e] = dp2[i][j][k][e];
		}
	}

	res[0][0][0] = 1;
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < (1<<W); ++j) for (int k = 0; k <= W; ++k) for (int e = 0; e < W; ++e) res2[j][k][e] = 0;

		for (int was = 0; was < (1<<i); ++was) {
			for (int spent = 0; spent <= W; ++spent) {
				for (int xr = 0; xr < W; ++xr) {
					if (!res[was][spent][xr]) continue;

					for (int want_s = 0; want_s + spent <= W; ++want_s) {
						for (int xt = 0; xt < W; ++xt) {

							int A = ((ll) res[was][spent][xr] * dp[i][want_s][xt][0]) % mod;
							relax(res2[was][spent + want_s][xr ^ xt], ((ll) A * C[spent + want_s][spent]) % mod);

							A = ((ll) res[was][spent][xr] * dp[i][want_s][xt][1]) % mod;
							relax(res2[was ^ (1<<i)][spent + want_s][xr ^ xt], ((ll) A * C[spent + want_s][spent]) % mod);
						}
					}
				}
			}
		}

		for (int j = 0; j < (1<<W); ++j) for (int k = 0; k <= W; ++k) for (int e = 0; e < W; ++e) res[j][k][e] = res2[j][k][e];
	}
	
	int Q = bp(n, mod-2);
	Q = bp(Q, k);

	for (int mask = 0; mask < (1<<W); ++mask) {

		int tet = 0;
		for (int i = 1; i < W; ++i) {
			if ((1<<i)&mask) {
				tet ^= (((1<<i) - 1) << 4);
			}
		}

		//if (tet != 0) cout << tet << endl;

		for (int xr = 0; xr < W; ++xr) {
			int resulting = xr ^ tet ^ def_val;
			if (!res[mask][k][xr]) continue;
			relax(ans[resulting], res[mask][k][xr]);

		}

	}

	for (auto& W : ans) {
		W = ((ll) W * Q) % mod;
	}

	for (auto W : ans) cout << W << " ";

	

}