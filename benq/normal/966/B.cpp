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
const int MX = 300001;

int n,x0,x1,posi[2][MX];
vpi c;

int cdiv(int x, int y) {
    return (x+y-1)/y;
}

void test(int ind) {
    F0Rd(i,n) if (n-i >= posi[ind][i]) {
        F0Rd(j,i) if (n-j >= posi[ind^1][j]+posi[ind][i]) {
            cout << "Yes\n";
            if (ind == 0) {
                cout << n-i << " " << i-j << "\n";
                F0R(k,posi[0][i]) cout << c[n-1-k].s << " ";
                cout << "\n";
                F0R(k,posi[1][j]) cout << c[j+k].s << " ";
                cout << "\n";
            } else {
                cout << i-j << " " << n-i << "\n";
                F0R(k,posi[0][j]) cout << c[j+k].s << " ";
                cout << "\n";
                F0R(k,posi[1][i]) cout << c[n-1-k].s << " ";
                cout << "\n";
            }
            exit(0);
        }
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x0 >> x1;
    F0R(i,n) {
        int x; cin >> x;
        c.pb({x,i+1});
    }
    sort(all(c));
    F0R(i,n) {
        posi[0][i] = cdiv(x0,c[i].f);
        posi[1][i] = cdiv(x1,c[i].f);
    }
    test(0);
    test(1);
    cout << "No";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)