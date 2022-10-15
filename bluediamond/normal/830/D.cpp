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

bool home = true;
using namespace std;
typedef long long ll;
const int M = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= M) {
		return a - M;
	}
	if (a < 0) {
		return a + M;
	}
	return a;
}

int mul(int a, int b) {
	return a * (ll)b % M;
}

int pw(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) {
			r = mul(r, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return r;
}

int dv(int a, int b) {
	return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
	a = add(a, b);
}

void mulup(int& a, int b) {
	a = mul(a, b);
}

const int N = 1000 + 7;
int lim;
int dp[N][N];

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

	cin >> lim;
	dp[1][0] = dp[1][1] = 1;
	for (int n = 2; n <= lim; n++) {
		for (int x = 0; x <= lim; x++) {
			for (int y = 0; y <= lim; y++) {
				int coef = mul(dp[n - 1][x], dp[n - 1][y]);
				if (!coef) continue;
				// don't add the root
				{
					addup(dp[n][x + y], coef);
				}
				// add the root
				{
					// alone
					{
						addup(dp[n][x + y + 1], coef);
					}
					// join from x
					if(x) {
						addup(dp[n][x + y], mul(coef, mul(2, x)));
					}
					// join from y
					if(y) {
						addup(dp[n][x + y], mul(coef, mul(2, y)));
					}
					// join from x and y
					if (x + y - 1 >= 0) {
						addup(dp[n][x + y - 1], mul(coef, mul(x + y, x + y - 1)));
					}
				}
			}
		}
	}
	cout << dp[lim][1] << "\n";
}