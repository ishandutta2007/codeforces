
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int maxn = 100*1000 + 5;

ll t[maxn];

int main(){
	ll n, m, a, D;
	cin >> n >> m >> a >> D;
	for (int i = 0; i < m; i++)
		cin >> t[i];
	ll p = 0, d = 1;
	ll aperd = (D/a + 1);
	ll ans = 0;
	while (p < m){
		ll r = min(t[p]/a, n);
		ll l = (d + a - 1)/a;
		if (r-l+1 >= 1){
			ll cnt = (r-l+1 + aperd-1)/aperd;
			ans += cnt;
			d = (l + (cnt-1)*aperd)*a + D + 1;
		}
		else{
			ans++;
			d = t[p] + D + 1;
		}
		while (p < m && t[p] < d) p++;
	}
	ll r = n;
	ll l = (d + a - 1)/a;
	if (r-l+1 >= 1){
		ll cnt = (r-l+1 + aperd-1)/aperd;
		ans += cnt;
	}
	cout << ans << endl;
	return 0;
}