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

int R,C, xdir[4] = {0,1,0,-1}, ydir[4] = {1,0,-1,0};
char g[500][500];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C; F0R(i,R) F0R(j,C) cin >> g[i][j];
    F0R(i,R) F0R(j,C) if (g[i][j] == 'S') 
        F0R(k,4) {
            int I = i+xdir[k], J = j+ydir[k];
            if (I >= 0 && I < R && J >= 0 && J < C && g[I][J] == 'W') {
                cout << "No";
                return 0;
            }
        }
    cout << "Yes\n";
    F0R(i,R) {
        F0R(j,C) {
            if (g[i][j] == '.') cout << 'D';
            else cout << g[i][j];
        }
        cout << "\n";
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)