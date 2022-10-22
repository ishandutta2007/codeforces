/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100000, K = 17, h = 1823;
const ll M = 971943784632277;
vector <pair <int, pair <int, int>>> q[N];
ll ans[N];
string s[N];
map <ll, vector <int>> mp;
ll ps[N];

inline ll f(string s) {
	ll ans = 0;
	for (char c : s) {
		ans += c;
		ans *= h;
		ans %= M;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, t;
	cin >> n >> t;
	vector <int> sz;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			s[i][j] -= 'a';
			s[i][j]++;
		}
		sz.push_back(s[i].size());
		if (s[i].size() <= K) {
			mp[f(s[i])].push_back(i);
		}
	}
	sort(sz.begin(), sz.end());
	sz.erase(unique(sz.begin(), sz.end()), sz.end());
	for (int i = 0; i < t; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		l--, r--, k--;
		q[k].push_back(make_pair(i, make_pair(l, r)));
	}
	for (int k = 0; k < n; k++) {
		if (q[k].empty())
			continue;
		if (s[k].size() <= K) {
			for (int i = 0; i < s[k].size(); i++) {
				string t;
				for (int j = i; j < s[k].size(); j++) {
					t += s[k][j];
					for (pair <int, pair <int, int>> p : q[k]) {
						int l = p.S.F;
						int r = p.S.S;
						int in = p.F;
						ll x = f(t);
						ans[in] += upper_bound(mp[x].begin(), mp[x].end(), r) - lower_bound(mp[x].begin(), mp[x].end(), l);
					}
				}
			}
		} else {
			ps[0] = 0;
			map <pair <int, ll>, int> mp;
			for (int w : sz) {
				if (w > s[k].size())
					break;
				ll wh = 0;
				for (int i = 0; i < w; i++) {
					wh *= h;
					wh += (s[k][i]);
					wh %= M;
				}
				mp[make_pair(w, wh)]++;
				ll x = 1;
				for (int i = 0; i < w - 1; i++) {
					x *= h;
					x %= M;
				}
				for (int i = w; i < s[k].size(); i++) {
					wh -= x * (s[k][i - w]);
					wh %= M;
					wh += M;
					if (wh >= M)
						wh -= M;
					wh *= h;
					wh += (s[k][i]);
					wh %= M;
					mp[make_pair(w, wh)]++;
				}
			}
			for (int i = 0; i < n; i++) {
				int c = 0; // s[i] -> s[k];
				if (s[i].size() > s[k].size()) {
					c = 0;
				} else {
					int w = s[i].size();
					ll ans = 0;
					for (int j = 0; j < w; j++) {
						ans *= h;
						ans += (s[i][j]); 
						ans %= M;
					}
					c = mp[make_pair(w, ans)];
				}
				ps[i + 1] = ps[i] + c;
			}
			for (pair <int, pair <int, int>> p : q[k]) {
				int l = p.S.F;
				int r = p.S.S;
				int in = p.F;
				ans[in] = ps[r + 1] - ps[l]; 
			}
		}
	}
	for (int i = 0; i < t; i++)
		cout << ans[i] << ' ';
}