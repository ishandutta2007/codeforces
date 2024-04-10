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
const int MX = 200001;

int t;
string s;
ll val[MX];

ll po10(int k) {
    ll z = 1; F0R(i,k) z *= 10;
    return z;
}

bool ok(int k, int lef) {
    if (__builtin_popcount(lef) > sz(s)-k) return 0;
    int z = 0; FOR(i,1,10) if (lef&(1<<i)) z = 10*z+i;
    // cout << "AH " << k << " " << z << " " << val[k] << "\n";
    return z < val[k];
}

bool search(int k, int lef) {
    // cout << "A " << k << "\n";
    if (!ok(k,lef)) return 0;
    // cout << "B " << k << "\n";
    if (search(k+1,lef^(1<<(s[k]-'0')))) return 1;
    
    if (k == 0 && s[0] == '1') {
        F0R(i,sz(s)-2) cout << '9';
        cout << "\n";
    } else {
        if (__builtin_popcount(lef) == sz(s)-k) {
            cout << s.substr(0,k);
            F0Rd(i,10) if (lef&(1<<i)) if (i < s[k]-'0') {
                cout << i; lef ^= 1<<i;
                F0Rd(j,10) if (lef&(1<<j)) cout << j;
                break;
            }
            cout << "\n";
        } else {
            char ans[sz(s)];
            F0R(i,k) ans[i] = s[i];
            ans[k] = s[k]-1;
            lef ^= (1<<(s[k]-1-'0'));
            
            int nex = sz(s);
            F0R(i,10) if (lef&(1<<i)) ans[--nex] = '0'+i;
            FOR(i,k+1,nex) ans[i] = '9';
            F0R(i,sz(s)) cout << ans[i];
            cout << "\n";
        }
    }
    return 1;
}

void solve() {
    cin >> s;
    val[sz(s)] = 0;
    F0Rd(i,sz(s)) {
        val[i] = val[i+1];
        char c = s[i];
        if (c != '0') {
            if (i < sz(s)-12) val[i] = INF;
            else val[i] += po10(sz(s)-1-i)*(c-'0');
        }
    }
    search(0,0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    /*FOR(i,12,10000) if (sz(to_string(i))% 2 == 0) {
        s = to_string(i);
        cout << i << " ";
        solve();
        
    }*/
    F0R(i,t) solve();
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)