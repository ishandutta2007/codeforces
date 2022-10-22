#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

int main() {
	int T, a, b, x, y, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%d%d%d", &a, &b, &x, &y, &n);
		ll out = 1e18;
		
		if (n <= a - x)
			out = min(out, 1LL * (a - n) * b);
		else 
			out = min(out, 1LL * x * max(y, b - (n - (a - x))));
			
		swap(a, b);
		swap(x, y);
		
		if (n <= a - x)
			out = min(out, 1LL * (a - n) * b);
		else 
			out = min(out, 1LL * x * max(y, b - (n - (a - x))));
		printf ("%lld\n", out);
	}
	return 0;
}