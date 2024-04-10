#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, a[100005], c; vector<int>D;
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
int main() {
	cin >> n; int s = 0;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	int F = a[0];
	for (int i = 1; i < n; i++) {
		F = gcd(F, a[i]);
	}
	if (F >= 2) { cout << "YES" << endl; cout << "0" << endl; return 0; }
	for (int i = 0; i <= n; i++) {
		if (i != n && a[i] % 2 == 1) { s++; }
		else { if (s >= 1) { D.push_back(s); s = 0; } }
	}
	for (int i = 0; i < D.size(); i++) {
		c += D[i] / 2; if (D[i] % 2 == 1)c += 2;
	}
	cout << "YES" << endl;
	cout << c << endl;
	return 0;
}