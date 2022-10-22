/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 400012, LG = 19;
int nxt[N][LG];
ll sum[N][LG];
int w[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	ll lst = 0;
	for (int i = 0; i < LG; i++)
		nxt[1][i] = -1;
	w[1] = 0;
	int cnt = 1;
	while (t--) {
		ll t, p, q;
		cin >> t >> p >> q;
		p ^= lst;
		q ^= lst;
		if (t == 1) {
			cnt++;
			w[cnt] = q;
			if (w[p] >= w[cnt]) {
				nxt[cnt][0] = p;
			} else {
				for (int i = LG - 1; i >= 0; i--) {
					if (nxt[p][i] != -1) {
						if (w[nxt[p][i]] < w[cnt]) {
							p = nxt[p][i];
						}
					}
				}
				if (p == 1) {
					nxt[cnt][0] = -1;
				} else {
					nxt[cnt][0] = nxt[p][0];
				}
			}
			sum[cnt][0] = w[nxt[cnt][0]];
			for (int i = 1; i < LG; i++) {
				if (nxt[cnt][i - 1] == -1) {
					nxt[cnt][i] = -1;
				} else {
					nxt[cnt][i] = nxt[nxt[cnt][i - 1]][i - 1];
					sum[cnt][i] = sum[nxt[cnt][i - 1]][i - 1] + sum[cnt][i - 1];
				}
			}
		} else {
			q -= w[p];
			if (q < 0) {
				cout << 0 << endl;
				lst = 0;
				continue;
			}
			int ans = 1;
			for (int i = LG - 1; i >= 0; i--) {
				if (nxt[p][i] != -1) {
					if (sum[p][i] <= q) {
						q -= sum[p][i];
						p = nxt[p][i];
						ans += (1 << i);
					}
				}
			}
			lst = ans;
			cout << ans << endl;
		}
	}
}