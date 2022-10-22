#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define ss(x) (int) x.size()

using namespace std;

const int nax = 1e6 + 111;

int n;
int a[nax];
ll b[nax];
ll sum;
vector <ll> primes;
ll best = 1e18;
vector <pair<ll, ll>> w;
ll opt = 0;

void proces(ll prime) {
	int L = w[0].fi;
	int R = w.back().fi;
	int wsk = 0;
	ll sum = 0;
	ll res = 1e18;
	ll ile = 0;
	ll global = 0;
	for(auto it : w)
		global += (ll) it.se * it.fi;
	for(int i = L; i <= R; ++i) {
		while(wsk < ss(w) && w[wsk].fi == i) {
			ile += w[wsk].se;
			sum += (ll) w[wsk].se * w[wsk].fi;
			wsk += 1;
		}
		res = min(res, (ll) i * ile - sum + (global - sum) - (ll) (prime - ile) * i);
	}
	opt += res;
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		sum += a[i];
	}
	if(sum == 1) {
		printf("-1\n");
		return 0;
	}
	for(int i = 2; (ll) i * i <= sum; ++i) {
		if(sum % i == 0) {
			primes.pb(i);
			while(sum % i == 0)
				sum /= i;
		}
	}
	if(sum > 1)
		primes.pb(sum);
	for(auto it : primes) {
		opt = 0;
		ll mam = 0;
		for(int i = 1; i <= n; ++i)
			b[i] = a[i] % it;
		for(int i = 1; i <= n; ++i) {
			int take = min(it - mam, b[i]);
			mam += take;
			if(take > 0)
				w.pb(mp(i, take));
			if(mam == it) {
				proces(it);
				w.clear();
				mam = 0;
			}
			b[i] -= take;
			take = min(it - mam, b[i]);
			mam += take;
			if(take > 0) {
				w.pb(mp(i, take));
			}
		}
		best = min(best, opt);
	}
	printf("%lld\n", best);





	return 0;
}