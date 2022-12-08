#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 310000;
int n;
int kkk;
ll v[N];
ll m[N];
int main() {
	cin >> n;
	ll sm = 0;
	for (int i = 0; i < n; ++i)
		cin >> v[i] >> m[i], sm += v[i];
	if (sm < 0) {
		for (int i = 0; i < n; ++i)
			v[i] = -v[i];
	}
	ll ans = 0;
	for (int i = 0; i < 62; ++i) {
		ll sm = 0;
		for (int j = 0; j < n; ++j) {
			if (m[j] == 1)
				sm += v[j];
		}
		if (sm > 0) {
			ans += (1ll << i);
			for (int j = 0; j < n; ++j)
				if (m[j] & 1)
					v[j] = -v[j];
		}
		for (int j = 0; j < n; ++j)
			m[j] /= 2;
	}
	cout << ans << "\n";
	return 0;
}