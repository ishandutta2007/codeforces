/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], cnt[N];
ll ans[N], ps[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	ll mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i], cnt[a[i]]++;
	for (int i = 1; i < N; i++) 
		ps[i] = ps[i - 1] + cnt[i];
	for (int i = 1; i < N; i++) {
		if (cnt[i] == 0)
			continue;
		for (int j = i; j < N ; j += i) {
			int tedad = ps[min(N - 1, j + i - 1)] - ps[j - 1];
			ll sum = (ll)tedad * (ll)j;
			ans[i] += sum;
		}
		mx = max(mx, ans[i]);
	}
	cout << mx << endl;
}