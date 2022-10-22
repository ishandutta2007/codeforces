/* 	* In the name of GOD  */

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 300000, K = 31;
pair <int, int> a[N];
bool b[K], c[K];

inline void solve() {
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << n << '\n';
		for (int i = 1; i <= n; i++) {
			cout << i << ' ';
		}
		return;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i].F, a[i].S = i;
	sort(a, a + n);
	int l = k;
	for (int i = 0; i < K; i++) {
		b[i] = l % 2;
		l /= 2;
	}
	int x = 0;
	while ((1 << x) <= k)
		x++;
	x = (1 << x);
	vector <int> ans;
	int lst = 0;
	while (lst != n) {
		vector <pair <int, int>> v;
		for (int i = lst; i <= n; i++) {
			if (i != n && a[i].F / x == a[lst].F / x) {
				v.push_back(make_pair(a[i].F % x, a[i].S));
				//cout << a[i].F << '\n';
			} else {
				lst = i;
				break;
			}
		}
		sort(v.begin(), v.end());
		int in1 = -1, in2 = 0;
		bool h = false;
		for (int i = 0; i < v.size() && !h; i++) {
			l = v[i].F;
			for (int j = 0; j < K; j++) {
				c[j] = l % 2;
				l /= 2;
			}
			int x3 = 0;
			bool f = true;
			for (int j = 30; j >= 0 && f; j--) {
//				cout << i << ' ' << j << '\n';
				if (b[j] == 1) {
					x3 *= 2;
					x3 += (1 - c[j]);
					int r = (x3 + 1) * (1 << j);
					int aa = (lower_bound(v.begin(), v.end(), make_pair(x3 * (1 << j), -1))) - v.begin();
					if (aa != v.size() && v[aa].S == v[i].S)
						aa++;
//					cout << aa << ' ' << v[aa].F << ' ' << v[aa].S << '\n';
					if (aa != v.size() && v[aa].F < r) {
						continue;
					} else {
//						cout << x3 << ' ' << '\n';
						f = false;
					}
				} else {
					x3 *= 2;
					x3 += (1 - c[j]);
					int r = (x3 + 1) * (1 << j);
					int aa = (lower_bound(v.begin(), v.end(), make_pair(x3 * (1 << j), -1))) - v.begin();
					if (aa != v.size() && v[aa].S == v[i].S)
						aa++;
					if (aa != v.size() && v[aa].F < r) {
						in1 = i;
						in2 = aa;
						break;
					} else {
						x3 /= 2;
						x3 *= 2;
						x3 += c[j];
						continue;
					}
				}
			}
			if (f) {
				h = true;
				if (in1 == -1) {
					int r = (x3 + 1);
					int aa = (lower_bound(v.begin(), v.end(), make_pair(x3, -1))) - v.begin();
					if (aa != v.size() && v[aa].S == v[i].S)
						aa++;
					in1 = i;
					in2 = (aa);
				}
				ans.push_back(v[in1].S);
				ans.push_back(v[in2].S);
			}
		}
		if (!h) {
			ans.push_back(v[0].S);
			continue;
		}
	}
	if (ans.size() < 2) {
		cout << -1;
		return;
	}
	cout << ans.size() << '\n';
	for (auto x2 : ans)
		cout << x2 + 1 << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	solve();
}