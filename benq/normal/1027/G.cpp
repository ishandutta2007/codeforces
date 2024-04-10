#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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


typedef unsigned long long ull;
const int bits = 16;
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

vpl fac(ll m) {
    vpl v;
    for (ll i = 2; i*i <= m; ++i) if (m % i == 0) {
        int num = 0;
        while (m % i == 0) m /= i, num ++;
        v.pb({i,num});
    }
    if (m > 1) v.pb({m,1});
    return v;
}

ll m,x,ans;
vector<vl> p;
vpl v;

ll lcm(ll a, ll b) {
    return a/__gcd(a,b)*b;
}

ll getPeriod(ll p) {
    auto a = fac(p-1);
    ll cur = p-1;
    for (auto t: a) while (cur % t.f == 0 && mod_pow(x,cur/t.f,p) == 1) cur /= t.f;
    return cur;
}

void search(int ind, ll ph, ll pe) {
    if (ind == sz(v)) {
        ans += ph/pe;
        return;
    }
    F0R(i,v[ind].s+1) {
        search(ind+1,ph,lcm(p[ind][i],pe));
        if (i == 0) ph *= v[ind].f-1;
        else ph *= v[ind].f;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> x;
    v = fac(m);
    F0R(i,sz(v)) {
        p.pb({1});
        ll mul = v[i].f;
        FOR(j,1,v[i].s+1) {
            if (j == 1) p.back().pb(getPeriod(v[i].f));
            else {
                mul *= v[i].f;
                ll lst = p.back().back();
                if (mod_pow(x,lst,mul) == 1) p.back().pb(lst);
                else p.back().pb(lst*v[i].f);
            }
        }
    }
    search(0,1,1);
    cout << ans;
    // for each divisor of m: 
    // phi(m)/(lcm of periods for each prime power)
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/