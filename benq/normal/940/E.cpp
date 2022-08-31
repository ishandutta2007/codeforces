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

int n,c;
ll ans[MX],sum;
deque<pi> d;

void ins(int ind, int val) {
    sum += val;
    pi a = {val,ind};
    while (sz(d) && d.back().f >= a.f) d.pop_back();
    d.pb(a);
}

int get(int x) {
    while (d.front().s < x) d.pop_front();
    return d.front().f;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    FOR(i,1,n+1) {
        int x; cin >> x;
        ins(i,x);
        ans[i] = max(ans[i],ans[i-1]);
        if (i >= c) ans[i] = max(ans[i],ans[i-c]+get(i-c+1));
    }
    cout << sum-ans[n];
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)