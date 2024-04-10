/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 262200, K = 19;
vector <pair <int, int>> v[K];
int num[K];
pair <int, int> wh[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int k;
	cin >> k >> s;
	int n = 1 << k, xx = n / 2, y = 0;
	while (xx) {
		num[y] = xx;
		y++;
		xx /= 2;
	}
	xx = 0;
	for (int j = 0; j < num[0]; j++) {
		v[0].push_back({j, (s[j] == '?' ? 2 : 1)});
		wh[xx] = {0, j};
		xx++;
	}
	for (int i = 1; i < k; i++) {
		for (int j = 0; j < num[i]; j++) {
			int a = 0;
			if (s[xx] != '0') {
				a += v[i - 1][j * 2 + 1].S;
			} 
			if (s[xx] != '1') {
				a += v[i - 1][j * 2].S;
			}
			v[i].push_back({xx, a});
			wh[xx] = {i, j};
			xx++;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int p;
		char c;
		cin >> p >> c;
		p--;
		int i = wh[p].F, j = wh[p].S;
		s[p] = c;
		while (i != k) {
			if (i == 0) {
				v[0][j] = make_pair(j, (s[j] == '?' ? 2 : 1));
			} else {
				int a = 0;
				int xx = v[i][j].F;
				if (s[xx] != '0') {
					a += v[i - 1][j * 2 + 1].S;
				}
				if (s[xx] != '1') {
					a += v[i - 1][j * 2].S;
				}
				v[i][j] = make_pair(xx, a);
			}
			i++;
			j /= 2;
		}
		cout << v[k - 1][0].S << '\n';;
	}
}