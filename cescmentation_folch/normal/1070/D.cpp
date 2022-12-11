#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> ii;


int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll g0 = 0, g1 = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        g1 = g0;
        cin >> g0;
        ll t = (g1 + g0) - (g1 + g0)%k;
        if (t <= g1) g1 -= t;
        else {
            g0 -= t - g1;
            g1 = 0;
        }
        count += t/k;
        if (g1 > 0) {
            ++count;
            g0 = max(0ll, g0 - (k - g1));
            g1 = 0;
        }
    }
    if (g0 > 0) ++count;
    cout << count << endl;
}