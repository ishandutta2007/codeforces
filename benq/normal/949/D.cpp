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

int n,d,b, a[MX], A[MX];
pi bo[MX];

bool ok(int mid) {
    int l = mid, r = n-1-mid;
    int x = 0; F0R(i,n) A[i] = a[i];
    FOR(i,l,r+1) {
        int rem = b;
        for (;x < n; x++) {
            if (i < bo[x].f || bo[x].s < i) continue;
            if (A[x] == 0) continue;
            int t = min(A[x],rem);
            A[x] -= t; rem -= t;
            if (rem == 0) break;
        }
        if (rem > 0) return 0;
    }
    return 1;
}

int cdiv(int x, int y) {
    return (x+y-1)/y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d >> b;
    F0R(i,n) {
        if (i) bo[i] = bo[i-1];
        while (cdiv(i-bo[i].f,d)-1 > bo[i].f) bo[i].f ++;
        while (bo[i].s+1 < n && cdiv(bo[i].s+1-i,d)-1 <= n-1-(bo[i].s+1)) bo[i].s ++;
    }
    // 0,1 
    F0R(i,n) cin >> a[i];
    int lo = 0, hi = (n+1)/2;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (ok(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo;
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)