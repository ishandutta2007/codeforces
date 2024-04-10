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

const int N = 1e7 + 101;

int n;
int x[N];
int ans[N][2];

int sito[N];
int cnt[N];

int main() {
	scanf ("%d", &n);
	rep(i, 1, n)
		scanf ("%d", x + i);
	rep(i, 2, N - 1) {
		if (!cnt[i]) {
			for (int j = i; j < N; j += i) {
				sito[j] = i;
				cnt[j]++;
			}
		}
	}
	rep(i, 1, n) {
		if (cnt[x[i]] == 1) {
			ans[i][0] = ans[i][1] = -1;
		}
		else {
			ans[i][0] = 1;
			const int c = sito[x[i]];
			while (x[i] % (ans[i][0] * c) == 0)
				ans[i][0] *= c;
			ans[i][1] = x[i] / ans[i][0];
		}
	}
	
	rep(j, 0, 1) {
		rep(i, 1, n)
			printf ("%d ", ans[i][j]);
		printf ("\n");
	}
	
	
	return 0;
}