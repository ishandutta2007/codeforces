#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

long long n;
long long ans = 1;

int main() {
	cin >> n;
	for(long long i = 1; i <= n; i *= 3) {
		if (n % i != 0)
			ans = max(ans, n / i + (n % i > 0));
	}
	cout << ans << endl;
	return 0;
}