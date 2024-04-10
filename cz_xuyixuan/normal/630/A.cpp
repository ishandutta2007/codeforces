#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
#define P	100
int power(int x, long long y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
int main() {
	ios::sync_with_stdio(false);
	long long n; cin >> n;
	long long tmp = power(5, n);
	cout << tmp / 10 << tmp % 10 << endl;
	return 0;
}