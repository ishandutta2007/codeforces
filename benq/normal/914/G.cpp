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

const int MOD = 1000000007;

typedef vector<ll> vl;

int get(int s) {
    return s > 1 ? 32 - __builtin_clz(s - 1) : 0;
}

namespace andConv {
    vl andConv(vl P, bool inv = 0) {
        for (int len = 1; 2 * len <= sz(P); len <<= 1) {
            for (int i = 0; i < sz(P); i += 2 * len) {
                for (int j = 0; j < len; j++) {
                    ll u = P[i + j];
                    ll v = P[i + len + j];

                    if (!inv) {
                        P[i + j] = v;
                        P[i + len + j] = (u + v)%MOD;
                    } else {
                        P[i + j] = (-u + v+MOD)%MOD;
                        P[i + len + j] = u;
                    }
                }
            }
        }
    
        return P;
    }
    
    vl conv(vl a, vl b) {
        int s = max(sz(a),sz(b)), L = get(s), n = 1<<L;
        if (s <= 0) return {};
        
        a.resize(n); a = andConv(a);
        b.resize(n); b = andConv(b);
        
        F0R(i,n) a[i] = a[i]*b[i] % MOD;
        a = andConv(a,1);
        return a;
    }
}


namespace FWHT {
    ll modpow(ll b, ll p) { return !p?1:modpow(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    
    ll inv (ll b) { return modpow(b,MOD-2); }
    
    vl fwht(vl P) {
        for (int len = 1; 2 * len <= sz(P); len <<= 1) {
            for (int i = 0; i < sz(P); i += 2 * len) {
                for (int j = 0; j < len; j++) {
                    ll u = P[i + j];
                    ll v = P[i + len + j];
                    P[i + j] = (u+v)%MOD;
                    P[i + len + j] = (u-v+MOD)%MOD;
                }
            }
        }
    
        return P;
    }

    
    vl fwht_rev(vl& a) {
        vl res = fwht(a);
        ll x = inv(sz(a));
        F0R(i,sz(res)) res[i] = res[i]*x % MOD;
        return res;
    }
    
    vl conv(vl a, vl b) {
        int s = max(sz(a),sz(b)), L = get(s), n = 1<<L;
        if (s <= 0) return {};
        
        a.resize(n); a = fwht(a);
        b.resize(n); b = fwht(b);
        
        F0R(i,n) a[i] = a[i]*b[i] % MOD;
        a = fwht_rev(a);
        return a;
    }
}

int n;
vl oc, fib;
vl ret;

void search(int ori, vi& t, int ind, int res) {
    if (ind == sz(t)) {
        ret[ori|res] += oc[ori]*oc[res];
        ret[ori|res] %= MOD;
        return;
    }
    search(ori,t,ind+1,res);
    search(ori,t,ind+1,res^(1<<t[ind]));
}

vl Subset() {
    ret.resize(1<<17);
    F0R(i,1<<17) {
        vi t;
        F0R(j,17) if (!(i&(1<<j))) t.pb(j);
        search(i,t,0,0);
    }
    return ret;
}

vl trans(vl x) {
    F0R(i,sz(x)) {
        x[i] *= fib[i];
        x[i] %= MOD;
    }
    return x;
}

void prin(vl x) {
    F0R(i,sz(x)) if (x[i] != 0) cout << i << " " << x[i] << "\n";
    cout << "----\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	oc.resize(1<<17); fib.resize(1<<17);
	fib[1] = 1;
	FOR(i,2,1<<17) fib[i] = (fib[i-1]+fib[i-2]) % MOD;
	F0R(i,n) {
	    int s; cin >> s;
	    oc[s] ++;
	}
	
	vl a = trans(Subset());
	vl b = trans(oc);
	vl c = trans(FWHT::conv(oc,oc));
	// prin(a); prin(b); prin(c);
	vl fin = andConv::conv(a,andConv::conv(b,c));
	
	ll ans = 0;
	F0R(i,17) ans = (ans+fin[1<<i])%MOD;
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!