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

template<class T> pair<T,T> operator+(const pair<T,T>& l, const pair<T,T>& r) {
    return {(l.f+r.f)%MOD,(l.s+r.s)%MOD};
}
 
template<class T> pair<T,T> operator-(const pair<T,T>& l, const pair<T,T>& r) {
    return {(l.f-r.f+MOD)%MOD,(l.s-r.s+MOD)%MOD};
}
 
template<class T> pair<T,T> operator*(const pair<T,T>& l, const T& r) {
    return {l.f*r%MOD,l.s*r%MOD};
}

template<class T> pair<T,T> operator*(const pair<T,T>& l, const pair<T,T>& r) {
    return {l.f*r.f%MOD,l.s*r.s%MOD};
}

array<pl,26> operator-(const array<pl,26>& a, const array<pl,26>& b) {
    array<pl,26> c; F0R(i,26) c[i] = a[i]-b[i];
    return c;
}

array<pl,26> operator*(const pl& a, const array<pl,26>& b) {
    array<pl,26> c; F0R(i,26) c[i] = b[i]*a;
    return c;
}

struct hsh {
    string S; 
    vector<pl> po, ipo;
    vector<array<pl,26>> cum;
    pl base = mp(948392576,573928192), invbase = mp(499499562,829828935);

    ll modpow(ll b, ll p) {
        return !p?1:modpow(b*b%MOD,p/2)*(p&1?b:1)%MOD;
    }
    
    ll inv(ll x) {
        return modpow(x,MOD-2);
    }
    
    void gen(string _S) {
        S = _S;
        po.resize(sz(S)), ipo.resize(sz(S)), cum.resize(sz(S)+1);
        po[0] = ipo[0] = {1,1};
        
        base.s = rand() % MOD; invbase.s = inv(base.s);
        FOR(i,1,sz(S)) {
            po[i] = po[i-1]*base;
            ipo[i] = ipo[i-1]*invbase;
        }
        F0R(i,sz(S)) {
            cum[i+1] = cum[i];
            cum[i+1][S[i]-'a'] = cum[i+1][S[i]-'a']+po[i];
        }
        //cout << "HI " << cum[2][0].f << " " << cum[2][0].s << "\n";
        //cout << "HI " << cum[2][1].f << " " << cum[2][1].s << "\n";
        //cout << (cum[2][1]*invbase).f << " " << (cum[2][1]*invbase).s << "\n";
    }
    
    vpl get(int l, int r) {
        array<pl,26> a = ipo[l]*(cum[r+1]-cum[l]);
        vpl z; F0R(i,26) z.pb(a[i]);
        sort(all(z));
        // F0R(i,26) cout << z[i].f << " " << z[i].s << "\n";
        return z;
    }
};

hsh H;

int n,m;

int main() {
    srand(time(0));
    cin >> n >> m;
    string t; cin >> t;
    H.gen(t);
    F0R(i,m) {
        int x,y,len; cin >> x >> y >> len;
        x--, y--;
        if (H.get(x,x+len-1) == H.get(y,y+len-1)) cout << "YES\n";
        else cout << "NO\n";
        // cout << "----\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)