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

int n;
vi a,b;

vi shift(vi x) {
    x.insert(x.begin(),0);
    return x;
}

vi ad(vi a, vi b) {
    vi c(max(sz(a),sz(b)));
    F0R(i,sz(a)) c[i] += a[i];
    F0R(i,sz(b)) c[i] += b[i];
    F0R(i,sz(c)) c[i] %= 2;
    return c;
}

void prin(vi x) {
    cout << sz(x)-1 << "\n";
    for (int i: x) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; a = {0,1}, b = {1};
    F0R(i,n-1) {
        b = ad(b,shift(a));
        swap(a,b);
    }
    prin(a);
    prin(b);
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)