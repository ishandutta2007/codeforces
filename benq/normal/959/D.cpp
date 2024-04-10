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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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

int n;
vi pri[200001];
bool comp[2000001], done[2000001];

int cur = 2;

int getSmallest() {
    while (comp[cur] || done[cur]) cur ++;
    return cur;
}

bool ok(int x) {
    for (int i: pri[x]) if (done[i]) return 0;
    return 1;
}

void ad(int x) {
    cout << x << " ";
    for (int i: pri[x]) done[i] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    FOR(i,2,200001) if (!sz(pri[i])) 
        for (int j = i; j <= 200000; j += i) 
            pri[j].pb(i);
    
    FOR(i,2,2000001) if (!comp[i]) 
        for (int j = 2*i; j <= 2000000; j += i) comp[j] = 1;
    
    bool eq = 1;
    F0R(i,n) {
        int x; cin >> x;
        if (eq) {
            if (ok(x)) {
                ad(x);
            } else {
                for (int j = x+1; ; ++j) if (ok(j)) {
                    ad(j);
                    break;
                }
                eq = 0;
            }
        } else {
            int z = getSmallest(); done[z] = 1;
            cout << z << " ";
        }
    }
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)