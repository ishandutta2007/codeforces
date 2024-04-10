#include <iostream>
#include <cstdio>

using namespace std;

double r[1<<20];
double a[20][20];
int n;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	r[(1<<n) - 1] = 1;
	for (int m = (1<<n) - 1; m > 0; m--) {
		int c = 0;
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if ( (m & ((1<<i)+(1<<j))) == (1<<i)+(1<<j) ) c++;
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if ( (m & ((1<<i)+(1<<j))) == (1<<i)+(1<<j) ) {
			r[m - (1<<i)] += r[m] * a[j][i] / c;
			r[m - (1<<j)] += r[m] * a[i][j] / c;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%.10lf ", r[1<<i]);
	}
}

int main() {
	solve();
	return 0;
}