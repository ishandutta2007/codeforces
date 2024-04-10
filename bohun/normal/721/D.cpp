#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
	
		
using namespace std;

const int nax = 2e5 + 111;

int n, k, x;
ll a[nax];	
multiset <pair<ll, int>> secik;

int znak(ll x) {
	if(x >= 0)
		return 1;
	return -1;
}

int main() {	
	scanf("%d %d %d", &n, &k, &x);
	int ilo = 1;
	FOR(i, 1, n) {
		scanf("%lld", a + i);
		ilo *= znak(a[i]);
		secik.insert(mp(abs(a[i]), i));
	}
	if(ilo > 0) {
		while(k--) {
			pair<ll, int> r = *secik.begin();
			secik.erase(secik.begin());
			int old = znak(a[r.se]);
			a[r.se] += x * -1 * znak(a[r.se]);
			int now = znak(a[r.se]);
			secik.insert(mp(abs(a[r.se]), r.se));
			if(old != now)
				break;
		}
	}
	while(k > 0) {
		pair<ll, int> r = *secik.begin();
		secik.erase(secik.begin());
		a[r.se] += x * znak(a[r.se]);
		secik.insert(mp(abs(a[r.se]), r.se));
		k -= 1;
	}
	FOR(i, 1, n)
		printf("%lld ", a[i]);
	
	
	
	
	
	return 0;
}