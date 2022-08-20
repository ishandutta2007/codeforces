
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

int w,l,a[MX],cur[MX], A[MX];

bool ok(int mid) {
    F0R(i,w) {
        cur[i] = 0;
        A[i] = a[i];
    }
    cur[0] = mid;
    int nex = 0;
    F0R(i,w) {
        nex = max(nex,i+1);
        while (cur[i]) {
            while (nex < w && !A[nex]) nex ++;
            if (nex-i > l) return 0;
            if (nex == w) return 1;
            int z = min(cur[i],A[nex]);
            cur[i] -= z, cur[nex] += z, A[nex] -= z;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> w >> l;
    FOR(i,1,w) cin >> a[i];
    int lo = 0, hi = 1000000000;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (ok(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)