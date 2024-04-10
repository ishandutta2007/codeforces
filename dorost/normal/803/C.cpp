/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int unsigned long long

int32_t main(){
	int n, k, mx = 0;
	scanf("%llu%llu", &n, &k);
	vector <int> div;
	for (int i = 1; i * i <= n; i++) {
		if (n % i)
			continue;
		div.push_back(i);
		if (i != n / i)
			div.push_back(n / i);
	}
	for (int i = 0; i < div.size(); i++) {
		int x = div[i];
		if ((k * (k + 1)) / 2 * x <= n) {
			mx = max(mx, x);
		}
	}
	if (mx == 0 || k >= 1000000)
		return cout << -1, 0;
	int sum = 0;
	for (int i = 0; i < k - 1; i++) {
		printf("%llu ", mx * (i + 1));
		sum += mx * (i + 1);
	}
	printf("%llu", n - sum);
}