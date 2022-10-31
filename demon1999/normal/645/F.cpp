#include <bits/stdc++.h>
#define forn(i, n) for(ll i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef double ld;
using namespace std;

struct T { int x, y; };
T t = {1, 2};
const ll mod = 1e9 + 7, szz = 1000101;

ll n, k, q, sum, fc[szz], fc1[szz], col[szz], ff[szz], bad[szz];
vector<int> a[szz];
ll delta, p;

ll c(int n, int k) {
	if (n < k) re 0;
	re (((fc[n] * fc1[k]) % mod) * fc1[n - k]) % mod;
}

void add(ll d) {
	for (int i = sz(a[d]) - 1; i >= 0; i--) {
		p = a[d][i];
		col[p]++;
		delta = (c(col[p], k) - ff[p] - bad[p]) % mod;
		if (delta < 0) delta += mod;
		sum = (sum + ll(p) * delta) % mod;
		ff[p] = (delta + ff[p]) % mod;
		forn (i, sz(a[p]) - 1) {
			bad[a[p][i]] = (bad[a[p][i]] + delta);
			if (bad[a[p][i]] > mod) bad[a[p][i]] -= mod;
			
		}
		
	}
}


int pow1(ll a, int k) {
	ll ans = 1, q = a;
	forn(j, 31) {
		if (k & (1 << j)) ans = ans * q % mod;
		q = q * q % mod;
	}	
	re ans;
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qqq.in", "r",  stdin));
    for (int i = 1; i <= 1000000; i++) {
    	for (int j = i; j <= 1000000; j += i)
			a[j].push_back(i); 
	}
	fc[0] = 1;
	fc1[0] = pow1(1, mod - 2);
	for (int i = 1; i <= 200000; i++) {
		fc[i] = fc[i - 1] * ll(i) % mod;
		fc1[i] = pow1(fc[i], mod - 2);
	}
	cin >> n >> k >> q;
	forn (i, n + q) {
		ll a;
		cin >> a;
		add(a);
		if (sum < 0) sum = (sum + mod);
		if (i >= n) cout << sum << "\n";
	}
    return 0;
}