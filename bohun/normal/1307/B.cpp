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

const int nax = 100005;

int T, n;
int a[nax];

int main() {
	scanf ("%d", &T);
	while (T--) {
		int c;
		scanf ("%d%d", &n, &c);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", a + i);
		sort(a + 1, a + n + 1);
		bool ok = 0;
		for (int i = 1; i <= n; ++i) {
			if (!ok && c == a[i]) {
				printf ("1\n");
				ok = 1;
				break;
			}
		}

		if (ok) continue;

		if (c % a[n] == 0) {
			printf ("%d\n", c / a[n]);
		}
		else if (a[n] <= c)
			printf ("%d\n", (c + a[n] - 1) / a[n]);
		else
			printf ("2\n");
	}

	return 0;
}