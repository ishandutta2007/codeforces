/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 10123456;
int a[N], ps[N], cnt[N];
bool f[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	f[1] = true;
	for (int i = 1; i < N; i++) {
		if (f[i])
			continue;
		for (int j = i; j < N; j += i) {
			a[i] += cnt[j];
			if (i != j)
				f[j] = true;
		}
	}
	ps[0] = a[0];
	for (int i = 1; i < N; i++) {
		ps[i] = ps[i - 1] + a[i];
	}
	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		if (r >= N) {
			r = N - 1;
		}
		if (l >= N) {
			l = N - 1;
		}
		cout << ps[r] - ps[l - 1] << ' ';
	}
}