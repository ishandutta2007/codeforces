#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
  
int t;
ll x, y, p, q;

int main() {
   	iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("a.in", "r", stdin);
    cin >> t;
    forn (i, t) {
    	cin >> x >> y >> p >> q;
    	ll gc = __gcd(p, q);
    	p /= gc;
    	q /= gc;
    	if (p == 0 && x) {
    		cout << "-1\n";
    		continue;
    	}
    	if (p == 1 && q == 1 && x < y) {
    		cout << "-1\n";
    		continue;
    	}
    	if (p == 0) {
    		cout << "0\n";
    		continue;
    	}
    	ll l = 0, r = ll(1e9) + 1LL;
    	while (r - l > 1) {
    		ll mid = (l + r) / 2;
    		if (mid * p >= x && mid * q >= y && mid * p - x <= mid * q - y)
    			r = mid;
    		else
    			l = mid;
    	}
    	cout << r * q - y << "\n";
    }
    re 0;
}