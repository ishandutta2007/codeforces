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
const int MX = 1000001;

int g[MX], f[MX], cum[MX][10];
int Q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    FOR(i,1,MX) {
        string s = to_string(i);
        f[i] = 1; for (char c: s) if (c != '0') f[i] *= (c-'0');
        if (i < 10) g[i] = i;
        else g[i] = g[f[i]];
        F0R(j,10) cum[i][j] = cum[i-1][j];
        cum[i][g[i]] ++;
    }
    cin >> Q;
    F0R(i,Q) {
        int l,r,x; cin >> l >> r >> x;
        cout << cum[r][x]-cum[l-1][x] << "\n";
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)