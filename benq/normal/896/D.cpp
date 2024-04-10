#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
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

int n,p,l,r;
map<pii,ll> m; 
map<pii,vector<pii>> fac;

ll inv(int a, int b) { // 0 < a < b, gcd(a,b) = 1
    if (a == 1) return 1;
    ll i = inv(b%a,a);
    ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
    while (tmp < 0) tmp += b;
    return tmp;
}

void process(pii z, int a, int b, int mult) {
    int mo = pow(z.f,z.s);
    auto N = fac[z][n], A = fac[z][a], B = fac[z][b], C = fac[z][n-a-b];
    N.s -= A.s+B.s+C.s;
    N.f = N.f*inv(A.f,mo)%mo;
    N.f = N.f*inv(B.f,mo)%mo;
    N.f = N.f*inv(C.f,mo)%mo;
    F0R(i,N.s) N.f = N.f*z.f %mo;
    m[z] += mult*N.f;
    m[z] = (m[z]%mo+mo)%mo;
}

void upd(int sum, int lo, int mult) { // b+a=sum, b-a >= lo
    int b = (lo+sum+1)/2, a = sum-b;
    if (a < 0 || b < 0) return;
    for (auto& z: m) process(z.f,a,b,mult);
}

ll nn = 1, mm, a = 0, b;

void solve() {
    ll x = (a-b)*inv(mm,nn) % nn;
    ll ans = (mm*x+b) % (mm*nn);
    while (ans < 0) ans += (mm*nn);
    nn = mm*nn, a = ans;
}

void comb() {
    for (auto a: m) {
        mm = pow(a.f.f,a.f.s);
        b = a.s;
        solve();
    }
    cout << a;
}

void factor(int p) { // p = 1?
    for (int i = 2; i*i <= p; ++i) {
        int co = 0;
        while (p % i == 0) p /= i, co++;
        if (co) m[{i,co}] = 0;
    }
    if (p > 1) m[{p,1}] = 0;
}

void gen() {
    for (auto& a: m) {
        ll x = 1, y = 0;
        
        vector<pii> tmp; tmp.pb({x,y});
        FOR(i,1,n+1) {
            int i1 = i;
            while (i1 % a.f.f == 0) i1 /= a.f.f, y++;
            x = x*i1%(int)pow(a.f.f,a.f.s);
            tmp.pb({x,y});
        }
        
        fac[a.f] = tmp;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> p >> l >> r;
	factor(p);
	gen();
	F0R(i,n+1) {
	    upd(i,l,1);
	    upd(i,r+1,-1);
	}
	comb();
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!