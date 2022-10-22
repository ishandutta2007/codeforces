/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 40123;
int a[N];

int32_t main() {
	set <pair <int, int>> st;
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	for (int i = 0; i < k; i++) {
		int a1, b;
		cin >> a1 >> b;
		st.insert(make_pair(a1 - 1, b - 1));
		a[a1 - 1]++;
	}
	while (t--) {
		int i, j;
		cin >> i >> j;
		i--;
		j--;
		int ans = 0;
		for (int k = 0; k < i; k++) {
			ans += (m - a[k]);
		}
		for (int k = 0; k < j; k++) {
			if (!st.count(make_pair(i, k))) {
				ans++;
			}
		}
		if (st.count(make_pair(i, j)))
			cout << "Waste\n";
		else {
			string s[3] = {"Carrots", "Kiwis", "Grapes"};
			cout << s[ans % 3] << '\n';
		}
	}

}