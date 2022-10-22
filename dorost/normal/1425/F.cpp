#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second

int32_t main() {
	int n;
	cin >> n;
	int x = 0;
	vector <int> v, v2;
	for (int i = 2; i <= n; i++) {
		cout << "? " << 1 << ' ' << i << endl;
		int k;
		cin >> k;
		v2.push_back(k);
	}
	cout << "? " << 2 << ' ' << 3 << endl;
	int k;
	cin >> k;
	v.push_back(v2[1] - k);
	for (int i = 0; i < n - 1; i++) {
		v.push_back(v2[i] - (i == 0 ? v[0] : v2[i - 1]));
	}
	cout << "! ";
	for (auto x : v)
		cout << x << ' ';
	cout << endl; 
}