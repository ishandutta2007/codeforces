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

int n,p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> n >> p >> s;
    bool bad = 0;
    F0R(i,sz(s)-p) {
        if (s[i] != '.' && s[i+p] != '.' && s[i] != s[i+p]) bad = 1;
        if (!bad) {
            if (s[i] == '.') {
                if (s[i+p] == '.') s[i] = '1', s[i+p] = '0';
                else if (s[i+p] == '1') s[i] = '0';
                else s[i] = '1';
                bad = 1;
            } else if (s[i+p] == '.') {
                if (s[i] == '0') s[i+p] = '1';
                else s[i+p] = '0';
                bad = 1;
            }
        }
    }
    F0R(i,sz(s)) if (s[i] == '.') s[i] = '0';
    if (bad) cout << s;
    else cout << "NO";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS