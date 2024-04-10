#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int a[200], n, b[200], c[200]; long long ret = 1;
long long gcd(long long a, long long b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
long long lcm(long long a, long long b) {
	return a / gcd(a, b)*b;
}
int main() {
	cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i]; b[i] = i; c[i] = 999999999; }
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= n; j++) {
			b[j] = a[b[j]]; if (b[j] == j)c[j] = min(c[j], i);
		}
	}
	bool OK = true; for (int i = 1; i <= n; i++) { if (c[i] == 999999999)OK = false; }
	if (OK == false) { cout << "-1" << endl; return 0; }
	for (int i = 1; i <= n; i++) { ret = lcm(ret, c[i]); }
	if (ret % 2 == 0)ret /= 2;
	cout << ret << endl;
	return 0;
}