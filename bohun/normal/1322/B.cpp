#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

const int N = 4e5 + 5;
int n, a[N], b[N], out;

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	for (int bit = 1; bit <= 2e7; bit <<= 1) {
		rep(i, 1, n) b[i] = a[i] % (bit << 1);
		sort(b + 1, b + n + 1);
		ll sum = 0;
		int w = n;
		rep(i, 1, n) {
			while (w && b[i] + b[w] >= bit) w--;
			sum += n - max(w, i);
		}
		w = n;
		rep(i, 1, n) {
			while (w && b[i] + b[w] >= 2 * bit) w--;
			sum -= n - max(w, i);
		}
		w = n;
		rep(i, 1, n) {
			while (w && b[i] + b[w] >= 3 * bit) w--;
			sum += n - max(w, i);
		}
		if (sum & 1) out += bit;
	}
	printf ("%d\n", out);
		
	return 0;
}