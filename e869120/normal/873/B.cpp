#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[100009], p[200009], n, maxn; string S;
int main() {
	for (int i = 0; i < 200009; i++)p[i] = -1;
	a[0] = 100000; cin >> n >> S; p[100000] = 0;
	for (int i = 1; i <= n; i++) { if (S[i - 1] == '1')a[i] = a[i - 1] + 1; else a[i] = a[i - 1] - 1; }
	for (int i = 1; i <= n; i++) {
		if (p[a[i]] >= 0) { maxn = max(maxn, i - p[a[i]]); }
		else { p[a[i]] = i; }
	}
	cout << maxn << endl;
	return 0;
}