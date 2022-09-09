#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main() {
	ios::sync_with_stdio(false);
	long long x, k;
	cin >> x >> k;
	long long tmp = 1;
	for (int i = 1; i <= k; i++)
		tmp *= 10;
	cout << x * tmp / gcd(x, tmp) << endl;
	return 0;
}