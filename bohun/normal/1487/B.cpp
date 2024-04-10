#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

int n, a[105];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		if (n % 2 == 0) {
			printf("%d\n", (k - 1) % n + 1); continue;
		}
		if (k <= n / 2) {
			printf("%d\n", k); continue;
		}
		printf("%d\n", (k + (k - n / 2 - 1) / (n / 2)) % n + 1);
	}
	return 0;
}