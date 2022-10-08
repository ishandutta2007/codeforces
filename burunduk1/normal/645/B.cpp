/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	long long n, k;
	cin >> n >> k;
	k = min(k, n / 2);
	cout << 2 * (k * (n - k) + k * (k - 1) / 2) - k * k << endl;
}