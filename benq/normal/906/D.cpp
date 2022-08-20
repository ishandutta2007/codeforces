#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

int n,m,w[100001];
vi z;

ll modpow(ll b, int po, int MOD) {
    return !po?1:modpow(b*b%MOD,po/2,MOD)*(po&1?b:1)%MOD;
}

int phi(int x) {
    if (x == 1) return 1;
    int X = x; 
    
    vi pri;
    for (int i = 2; i*i <= x; ++i) if (x % i == 0) {
        while (x % i == 0) x /= i;
        pri.pb(i);
    }
    
    if (x > 1) pri.pb(x);
    for (int i: pri) { X /= i; X *= i-1; }
    return X;
}

double solve(ll l, ll r, ll mx) {
    if (l > r || w[l] == 1) return 1;
    if (w[l] >= mx) return mx;
    double z = 1, co = 0; while (z <= mx) z *= w[l], co++;
    double t = pow(w[l],solve(l+1,r,co));
    return min(t,(double)mx);
}

ll get(int l, int r, int ind) {
    if (z[ind] == 1) return 0; // OK
    if ((ll)solve(l+1,r,31) <= 30) return modpow(w[l],(ll)solve(l+1,r,31),z[ind]);
    return modpow(w[l],z[ind+1]+get(l+1,r,ind+1),z[ind]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    FOR(i,1,n+1) {
        cin >> w[i];
        // w[i] = rand() % 1000000000+1;
    }
    z.pb(m); 
    while (z.back() != 1) z.pb(phi(z.back()));
    
    int q; cin >> q;
    F0R(i,q) {
        int l,r; // l = rand() % 50000+1; r = rand() % 50000+50000+1;
        cin >> l >> r;
        cout << get(l,r,0) << "\n";
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!