#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main() {
	ios::sync_with_stdio(false);
	long long tmp = 1;
	for (int i = 2; i <= 10; i++)
		tmp = tmp * i / gcd(tmp, i);
	long long n;
	cin >> n;
	cout << n / tmp << endl;
	return 0;
}