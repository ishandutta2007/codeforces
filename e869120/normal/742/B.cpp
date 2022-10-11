#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n, k, a[1000000], b[131072];
int main() {
	cin >> n >> k; long long ret = 0;
	for (int i = 0; i < n; i++) { cin >> a[i]; b[a[i]]++; }
	for (int i = 0; i < 131072; i++) {
		int g = i^k;
		if (i != g)ret += 1LL * b[i] * b[g];
		if (i == g)ret += 1LL * (b[i] - 1)*b[i];
	}
	cout << ret / 2 << endl;
	return 0;
}