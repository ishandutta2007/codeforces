/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1000001;
int a[N], nge[N], lge[N], n, b[N * 2];

void LGE() {
	vector <int> st;
	for (int i = 0; i < 2 * n; i++) {
		while (!st.empty() && b[st.back()] <= b[i]) {
			st.pop_back();
		}
		if (st.empty()) {
			lge[i % n] = -1;
		} else {
			lge[i % n] = st.back() % n;
		}
		st.push_back(i);
	}
}

void NGE() {
	vector <int> st;
	for (int i = 0; i < 2 * n; i++) {
		while (!st.empty() && b[st.back()] <= b[i]) {
			st.pop_back();
		}
		if (st.empty()) {
			nge[n - (i % n) - 1] = -1;
		} else {
			nge[n - (i % n) - 1] = n - (st.back() % n) - 1;
		}
		st.push_back(i);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	map <int, pair <int, vector <int>>> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]].F = -1;
		mp[a[i]].S.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
		b[n + i] = a[i];
	}
	LGE();
	for (int i = 0; i < n; i++) {
		swap(b[i], b[n * 2 - i - 1]);
	}
	NGE();
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int l = lge[i], r = nge[i];
		if (l == r && l != -1)
			ans++;
		if (l != r)
			ans += 2;
	}
	for (auto p : mp) {
		for (int i = 0; i < p.S.S.size(); i++) {
			int l = lge[mp[p.F].S[i]], r = nge[mp[p.F].S[i]];
			int x = 0;
			if (l == r) {
				l = 0;
				r = n - 1;
			}
			if (l > r) {
				while (mp[p.F].S.size() >= mp[p.F].F + 1 && mp[p.F].S.size()) {
					if (mp[p.F].S.back() < l) {
						break;
					}
					x++;
					mp[p.F].S.pop_back();
				}
				l = 0;
			}
			for (int i = mp[p.F].F + 1; i < mp[p.F].S.size(); i++) {
				if (mp[p.F].S[i] > r) {
					break;
				}
				x++;
				mp[p.F].F++;
			}
			ans += (ll)((ll)x * (ll)(x - 1LL)) / 2LL;
		}
	}
	cout << ans;
}