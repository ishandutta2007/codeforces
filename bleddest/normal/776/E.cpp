#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

long long phi (long long n) {
	long long result = n;
	for (long long i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long n, k;
	cin >> n >> k;
	long long l = 1;
	n = phi(n);
	while(l < k && n != 1)
	{
	 	++l;
	 	if (l & 1) n = phi(n);
	}
	cout << n % (1000000007) << endl;
	return 0;
}