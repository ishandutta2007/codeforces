#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

const int N = 1000 + 7;
const int K = 50 + 7;
const int INF = (int)1e9 + 7;
int n, p, k;
int is1[N], is2[N], is3[N];
int mx[N][K][K];
int nmx[N][K][K];

void relax(int& a, int val) {
	a = max(a, val);
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}


	cin >> n >> p >> k;
	{
		int c1;
		cin >> c1;
		for (int i = 1; i <= c1; i++) {
			int x;
			cin >> x;
			is1[x] = 1;
		}
	}
	{
		int c2;
		cin >> c2;
		for (int i = 1; i <= c2; i++) {
			int x;
			cin >> x;
			is2[x] = 1;
		}
	}
	for (int i = 0; i <= p; i++) {
		for (int a = 0; a <= k; a++) {
			for (int b = 0; b <= k; b++) {
				mx[i][a][b] = -INF;
				nmx[i][a][b] = -INF;
			}
		}
	}
	mx[0][0][0] = 0;

	{
		int need = (n + k - 1) / k;
		if (p >= 2 * need) {
			int sol = 0;
			for (int i = 1; i <= n; i++) {
				sol += (is1[i] | is2[i]);
			}
			cout << sol << "\n";
			return 0;
		}
	}

	for (int position = 1; position <= n; position++) {
		int g1 = is1[position];
		int g2 = is2[position];
		for (int i = 0; i <= p; i++) {
			for (int a = 0; a <= k; a++) {
				for (int b = 0; b <= k; b++) {
					int coef = mx[i][a][b];
					// just consume
					relax(nmx[i][max(0, a - 1)][max(0, b - 1)], coef + min(1, g1 * (a >= 1) + g2 * (b >= 1)));
					// fuel a
					relax(nmx[i + 1][k - 1][max(0, b - 1)], coef + min(1, g1 * 1 + g2 * (b >= 1)));
					// fuel b
					relax(nmx[i + 1][max(0, a - 1)][k - 1], coef + min(1, g1 * (a >= 1) + g2 * 1));

					// fuel both
					relax(nmx[i + 2][k - 1][k - 1], coef + min(1, g1 * 1 + g2 * 1));
				}
			}

		}
		for (int i = 0; i <= p; i++) {
			for (int a = 0; a <= k; a++) {
				for (int b = 0; b <= k; b++) {
					mx[i][a][b] = nmx[i][a][b];
					nmx[i][a][b] = -INF;
				}
			}
		}
	}
	int best = -INF;
	for (int i = 0; i <= p; i++) {
		for (int a = 0; a <= k; a++) {
			for (int b = 0; b <= k; b++) {
				relax(best, mx[i][a][b]);
			}
		}
	}
	cout << best << "\n";
}