#include<iostream>
#include<algorithm>
using namespace std;
long long a, b, c, d, e;
int main() {
	cin >> a >> b >> c >> d >> e;
	long long L, R;
	if (a > c) { swap(a, c); swap(b, d); }
	if (b < c) { cout << "0" << endl; return 0; }
	L = max(a, c); R = min(b, d);
	if (L <= e && e <= R)cout << (R - L + 1) - 1 << endl;
	else cout << R - L + 1 << endl;
	return 0;
}