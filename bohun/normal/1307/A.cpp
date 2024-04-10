#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 110;

int T, n;
int a[nax];

int main() {
	scanf ("%d", &T);
	while (T--) {
		int c;
		scanf ("%d%d", &n, &c);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", a + i);
			if (i > 0) {
				while (c >= i && a[i] > 0) {
					a[i]--;
					c -= i;
					a[0]++;
				}
			}
		}
		printf ("%d\n", a[0]);
	}

	return 0;
}