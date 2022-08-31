/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 4e5 + 10, L = log2(N) + 10;
const ll inf = 1e15 + 10;

ll sum[N][L];
int par[N][L];

int main() {
	fast_cin();
	int Q, ind = 2; ll last = 0;
	cin >> Q;
	for (int j = 0; j < L; ++j) {
		sum[0][j] = sum[1][j] = inf;
	}
	sum[1][0] = 0;
	while (Q--) {
		ll t, p, q;
		cin >> t >> p >> q;
		p ^= last;
		q ^= last;
		if (t == 1) {
			for (int j = L - 1; j >= 0; --j) {
				if (sum[par[p][j]][0] < q) {
					p = par[p][j];
				}
			}
			if (sum[p][0] < q) {
				p = par[p][0];
			}
			par[ind][0] = p;
			sum[ind][0] = q;
			for (int j = 1; j < L; ++j) {
				par[ind][j] = par[par[ind][j - 1]][j - 1];
				sum[ind][j] = min(inf, sum[ind][j - 1] + sum[par[ind][j - 1]][j - 1]);
			}
			++ind;
		} else {
			last = 0;
			for (int j = L - 1; j >= 0; --j) {
				if (sum[p][j] <= q) {
					q -= sum[p][j];
					last += (1 << j);
					p = par[p][j];
				}
			}
			cout << last << endl;
		}
	}
	// for (int i = 0; i <= 3; ++i) {
	// 	for (int j = 0; j < 5; ++j) {
	// 		cout << i << ' ' << (1 << j) << ' ' << par[i][j] << ' ' << sum[i][j] << endl;
	// 	}
	// }						
}