#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
long long n, a[100009]; vector<int>P;
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) {
		P.push_back(a[i]);
		if (i != n - 1 && gcd(a[i], a[i + 1]) != 1) {
			bool OK = false;
			for (int j = a[i]; j <= 1000000000; j++) {
				if (gcd(a[i], j) == 1 && gcd(j, a[i + 1]) == 1) { P.push_back(j); OK = true; break; }
			}
			if (OK == false) {
				for (int j = a[i]; j >= 1; j--) {
					if (gcd(a[i], j) == 1 && gcd(j, a[i + 1]) == 1) { P.push_back(j); OK = true; break; }
				}
			}
		}
	}
	cout << P.size() - n << endl;
	for (int i = 0; i < P.size(); i++) { if (i)cout << ' '; cout << P[i]; }cout << endl;
	return 0;
}