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
 
const int MOD = 1000000007;
 
pii edge[4];
ll ans = 0,n,m;
map<int,int> co, posi;
vector<pii> z;

int getsz(int x) {
    int po2 = 1; while (po2 < n) po2 *= 2;
    ll lo = x, hi = x;
    while (2*hi <= po2) lo *= 2, hi *= 2, hi++;
    ll ans = hi-lo;
    hi = min(hi,n);
    if (hi >= lo) ans += hi-lo+1;
    return ans;
}

ll dfs1(int x) {
    ll tmp = 1;
    if (x > 1 && !co.count(x/2)) {
        co[x/2] ++;
        tmp += dfs1(x/2);
        co.erase(x/2);
    }
    if (2*x <= n && !co.count(2*x)) {
        if (!posi.count(2*x)) tmp += getsz(2*x);
        else {
            co[2*x] ++;
            tmp += dfs1(2*x);
            co.erase(2*x);
        }
    }
    if (2*x+1 <= n && !co.count(2*x+1)) {
        if (!posi.count(2*x+1)) tmp += getsz(2*x+1);
        else {
            co[2*x+1] ++;
            tmp += dfs1(2*x+1);
            co.erase(2*x+1);
        }
    }
    return tmp;
}

void dfs0(int x) {
    ans += dfs1(z[z.size()-1].s);
    if (x > 1 && !co.count(x/2)) {
        co[x/2] ++;
        dfs0(x/2);
        co.erase(x/2);
    }
    if (2*x <= n && !co.count(2*x)) {
        if (!posi.count(2*x)) ans = (ans+getsz(2*x)*dfs1(z[z.size()-1].s)) % MOD;
        else {
            co[2*x] ++;
            dfs0(2*x);
            co.erase(2*x);
        }
    }
    if (2*x+1 <= n && !co.count(2*x+1)) {
        if (!posi.count(2*x+1)) ans = (ans+getsz(2*x+1)*dfs1(z[z.size()-1].s)) % MOD;
        else {
            co[2*x+1] ++;
            dfs0(2*x+1);
            co.erase(2*x+1);
        }
    }
}

void ad(int a, int b) {
    while (a != b) {
        if (a > b) swap(a,b);
        co[b] ++; b /= 2;
    }
    co[a] ++;
}

void pro(int x) {
    while (x) {
        posi[x] = 1;
        x /= 2;
    }
}

void process() {
    co.clear(), posi.clear();
    F0R(i,z.size()-1) ad(z[i].s,z[i+1].f);
    co[z[0].f] ++, co[z[z.size()-1].s] ++;
    for (auto a: co) if (a.s > 1) return;
    F0R(i,z.size()) pro(z[i].f), pro(z[i].s);
    dfs0(z[0].f);
}
 
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m; ans = n*n;
    F0R(i,m) cin >> edge[i].f >> edge[i].s;
    FOR(i,1,1<<m) {
        vector<pii> x;
        F0R(j,m) if (i&(1<<j)) x.pb(edge[j]);
        F0R(j,1<<x.size()) {
            z = x;
            F0R(k,x.size()) if (j&(1<<k)) swap(z[k].f,z[k].s);
            sort(z.begin(),z.end());
            do { process(); } while (next_permutation(z.begin(),z.end()));
        }
    }
    cout << ans;
}
 
// read!
// ll vs. int!