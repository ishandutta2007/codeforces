#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 1e5 + 111;

int n;
int x[nax], y[nax];

LL wek(int x, int y, int xx, int yy) {
	return (LL) x * yy - (LL) y * xx;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d %d", x + i, y + i);
	}
	if (n % 2 == 1) {
		printf ("NO\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		int e = (j + 1) % n;
		int k = (i + n / 2) % n;
		int kk = (k + 1) % n;
		int kkk = (k + 2) % n;
		if (wek(x[j] - x[i], y[j] - y[i], x[e] - x[j], y[e] - y[j]) != wek(x[kk] - x[k], y[kk] - y[k], x[kkk] - x[kk], y[kkk] - y[kk])) {
			printf ("NO\n");
			return 0;
		}
	}
	printf ("YES\n");



	return 0;
}