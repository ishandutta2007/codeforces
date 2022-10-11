#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long n, a[100009], L = -1000000001, R = 1000000001;
string S;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> S;
	for (int i = 4; i < n; i++) {
		if (S.substr(i - 4, 5) == "00001") { L = max({ L, a[i - 4],a[i - 3],a[i - 2],a[i - 1],a[i] }); }
		if (S.substr(i - 4, 5) == "11110") { R = min({ R, a[i - 4],a[i - 3],a[i - 2],a[i - 1],a[i] }); }
	}
	cout << L + 1 << " " << R - 1 << endl;
	return 0;
}