#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<int,int> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<int> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

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
#define aint(x) x.begin(), x.end()

const int MOD = 1000000007;
const int INF = 1e18;
const int MX = 100001;


vpi fac(int x) {
    vpi pri;
    
    for (int i = 2; i*i <= x; ++i) if (x % i == 0) {
        int t = 0;
        while (x % i == 0) x /= i, t ++;
        pri.pb({i,t});
    }
    
    if (x > 1) pri.pb({x,1});
    return pri;
}

int t, numFac[MX];
vl v(3);

int brute() {
    int ans = 0;
    FOR(i,1,21) FOR(j,i,21) FOR(k,j,21) {
        vi x = {i,j,k};
        bool ok = 0;
        do {
            if (v[0] % x[0] != 0) continue;
            if (v[1] % x[1] != 0) continue;
            if (v[2] % x[2] != 0) continue;
            ok = 1;
            break;
        } while (next_permutation(aint(x)));
        if (ok) ans ++;
    }
    return ans;
}

int gen2() {
    int ans = 0;
    vector<vl> x; 
    x.pb({__gcd(v[0],v[1]),v[2]});
    x.pb({__gcd(v[1],v[2]),v[0]});
    x.pb({__gcd(v[2],v[0]),v[1]});
    
    FOR(i,1,8) {
        vl tmp(2);
        F0R(j,3) if (i&(1<<j)) {
            F0R(k,2) tmp[k] = __gcd(tmp[k],x[j][k]);
        }
        if (__builtin_popcount(i)&1) ans += numFac[tmp[0]]*numFac[tmp[1]];
        else ans -= numFac[tmp[0]]*numFac[tmp[1]];
    }
    
    return ans;
}

int gen3() {
    int ans = 0;
    vector<vi> V;
    F0R(i,3) F0R(j,3) F0R(k,3) if (i != j && j != k && k != i) V.pb({i,j,k});
    int g[8];
    F0R(i,8) {
        g[i] = 0;
        F0R(j,3) if (i&(1<<j)) g[i] = __gcd(g[i],v[j]);
    }
    assert(sz(V) == 6);
    FOR(i,1,64) {
        vi tmp(3);
        F0R(j,6) if (i&(1<<j)) {
            F0R(k,3) tmp[k] |= 1<<V[j][k];
        }
        F0R(i,3) tmp[i] = g[tmp[i]];
        if (__builtin_popcount(i)&1) ans += numFac[tmp[0]]*numFac[tmp[1]]*numFac[tmp[2]];
        else ans -= numFac[tmp[0]]*numFac[tmp[1]]*numFac[tmp[2]];
    }
    return ans;
}

int solve() {
    sort(aint(v));
    
    int num1 = numFac[__gcd(__gcd(v[0],v[1]),v[2])];
    
    int tmp = gen2();
    int num2 = tmp-num1;
    
    tmp = gen3();
    int num3 = (tmp-3*num2-num1)/6;
    return num1+num2+num3;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    FOR(i,1,MX) {
        vpi v = fac(i);
        numFac[i] = 1;
        for (auto a: v) numFac[i] *= a.s+1;
    }
    /*int z = 100000;
    F0R(i,100000) {
        v[0] = rand() % z+1;
        v[1] = rand() % z+1;
        v[2] = rand() % z+1;
        solve();
    }*/
    
    cin >> t;
    F0R(i,t) {
        F0R(i,3) cin >> v[i];
        cout << solve() << "\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (int vs int?)
* array bounds
*/