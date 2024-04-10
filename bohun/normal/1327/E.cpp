#include <bits/stdc++.h>
#define LL long long
#define LD long double
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

const int MOD = 998244353;
const int N = 2e5 + 100;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int n;
int p[N];


int main() {
	scanf ("%d", &n);
	p[0] = 1;
	rep(i, 1, N - 1) p[i] = (LL) p[i - 1] * 10 % MOD;
	
	rep(i, 1, n) {
		if (i == n) {
			printf ("%d\n", 10);
			continue;
		}
		int all = n - i + 1;
		int ans = 0;
		add(ans, (LL) 2 * 10 * 9 * p[n - i - 1] % MOD);
		add(ans, (LL) (all - 2) * 10 * 9 * 9 % MOD * p[n - i - 2] % MOD);
		printf ("%d ", ans);
	}
		
	

	return 0;
}