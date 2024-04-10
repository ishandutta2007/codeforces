#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2e5 + 100;

int T;
int n;

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		if (n == 1) {
			printf ("-1\n");
		}
		else {
			printf ("2");
			rep(i, 1, n - 1) printf ("9");
			printf ("\n");
		}
	}
	
    return 0;
}