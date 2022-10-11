#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
long long gcd(long long a, long long b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
long long n, k, c[1000000];
int main() {
	cin >> n >> k; long long V = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
		V = (V*c[i]) / gcd(V, c[i]);
		V = gcd(V, k);
	}
	if (V == k) { cout << "Yes" << endl; }
	else cout << "No" << endl;
	return 0;
}