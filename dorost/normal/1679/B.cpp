/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], ti[N];
int lst = -1, t = -1;

int get (int i) {
	if (ti[i] > t)
		return a[i];
	else
		return lst;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int time = 0;
	ll sum = 0;
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	while (q--) {
		time++;
		int c;
		cin >> c;
		if (c == 1) {
			int i, x;
			cin >> i >> x;
			i--;
			sum -= get(i);
			a[i] = x;
			ti[i] = time;
			sum += get(i);
		} else {
			int x;
			cin >> x;
			lst = x;
			t = time;
			sum = x * n;
		}
		cout << sum << '\n';
	}
}