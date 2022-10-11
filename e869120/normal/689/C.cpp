#include<iostream>
#include<algorithm>
using namespace std;
long long n;

long long solve(long long p) {
	long long ret = 0;
	for (long long i = 2; i*i*i <= p; i++) {
		ret += p / (i*i*i);
	}
	return ret;
}
int main() {
	cin >> n;
	long long L = 0, R = (1LL << 55), M;
	while (true) {
		M = (L + R) / 2;
		long long s1 = solve(M - 1), s2 = solve(M);
		if (s1 < n && s2 >= n) {
			if (s2 == n)cout << M << endl;
			else cout << "-1" << endl;
			break;
		}
		if (s2 < n)L = M;
		else R = M;
	}
	return 0;
}