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
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		printf("%d\n", n - (int)count(a + 1, a + n + 1, a[1]));
	}
	return 0;
}