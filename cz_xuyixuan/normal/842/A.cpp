#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	long long a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	for (long long i = c; i <= d; i++) {
		long long tmp = i * e;
		if (tmp >= a && tmp <= b) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}