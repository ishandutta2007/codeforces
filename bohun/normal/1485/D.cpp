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

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		rep(j, 1, m) {
			int x; scanf("%d", &x);
			printf("%d ", 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 - ((i + j) % 2 ? 0 : x * x * x * x));
		}
		puts("");
	}
	return 0;
}