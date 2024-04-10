#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	long long n; cin >> n;
	int a = n / 10000;
	int b = n / 1000 % 10;
	int c = n / 100 % 10;
	int d = n / 10 % 10;
	int e = n % 10;
	n = a * 10000 + c * 1000 + e * 100 + d * 10 + b;
	long long ans = 1;
	for (int i = 1; i <= 5; i++)
		ans = ans * n % 100000;
	a = ans / 10000;
	b = ans / 1000 % 10;
	c = ans / 100 % 10;
	d = ans / 10 % 10;
	e = ans % 10;
	cout << a << b << c << d << e << endl;
	return 0;
}