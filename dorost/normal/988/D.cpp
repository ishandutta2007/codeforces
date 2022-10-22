/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200000, M = 31;
int p2[M], a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	p2[0] = 1;
	for (int i = 1; i < M; i++) {
		p2[i] = p2[i - 1] * 2;
	}
	int n;
	cin >> n;
	set <int> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(a[i]);
	}
	int mx = 0;
	int f, nxt;
	ll x;
	int ans, f1, nxt1, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < M; j++) {
			x = a[i] + p2[j];
			ans = 1;
			f1 = a[i];
			nxt1 = p2[j];
			if (st.count(x)) {
				ans++;
				x += p2[j];
				if (x < INT_MAX) {
					if (st.count(x)) 
						ans++;
				}
			}
			if (ans > mx) {
				mx = ans;
				f = f1;
				nxt = nxt1;
			}
		}
	}
	cout << mx << '\n';
	for (i = 0; i < mx; i++) {
		cout << f + nxt * i << ' ';
	}
}