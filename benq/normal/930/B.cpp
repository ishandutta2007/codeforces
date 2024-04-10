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

int oc[26][5000][26], co[26];
ll ans = 0;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    F0R(i,sz(s)) {
        co[s[i]-'a'] ++;
        FOR(j,1,sz(s)) oc[s[i]-'a'][j][s[(i+j)%sz(s)]-'a'] ++;
    }
    
    F0R(i,26) {
        int mx = 0;
        FOR(j,1,sz(s)) {
            int z = 0;
            F0R(k,26) if (oc[i][j][k] == 1) z ++;
            mx = max(mx,z);
        }
        ans += mx;
    }
    
    cout << fixed << setprecision(10) << (ld)ans/sz(s);
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)