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
const int MX = 100005;

int n,m, ans, cum[MX], a[MX], b[MX];

void gen() {
    vi bes = {0};
    FOR(i,1,m+1) {
        int x = cum[i];
        
        int lo = 0, hi = sz(bes)-1;
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            if (bes[mid] <= x) lo = mid;
            else hi = mid-1;
        }
        if (lo == sz(bes)-1) bes.pb(0);
        bes[lo+1] = x;
        a[i] = lo+1;
    }
    bes = {0};
    FORd(i,1,m+1) {
        int x = cum[i];
        
        int lo = 0, hi = sz(bes)-1;
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            if (bes[mid] <= x) lo = mid;
            else hi = mid-1;
        }
        if (lo == sz(bes)-1) bes.pb(0);
        bes[lo+1] = x;
        b[i] = lo+1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) {
        int l,r; cin >> l >> r;
        cum[l] ++, cum[r+1] --;
    }
    FOR(i,1,m+1) cum[i] += cum[i-1];
    gen();
    FOR(i,1,m+1) {
        // cout << a[i] << " " << b[i] << "\n";
        ans = max(ans,a[i]+b[i]-1);
    }
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)