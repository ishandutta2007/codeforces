/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int n, k, n2;
	cin >> n >> k;
	n2 = n;
	set <int> st;
	map <int, int> mp;
	for (int i = 0; i <= 30; i++) {
		if (n % 2) {
			st.insert(1 << i);
			mp[1 << i]++;
		}
		n /= 2;
	}
	if (st.size() > k || n2 < k) {
		cout << "NO";
		return 0;
	}
	int sum = st.size();
	while (sum != k) {
		int x = *st.rbegin();
		mp[x]--;
		if (mp[x] == 0)
			st.erase(x);
		x /= 2;
		mp[x] += 2;
		if (mp[x] == 2) 
			st.insert(x);
		sum++;
	}
	cout << "YES\n";
	for (auto x : st) {
		for (int i = 0; i < mp[x]; i++) {
			cout << x << ' ';
		}
	}
}