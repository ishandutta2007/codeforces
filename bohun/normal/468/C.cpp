#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	


ll mod;
ll pot10[30];

ll daj(ll x) {
	ll res = 0;
	ll sum = 0;
	vector <int> d;
	while(x) {
		res += x % 10;
		d.pb(x % 10);
		x /= 10;
	}
	reverse(d.begin(), d.end());
	for(int i = 0; i < ss(d); ++i) {
		for(int j = 0; j < d[i]; ++j) {
			res = (res + 1ll * (sum + j) * pot10[ss(d) - i - 1]);
			if(i < ss(d) - 1)
				res = (res + 1ll * 45 * (1ll * (ss(d) - i - 1) * pot10[ss(d) - i - 2]));
		}
		sum += d[i];
	}
	return res;
}
		
	
			
int main() {
	scanf("%lld", &mod);
	pot10[0] = 1;
	for(int i = 1; i < 19; ++i) {
		pot10[i] = 1ll * pot10[i - 1] * 10;
	}
	ll lewo = 0;
	ll prawo = 1e17;
	while(lewo < prawo) {
		ll mid = (lewo + prawo) / 2;
		//cat(mid);
		//cat(daj(mid));
		if(daj(mid) >= mod)
			prawo = mid;
		else
			lewo = mid + 1;
	}
	
	ll l1 = 1;
	ll l2 = lewo;
	ll w1 = 1 % mod;
	ll w2 = daj(lewo) % mod;
	
	while(l1 == l2 || w1 != w2) {
		if(w1 < w2) {
			l1++;
			w1 = daj(l1) % mod;
		}
		else {
			l2++;
			w2 = daj(l2) % mod;
		}
	}
	printf("%lld %lld", l1 + 1, l2);
			
			
		
	
	return 0;
}