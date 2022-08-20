
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

struct Edge {
    int v;
    ll flow, C;
    int rev;
};
 
int mxbit(int x) {
    return 31-__builtin_clz(x);
}


string s;
int m, req[MX], oc[64], REQ[64];

void ad(int x, int y) {
    F0R(i,64) if ((i&x) == x) REQ[i] += y;
}

void AD(int x, int y) {
    F0R(i,64) if (i&(1<<x)) oc[i] += y;
}

bool ok() {
    F0R(i,64) if (REQ[i] > oc[i]) return 0;
    return 1;
}

void input() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> m;
    F0R(i,sz(s)) {
        req[i] = 63;
        AD(s[i]-'a',1);
    }
    F0R(i,m) {
        int a; string b; cin >> a >> b;
        int t = 0; for (char c: b) t ^= 1<<(c-'a');
        req[a-1] = t;
    }
}

int main() {
    input();
    F0R(i,sz(s)) ad(req[i],1);
    string ans;
    F0R(i,sz(s)) {
        ad(req[i],-1);
        int cur = -1;
        F0R(j,6) if (req[i]&(1<<j)) if (oc[1<<j]) {
            AD(j,-1);
            if (ok()) {
                cur = j;
                break;
            }
            AD(j,1);
        }
        if (cur == -1) {
            cout << "Impossible";
            exit(0);
        }
        ans += char('a'+cur);
    }
    cout << ans;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/