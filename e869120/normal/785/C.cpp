#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
long long n, m;
int main() {
	cin >> n >> m;
	if (n <= m) { cout << n << endl; return 0; }
	long long d = m, e = n - m;
	long long L = 0, R = 2000000000, M;
	while (true) {
		M = (L + R) / 2;
		long long A1 = (M - 1)*M / 2;
		long long A2 = M*(M + 1) / 2;
		if (A1 < e && A2 >= e) { cout << d + M << endl; break; }
		if (A1 >= e)R = M;
		if (A2 < e)L = M;
	}
	return 0;
}