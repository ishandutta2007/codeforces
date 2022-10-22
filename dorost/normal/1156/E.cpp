/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int lst[N], nxt[N], a[N], w[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		w[a[i]] = i;
	}
	for (int i = 0; i < n; i++)
		lst[i] = -1, nxt[i] = n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		while (!v.empty() && a[v.back()] < a[i]) {
			nxt[v.back()] = i;
			v.pop_back();
		}
		v.push_back(i);
	}
	v.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!v.empty() && a[v.back()] < a[i]) {
			lst[v.back()] = i;
			v.pop_back();
		}
		v.push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (nxt[i] - i < i - lst[i]) 
			for (int j = i + 1; j < nxt[i]; j++) 
				ans += (w[a[i] - a[j]] > lst[i] && w[a[i] - a[j]] < i);
		else
			for (int j = lst[i] + 1; j < i; j++) 
				ans += (w[a[i] - a[j]] > i && w[a[i] - a[j]] < nxt[i]);
	}
	cout << ans;
}