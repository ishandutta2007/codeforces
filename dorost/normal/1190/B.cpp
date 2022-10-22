/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main() {
	int n;
	cin >> n;
	map <int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	bool f = false, h = true;
	int x = 0;
	set <int> st;
	for (int i = 0; i < n; i++) {
		if (mp[a[i]] >= 2)
			st.insert(a[i]);
	}
	if (st.size() > 2) {
		cout << "cslnb";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0)
			continue;
		set <int> st2 = st;
		st2.erase(a[i]);
		st2.erase(a[i] - 1);
		if (!st2.empty()) {
			continue;
		}
		mp[a[i]]--;
		mp[a[i] - 1]++;
		if (mp[a[i]] <= 1 && mp[a[i] - 1] <= 1)
			f = true;
		mp[a[i]]++;
		mp[a[i] - 1]--;
	}
	if (!f) {
		cout << "cslnb";
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		sum -= i;
		sum %= 2;
		if (sum < 0)
			sum += 2;
	}
	cout << (sum % 2 ? "sjfnb" : "cslnb");
}