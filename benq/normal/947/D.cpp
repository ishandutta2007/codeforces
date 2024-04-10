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

string s[2];
int Q, cum[2][MX],lst[2][MX];

bool solve(int a, int b, int c, int d) {
    int x = max(lst[0][b+1]-1,a-1), y = max(lst[1][d+1]-1,c-1);
    int X = cum[0][b+1]-cum[0][a], Y = cum[1][d+1]-cum[1][c];
    if (X > Y || (Y-X)%2 != 0) return 0;
    
    int d1 = b-x, d2 = d-y;
    if (d1 < d2) return 0;
    
    // no BC in there 
    if ((d1-d2) % 3 == 0) if (X > 0 || X == Y) return 1;
    
    // yes BC in there
    if (d1 > d2) return X+2 <= Y;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s[0] >> s[1];
    
    F0R(i,2) {
        F0R(j,sz(s[i])) {
            cum[i][j+1] = cum[i][j], lst[i][j+1] = lst[i][j];
            
            if (s[i][j] == 'C') s[i][j] = 'B';
            if (s[i][j] == 'B') {
                lst[i][j+1] = j+1;
                cum[i][j+1] ++;
            }
        }
    }
    
    cin >> Q;
    F0R(i,Q) {
        int a,b,c,d; 
        cin >> a >> b >> c >> d;
        cout << solve(a-1,b-1,c-1,d-1);
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)