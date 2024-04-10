#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


const int MOD = 1000000+3;


int pow2[3000];


int f (int n) {
	if (n == 1)  return 3;
	int res = (pow2[(n-1)*2] + 3 * f (n-1)) % MOD;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	pow2[0] = 1;
	for (int i=1; i<3000; ++i)
		pow2[i] = pow2[i-1] * 2 % MOD;

	int n;
	cin >> n;

	if (n == 0)
		cout << 1;
	else {
		int res = pow2[n*2] - f(n);
		res = (res % MOD + MOD) % MOD;
		cout << res;
	}

}