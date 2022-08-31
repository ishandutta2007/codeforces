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
const int MX = 100001;

set<int> cur[2];
vi ret[200000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int ans = 0;
    for (char c: s) {
        if (c == '0') ans ++;
        else ans --;
    }
    F0R(i,ans) cur[1].insert(i);
    
    int co = 0;
    for (char c: s) {
        if (c == '0') {
            if (!sz(cur[1])) {
                cout << -1;
                return 0;
            }
            int x = *cur[1].begin(); cur[1].erase(x);
            cur[0].insert(x);
            ret[x].pb(++co);
        } else {
            if (!sz(cur[0])) {
                cout << -1;
                return 0;
            }
            int x = *cur[0].begin(); cur[0].erase(x);
            cur[1].insert(x);
            ret[x].pb(++co);
        }
    }
    cout << ans << "\n";
    F0R(i,ans) {
        cout << sz(ret[i]) << " ";
        for (int j: ret[i]) cout << j << " ";
        cout << "\n";
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)