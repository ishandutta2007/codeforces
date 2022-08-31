/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int H = 100;

ll val_shift[H], node_shift[H];

inline int height(ll x);
inline ll length(int h);
inline ll get_val(ll x, int h);

int main() {
	fast_cin();
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			ll x, k;
			cin >> x >> k;
			k %= length(height(x));
			val_shift[height(x)] += k + length(height(x));
			val_shift[height(x)] %= length(height(x));
		} else if (t == 2) {
			ll x, k;
			cin >> x >> k;
			k %= length(height(x));
			node_shift[height(x)] += k + length(height(x));
			node_shift[height(x)] %= length(height(x));
		} else {
			ll x; cin >> x;
			ll h = height(x), i = get_val(x + val_shift[h], h);
			while (true) {
				ll val = get_val(i - val_shift[h], h);
				cout << val << ' ';
				if (i == 1) {
					break;
				}
				if (i & 1) {
					i = get_val(i / 2 + ((node_shift[h] + 1) / 2), h - 1);
				} else {
					i = get_val(i / 2 + (node_shift[h] / 2), h - 1);
				}
				--h;
			}
			cout << '\n';
		}
	}
}

inline int height(ll x) {
	ll ans = 0;
	while (x > 1) {
		x >>= 1;
		++ans;
	}
	return ans;
}

inline ll length(int h) {
	return (1ll << h);
}

inline ll get_val(ll x, int h) {
	ll l = (1ll << h), r = 2 * l - 1;
	if (x > r) {
		x -= l;
	}
	if (x < l) {
		x += l;
	}
	return x;
}