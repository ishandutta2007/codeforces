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
#define pc(x) __builtin_popcount(x)

using namespace std;

const int N = 1e5 + 100;

int n, m;
int a[N];
int p[N];

int main() {
	LL sum = 0;
	scanf ("%d%d", &n, &m);
	bool ok = 1;
	rep(i, 1, m) {
		scanf ("%d", &a[i]);
		p[i] = i;
		if (i - 1 + a[i] > n) ok = 0;
		sum += a[i];
	}
	if (!ok || sum < n) return printf ("-1\n"), 0;
	p[m + 1] = n + 1;
	per(i, 1, m) {
		while (p[i] + a[i] < p[i + 1])
			p[i]++;
	}
	rep(i, 1, m) printf ("%d ", p[i]);
	
    return 0;
}