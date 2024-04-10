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
	int n, k;
	cin >> n >> k;
	map <int, int> mp;
	map <int, bool> ans;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		mp[a[i]]++;
		if (mp[a[i]] == 1)
			ans[a[i]] = 1;
		if (mp[a[i]] == 2)
			ans.erase(a[i]);
	}
	int x = ans.size();
	if (x == 0) {
		cout << "Nothing" << '\n';
	} else {
		cout << (*ans.rbegin()).F << '\n';
	}
	for (int i = 0; i < n - k; i++) {
		cin >> a[i + k];
		mp[a[i + k]]++;
		if (mp[a[i + k]] == 1)
			ans[a[i + k]] = 1;
		if (mp[a[i + k]] == 2)
			ans.erase(a[i + k]);
		mp[a[i]]--;
		if (mp[a[i]] == 1)
			ans[a[i]] = 1;
		if (mp[a[i]] == 0)
			ans.erase(a[i]);
		x = ans.size();
		if (x == 0) {
			cout << "Nothing" << '\n';
		} else {
			cout << (*ans.rbegin()).F << '\n';
		}
	}
}