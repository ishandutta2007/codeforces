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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

array<ll,4> operator+(const array<ll,4>& l, const array<ll,4>& r) {
    array<ll,4> x;
    F0R(i,4) x[i] = (l[i]+r[i])%MOD;
    return x;
}
 
array<ll,4> operator-(const array<ll,4>& l, const array<ll,4>& r) {
    array<ll,4> x;
    F0R(i,4) x[i] = (l[i]-r[i]+MOD)%MOD;
    return x;
}

array<ll,4> operator*(const array<ll,4>& l, const ll& r) {
    array<ll,4> x;
    F0R(i,4) x[i] = l[i]*r%MOD;
    return x;
}

array<ll,4> operator*(const array<ll,4>& l, const array<ll,4>& r) {
    array<ll,4> x;
    F0R(i,4) x[i] = l[i]*r[i]%MOD;
    return x;
}
    
struct hsh {
    string S; 
    vector<array<ll,4>> po, ipo, cum;
    array<ll,4> base = {rand()%MOD,rand()%MOD,rand()%MOD,rand()%MOD}, invbase;

    ll modpow(ll b, ll p) {
        return !p?1:modpow(b*b%MOD,p/2)*(p&1?b:1)%MOD;
    }
    
    ll inv(ll x) {
        return modpow(x,MOD-2);
    }
    
    void gen(string _S) {
        S = _S;
        po.resize(sz(S)), ipo.resize(sz(S)), cum.resize(sz(S)+1);
        po[0] = ipo[0] = {1,1,1};
        invbase = {inv(base[0]),inv(base[1]),inv(base[2]),inv(base[3])};
        FOR(i,1,sz(S)) {
            po[i] = po[i-1]*base;
            ipo[i] = ipo[i-1]*invbase;
        }
        F0R(i,sz(S)) cum[i+1] = cum[i]+po[i]*(ll)(S[i]-'a'+1);
    }
    
    array<ll,4> get(int l, int r) {
        return ipo[l]*(cum[r+1]-cum[l]);
    }
};

hsh H;
int n;
int ans[1000000];

void ad(int x) {
    int X = n-1-x;
    int lo = -1, hi = x;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (H.get(x-mid,x+mid) == H.get(X-mid,X+mid)) lo = mid;
        else hi = mid-1;
    }
    if (lo != -1) ans[x-lo] = max(ans[x-lo],2*lo+1);
}

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; F0R(i,n) ans[i] = -1;
    string t; cin >> t; 
    H.gen(t);
    for (int i = 0; i < n-1-i; ++i) ad(i);
    for (int i = 0; i <= n-1-i; ++i) {
        if (i) ans[i] = max(ans[i],ans[i-1]-2);
        cout << ans[i] << " ";
    }
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)