#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a, b, ans = LLONG_MAX, mn = LLONG_MAX;
	cin >> a >> b;
	for (long long n=1;n*n <= a+b;n++) {
		if (n * n <= a && a % n == 0)
			mn = min(mn, a/n);
		swap(b,a);
		if (n * n <= a && a % n == 0)
			mn = min(mn, a/n);
		if ((a + b) % n == 0 && mn <= (a + b)/n)
			ans = min(ans, 2*(n + (a + b)/n));
	}
	cout << ans << endl;
}