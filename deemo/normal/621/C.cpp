#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 1e5 + 10;

ll n, p, le[MAXN], ri[MAXN];
ld ans = 0;

ll cnt(ll l, ll r){return r/p - (l - 1)/p;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n >> p;
	for (ll i = 0; i < n; i++)
		cin >> le[i] >> ri[i];
	for (ll i = 0; i < n; i++){
		ld a = cnt(le[i], ri[i]), b = cnt(le[(i + 1) % n], ri[(i + 1) % n]);
		ld sz1 = ri[i] - le[i] + 1, sz2 = ri[(i + 1) % n] - le[(i + 1) % n] + 1;
		
		ld t = sz1 * sz2;
		ld p = a * sz2 + b * sz1 - a * b;
		ans += ld(p/t) * 1000.0;
	}
	cout << ans * 2.0 << endl;
	return	0;
}