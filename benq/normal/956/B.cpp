#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vl> mat;

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

int n,U;
vi e;
pl ans = {-1,-1};

pl bet(pl a, pl b) {
    if (a.f == -1) return b;
    if (a.f*b.s < b.f*a.s) return b;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> U;
    e.resize(n);
    F0R(i,n) cin >> e[i];
    int lo = 0;
    F0R(i,n) {
        while (lo < n-1 && e[lo+1]-e[i] <= U) lo ++;
        if (lo > i+1) ans = bet(ans,{e[lo]-e[i+1],e[lo]-e[i]});
    }
    cout << fixed << setprecision(11);
    if (ans.f == -1) cout << -1;
    else cout << (ld)ans.f/ans.s;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)