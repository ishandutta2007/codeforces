#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a[155], b[155], c[155], n; vector<long long>X, Y;

int main() {
	cin >> n;
	a[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) { c[j] = b[j]; b[j] = a[j]; a[j] = 0; }
		for (int k = -1; k <= 1; k += 2) {
			a[0] = 0;
			for (int j = 0; j <= n; j++) a[j + 1] = b[j] * k;
			for (int j = 0; j <= n; j++) a[j] += c[j];
			bool OK = true;
			for (int j = 0; j <= n; j++) {
				if (a[j] >= 2 || a[j] <= -2) OK = false;
			}
			if (OK == true) break;
		}
	}

	int f1 = 0; for (int i = 150; i >= 0; i--) { if (a[i] != 0) f1 = 1; if (f1 == 1) X.push_back(a[i]); } reverse(X.begin(), X.end());
	int f2 = 0; for (int i = 150; i >= 0; i--) { if (b[i] != 0) f2 = 1; if (f2 == 1) Y.push_back(b[i]); } reverse(Y.begin(), Y.end());
	int T1 = 1; if (X[X.size() - 1] == -1) T1 = -1; cout << X.size() - 1 << endl; for (int i = 0; i < X.size(); i++) { if (i)cout << " "; cout << X[i] * T1; } cout << endl;
	int T2 = 1; if (Y[Y.size() - 1] == -1) T2 = -1; cout << Y.size() - 1 << endl; for (int i = 0; i < Y.size(); i++) { if (i)cout << " "; cout << Y[i] * T2; } cout << endl;
	return 0;
}