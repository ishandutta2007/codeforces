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

int N,A,B, nex = 1;

void solve(int a, int b) {
    F0R(i,a) {
        vi cur;
        F0R(j,A) cur.pb(nex++);
        F0R(j,A) cout << cur[(j+1)%sz(cur)] << " ";
    }
    F0R(i,b) {
        vi cur;
        F0R(j,B) cur.pb(nex++);
        F0R(j,B) cout << cur[(j+1)%sz(cur)] << " ";
    }
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B;
    for (int i = 0; i*A <= N; ++i) if ((N-i*A) % B == 0) solve(i,(N-i*A)/B);
    cout << -1;
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)