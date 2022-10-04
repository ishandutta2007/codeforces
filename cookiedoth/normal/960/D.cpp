/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL
#define int long long

using namespace std;

const ll MOD = 1e9 + 7;

const int lg = 62;
ll a[lg];
int n;

int get_level(ll x) {
	for (int i = 0; i < lg; ++i) {
		if ((1LL << (i + 1)) - 1 >= x)
			return i;
	}
	assert(false);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll t, x, k;
		cin >> t;
		if (t == 1) {
			cin >> x >> k;
			x = get_level(x);
			ll kek = (1LL << x);
			k = (k % kek + kek) % kek;
			a[x] += k;
			a[x] = (a[x] + (1LL << x)) % (1LL << x);
		}
		if (t == 2) {
			cin >> x >> k;
			x = get_level(x);
			ll kek = (1LL << x);
			k = (k % kek + kek) % kek;
			for (int j = x; j < lg; ++j) {
				a[j] += k;
				a[j] = (a[j] + (1LL << j)) % (1LL << j);
				k *= 2;
			}
		}
		if (t == 3) {
			/*cout << "a" << endl;
			for (int i = 0; i < 10; ++i) {
				cout << a[i] << " ";
			}
			cout << endl;*/
			vector<ll> v;
			cin >> x;
			v.push_back(x);
			ll level = get_level(x);

			//cout << "level = " << level << endl;
			ll p2 = (1LL << level);
			x = (x + a[level]) % p2 + p2;
			//cout << "real_x = " << x << "   " << endl;
			x /= 2;
			while (x > 0) {
				ll level = get_level(x);
				ll p2 = (1LL << level);
				x -= p2;
				ll y = (x - a[level] + p2) % p2;
				v.push_back(y + p2);
				x += p2;
				x /= 2;
			}
			for (auto p : v) {
				cout << p << " ";
			}
			cout << endl;
		}
	}
}