#include<iostream>
using namespace std;
int p[100009], n, l, r, s, a, q;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a; s += a; }
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r; p[l]++; p[r + 1]--;
	}
	for (int i = 1; i <= 100008; i++)p[i] += p[i - 1];
	for (int i = s; i <= 100008; i++) {
		if (p[i] >= 1) { cout << i << endl; return 0; }
	}
	cout << -1 << endl;
	return 0;
}