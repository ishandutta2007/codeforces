#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

const int nn = 301;
const int MOD = 1000000000 + 7;

int f(int x) {
	for (int i = 2; i * i <= x; ++i) {
		while (x % (i * i) == 0) x /= (i * i);
	}
	return x;
}

long long C[nn][nn];
long long F[nn];

long long d[nn][nn][nn];

void add(long long& a, long long b) {
	a += b;
	a %= MOD;
}

bool solve() {
	int n;
	cin >> n;
	vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) a[i] = f(a[i]);

	vector<int> B;
	map<int, int> fr; for (int i = 0; i < n; ++i) fr[a[i]]++;
	for (map<int, int>::iterator it = fr.begin(); it != fr.end(); ++it) B.push_back(it->second);

	F[0] = C[0][0] = 1;
	for (int i = 1; i < nn; ++i) {
		F[i] = F[i-1] * i % MOD;
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	}

	d[0][0][1] = 1;
	for (int i = 0; i < B.size(); ++i) {
		for (int a = 0; a <= n; ++a) for (int b = 0; b <= n; ++b) if (d[i][a][b]) {
			for (int x = 0; x <= B[i]; ++x) for (int y = 0; y + x <= B[i]; ++y) {
				if (x + y == 0) continue;
				int _a = a + x + y * 2;
				int _b = b - y + (B[i] - x - y);
				add(d[i + 1][_a][_b], d[i][a][b] * F[B[i]] % MOD * C[a][x] % MOD * C[b][y] % MOD * C[B[i] - 1][x + y - 1] % MOD);
			}
		}
	}

	cout << d[B.size()][n+1][0] << endl;

    return false;
}

int main() {

    while (solve());
    
    return 0;
}