#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

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
const int MX = 400001;

ll Q, lst, cnt = 0, wei[MX];
pl par[MX][19];

void upd(int p, int q) {
    wei[++cnt] = q;
    int cur = p;
    F0Rd(i,19) if (wei[par[cur][i].f] < q) cur = par[cur][i].f;
    
    if (wei[cur] < q) cur = par[cur][0].f;
    par[cnt][0] = {cur,wei[cnt]};
    FOR(i,1,19) {
        int p = par[cnt][i-1].f;
        par[cnt][i] = {par[p][i-1].f,min(INF,par[p][i-1].s+par[cnt][i-1].s)};
    }
}

int query(int r, ll x) {
    int ans = 0;
    F0Rd(i,19) if (x >= par[r][i].s) {
        x -= par[r][i].s; ans ^= 1<<i;
        r = par[r][i].f;
        // cout << "HA " << i << " " << x << " "
    }
    // cout << r << " " << x << " " << ans << "\n";
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Q;
    wei[0] = INF; F0R(i,19) par[0][i].s = INF;
    upd(0,0);
    
    F0R(i,Q) {
        int t; cin >> t;
        ll p,q; cin >> p >> q;
        p ^= lst, q ^= lst;
        if (t == 1) {
            upd(p,q);
        } else {
            lst = query(p,q);
            cout << lst << "\n";
        }
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)