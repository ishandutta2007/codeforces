#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
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
const int MX = 1000001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

ll n,a[MX],p[MX],res[MX],num[MX],ans[MX];
ll sum = 0;

void ad(ll x) {
    ll t = sum/__gcd(sum,x);
    if (t <= n) num[t] ++;
}

void AD(ll& a, ll b) {
    a = (a+b)%MOD;
}

int main() {
    io();
    cin >> n; 
    FOR(i,1,n+1) {
        // a[i] = rand() % MOD; 
        cin >> a[i];
        sum += a[i];
    }
    FOR(i,2,n+1) {
        // p[i] = i-1;
        cin >> p[i];
    }
    FORd(i,1,n+1) {
        res[i] += a[i];
        res[p[i]] += res[i];
        ad(res[i]);
    }
    FORd(i,1,n+1) for (int j = 2*i; j <= n; j += i) num[j] += num[i];
    ans[1] = 1;
    ll ANS = 0;
    FOR(i,1,n+1) if (num[i] == i) {
        AD(ANS,ans[i]);
        for (int j = 2*i; j <= n; j += i) AD(ans[j],ans[i]);
    }
    cout << ANS;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/