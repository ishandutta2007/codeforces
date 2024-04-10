#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif 


	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = i - a[i];
	}
	a[n] = n - 1;
	int Q;
	cin >> Q;
	vector<int> mn1(n + 1, n + 1), mn2(n + 1, n + 1);
	for (int i = n; i >= 0; i--) {
		int j = max(0, min(i, a[i]) + 1);
		mn2[j] = mn1[j];
		mn1[j] = i;
	}
	int fi = n + 1, sc = n + 1;
	for (int i = n; i >= 1; i--) {
		int upd = mn1[i];
		
		if (upd < fi) {
			sc = fi;
			fi = upd;
		} else {
			sc = min(sc, upd);
		}
		
		upd = mn2[i];
		
		if (upd < fi) {
			sc = fi;
			fi = upd;
		} else {
			sc = min(sc, upd);
		}
		
		mn1[i] = fi;
		mn2[i] = sc;
	}
	vector<ll> p1(n + 1, 0), p2(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		p1[i] = p1[i - 1] + mn1[i];
		p2[i] = p2[i - 1] + mn2[i];
	}
	while (Q--) {
		int p, vl;
		cin >> p >> vl;
		p--;
		int initj = max(0, min(p, a[p]) + 1);
		int nwj = max(0, min(p, p - vl) + 1);
		ll sol = 0;
		if (initj <= nwj) {	
			int last = initj, low = initj + 1, high = nwj;
			while (low <= high) {
				int j = (low + high) / 2;
				if (mn1[j] <= p) {
					last = j;
					low = j + 1;
				}	else {
					high = j - 1;
				}
			}
			sol += p1[n] - p1[nwj] + p1[last] + p * (ll) (nwj - last);
		} else {
			assert(nwj + 1 <= initj);
			int first = initj + 1, low = nwj + 1, high = initj;
			while (low <= high) {
				int j = (low + high) / 2;
				if (mn1[j] == p) {
					first = j;
					high = j - 1;
				} else {
					low = j + 1;
				}
			}
			sol += p1[n] - p1[initj] + p1[first - 1] + p2[initj] - p2[first - 1];
		}
		cout << sol - 1LL * n * (n - 1) / 2 << "\n";
	}

 	return 0;
}