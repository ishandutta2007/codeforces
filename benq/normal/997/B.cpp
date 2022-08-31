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

ll n;

int solve(int n) {
    
    bitset<10000> posi; posi[0] = 1;
    F0R(i,n) posi = (posi<<1)|(posi<<5)|(posi<<10)|(posi<<50);
    int cur = 480;
    while (posi[cur+1]) cur ++;
    int CUR = cur;
    while (posi[CUR-1]) CUR --;
    return posi.count();
    // cout << cur << " " << CUR << " " << n << " " << 50*n << "\n";
    // F0R(i,10000) if (posi[i]) cout << i << "\n";
}

ll smart(ll n) {
    if (n <= 11) return solve(n);
    return 49*(n-11)+solve(11);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cout << smart(n);
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS