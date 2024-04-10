/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	string t;
	for (int i = 0; i < k; i++)
		t += s[i];
	string t2;
	for (int i = 0; i < n; i++) {
		t2 += t[i % k];
	}
	if (t2 >= s) {
		cout << n << '\n' << t2;
		return 0;
	}
	for (int i = k - 1; i >= 0; i--) {
		t[i]++;
		if (t[i] <= '9')
			break;
		t[i] = '0';
	}
	for (int i = 0; i < n; i++) {
		t2[i] = t[i % k];
	}
	if (t2 >= s) {
		cout << n << '\n' << t2;
		return 0;
	}
	assert(false);
}