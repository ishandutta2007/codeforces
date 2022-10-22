/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 106;
int a[N];
bool f[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		if (!f[i])
			v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int k = 0, sum = 0;
	int an = -1;
	for (int i = 0; i < n; i++) {
		if (!f[i]) {
			a[i] = v[k];
			k++;
		}
		sum += a[i];
		if (sum < 0) {
			an = i;
		}
	}
	reverse(v.begin(), v.end());
	k = 0, sum = 0;
	int an2 = -1;
	for (int i = 0; i < n; i++) {
		if (!f[i]) {
			a[i] = v[k];
			k++;
		}
		sum += a[i];
		if (sum < 0)
			an2 = i;
	}
	if (an < an2) {
		reverse(v.begin(), v.end());
		int k = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			if (!f[i]) {
				a[i] = v[k];
				k++;
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}