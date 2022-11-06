#include <bits/stdc++.h>

using namespace std;

long long a[100];

int main() {

    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '#') a[i] += (1ll << (long long)j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if ((a[i] & a[j]) != 0 && a[i] != a[j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

    return 0;
}