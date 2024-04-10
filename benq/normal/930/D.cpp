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
const int MX = 200100;

int n, mn[MX][2], mx[MX][2];
ll ans = 0;
vi v[2][MX];

void solve(int ind) {
    F0Rd(i,MX) {
        if (i == MX-1) {
            mx[i][0] = -MOD;
        } else {
            mx[i][0] = mx[i+1][0];
            for (auto a: v[ind][i]) mx[i][0] = max(mx[i][0],a);
        }
    }
    
    F0Rd(i,MX) {
        if (i == MX-1) {
            mn[i][0] = MOD;
        } else {
            mn[i][0] = mn[i+1][0];
            for (auto a: v[ind][i]) mn[i][0] = min(mn[i][0],a+1);
        }
    }
    
    F0R(i,MX) {
        if (i == 0) {
            mx[i][1] = -MOD;
        } else {
            mx[i][1] = mx[i-1][1];
            for (auto a: v[ind][i-1]) mx[i][1] = max(mx[i][1],a);
        }
    }
    
    F0R(i,MX) {
        if (i == 0) {
            mn[i][1] = MOD;
        } else {
            mn[i][1] = mn[i-1][1];
            for (auto a: v[ind][i-1]) mn[i][1] = min(mn[i][1],a+1);
        }
    }
    
    F0R(i,MX) if (max(mn[i][0],mn[i][1]) <= min(mx[i][0],mx[i][1])) {
        // cout << i << " " << mn[i][0] << " " << mn[i][1] << " " << mx[i][0] << " " << mx[i][1] << "\n";
        ans += min(mx[i][0],mx[i][1])-max(mn[i][0],mn[i][1])+1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        int a,b; cin >> a >> b;
        if ((a+b)&1) {
            a ++;
            v[0][(a+b)/2+100010].pb((a-b)/2);
        } else {
            v[1][(a+b)/2+100010].pb((a-b)/2);
        }
    }
    F0R(i,2) solve(i);
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)