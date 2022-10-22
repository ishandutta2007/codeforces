#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;	

int t[310][310];
int col[310], row[310];

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int n, k;
		scanf ("%d%d", &n, &k);
		if (k % n == 0) printf ("0\n");
		else printf ("2\n");
		rep(i, 1, n) 
			col[i] = row[i] = k / n + (k % n >= i);

		rep(i, 1, n) rep(j, 1, n) t[i][j] = 0;
		int j = 1;
		rep(i, 1, n) {
			if (!col[i]) continue;
			while (!row[j]) {
				j++;
				if (j == n + 1) j = 1;
			}
			while (col[i] > 0) {
				t[i][j] = 1;
				row[j]--;
				col[i]--;
				j++;
				if (j == n + 1) j = 1;
			}
		}
		rep(i, 1, n) {
			rep(j, 1, n)
				printf ("%d", t[i][j]);
			printf ("\n");
		}
	}
	
	return 0;
}