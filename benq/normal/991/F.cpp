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

map<ll,string> bes;
ll n;
vector<pair<ll,string>> BES;
string ans;

string bet(string a, string b) {
    if (sz(a) < sz(b)) return a;
    return b;
}

void ad(ll x, string y) {
    if (!bes.count(x)) bes[x] = to_string(x);
    bes[x] = bet(bes[x],y);
}

void brute() {
    FOR(i,1,MX) {
        ll z = i, oc = 1;
        if (i > 1) while (z <= 1e10) {
            // cout << (to_string(i)+"^"+to_string(oc)) << "\n";
            ad(z,to_string(i)+"^"+to_string(oc));
            oc ++;
            z *= i;
        }
    }
    for (auto a: bes) BES.pb(a);
}

string need(ll x) {
    if (x == 0) return "";
    if (bes.count(x)) return "+"+bes[x];
    return "+"+to_string(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    brute();
    ans = to_string(n);
    int ind = sz(BES)-1;
    F0R(i,sz(BES)) {
        while (ind >= 0 && (ld)BES[i].f*BES[ind].f > n) ind --;
        if (BES[i].f <= n) ans = bet(ans,BES[i].s+need(n-BES[i].f));
        F0R(j,10) if (ind-j >= 0) ans = bet(ans,BES[i].s+"*"+BES[ind-j].s+need(n-BES[i].f*BES[ind-j].f));
    }
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS