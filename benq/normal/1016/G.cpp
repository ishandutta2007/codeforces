
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)

const int MAX_PR = 5000000;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

typedef unsigned long long ull;
const int bits = 4;
// if all numbers are less than 2^k, set bits = 64-k
const ull po = 1 << bits;
ull mod_mul(ull a, ull b, ull &c) {
	ull x = a * (b & (po - 1)) % c;
	while ((b >>= bits) > 0) {
		a = (a << bits) % c;
		x += (a * (b & (po - 1))) % c;
	}
	return x % c;
}
ull mod_pow(ull a, ull b, ull mod) {
	if (b == 0) return 1;
	ull res = mod_pow(a, b / 2, mod);
	res = mod_mul(res, res, mod);
	if (b & 1) return mod_mul(res, a, mod);
	return res;
}

bool prime(ull p) {
	if (p == 2) return true;
	if (p == 1 || p % 2 == 0) return false;
	ull s = p - 1;
	while (s % 2 == 0) s /= 2;
	rep(i,0,15) {
		ull a = rand() % (p - 1) + 1, tmp = s;
		ull mod = mod_pow(a, tmp, p);
		while (tmp != p - 1 && mod != 1 && mod != p - 1) {
			mod = mod_mul(mod, mod, p);
			tmp *= 2;
		}
		if (mod != p - 1 && tmp % 2 == 0) return false;
	}
	return true;
}

vector<ull> pr;
ull f(ull a, ull n, ull &has) {
	return (mod_mul(a, a, n) + has) % n;
}
vector<ull> factor(ull d) {
	vector<ull> res;
	for (int i = 0; i < sz(pr) && pr[i]*pr[i] <= d; i++)
		if (d % pr[i] == 0) {
			while (d % pr[i] == 0) {
			    d /= pr[i];
			    res.push_back(pr[i]);
			}
		}
	//d is now a product of at most 2 primes.
	if (d > 1) {
		if (prime(d))
			res.push_back(d);
		else while (true) {
			ull has = rand() % 2321 + 47;
			ull x = 2, y = 2, c = 1;
			for (; c==1; c = __gcd((y > x ? y - x : x - y), d)) {
				x = f(x, d, has);
				y = f(f(y, d, has), d, has);
			}
			if (c != d) {
				res.push_back(c); d /= c;
				res.push_back(d);
				break;
			}
		}
	}
	return res;
}

void init(int bits) {//how many bits do we use?
	vi p = eratosthenes_sieve(1 << ((bits + 2) / 3));
	pr.assign(all(p));
}

vpl comb(vector<ull> x) {
    map<ll,int> m;
    for (auto a: x) m[a] ++;
    vpl z;
    for (auto x: m) z.pb(x);
    return z;
}
int n;
ll x,y;
vl a,b;
ll M[1<<15], M2[1<<15], ans;

vpl tmp2;
void search(int ind, int l, int r) {
    if (ind == sz(tmp2)) {
        ans += M[l]*M2[r];
        return;
    }
    search(ind+1,l^(1<<ind),r);
    search(ind+1,l,r^(1<<ind));
    search(ind+1,l,r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x >> y;
    if (y % x != 0) {
        cout << 0;
        exit(0);
    }
    FOR(i,1,n+1) {
        ll z; cin >> z;
        if (z % x == 0) a.pb(z);
        if (y % z == 0) b.pb(z);
    }
    
    init(60);
    auto tmp = comb(factor(y));
    for (auto a: tmp) {
        int co = 0;
        while (x % a.f == 0) {
            x /= a.f;
            co ++;
        }
        tmp2.pb({a.f,co});
    }
    
    for (ll z: b) {
        ll bad = 0;
        F0R(i,sz(tmp)) {
            int co = 0;
            while (z % tmp[i].f == 0) z /= tmp[i].f, co ++;
            if (co < tmp[i].s && tmp[i].s != tmp2[i].s) bad |= 1<<i;
        }
        M[bad] ++;
    }
    for (ll z: a) {
        ll bad = 0;
        F0R(i,sz(tmp)) {
            int co = 0;
            while (z % tmp[i].f == 0) z /= tmp[i].f, co ++;
            if (co > tmp2[i].s) bad |= 1<<i;
        }
        M2[bad] ++;
    }
    
    search(0,0,0);
    cout << ans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/