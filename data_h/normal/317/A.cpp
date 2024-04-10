#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;


int main() {
	long long a, b, m;
	cin >> a >> b >> m;
	if (a >= m || b >= m) {
		printf("0\n");
		return 0;
	}
	if (max(a, b) <= 0) {
		printf("-1\n");
		return 0;
	}
	if (a > b)
		swap(a, b);
	long long ans = 0;
	if (a < 0) {
		ans += (-a) / b;
		a += ans * b;
		if (a < 0)
			ans++, a += b;
	}
	while(b < m) {
		swap(a, b);
		b = a + b;
		ans++;
	}
	cout << ans << endl;
	return 0;
}