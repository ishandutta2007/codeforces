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
const ll INF = 1e18;
const int MX = 100001;

int n,a,b,c,d,p[5001], num[5001];
vi child[5001];

bool sol(int x, int y) {
    if (num[1] % 2 == 1) return 0;
    vi v;
    while (p[x] != 1) {
        int X = p[x];
        for (int i: child[X]) if (i != x) v.pb(num[i]);
        x = X;
    }
    while (p[y] != 1) {
        int Y = p[y];
        for (int i: child[Y]) if (i != y) v.pb(num[i]);
        y = Y;
    }
    for (int i: child[1]) if (i != x && i != y) v.pb(num[i]);
    bitset<5001> posi; posi[0] = 1;
    for (int i: v) posi |= posi<<i;
    return posi[num[1]/2-1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b >> c >> d;
    FOR(i,2,n+1) {
        cin >> p[i];
        child[p[i]].pb(i);
    }
    FORd(i,1,n+1) {
        if (sz(child[i]) == 0) num[i] ++;
        num[p[i]] += num[i];
    }
    if (sol(a,c) && sol(b,d)) cout << "YES";
    else cout << "NO";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)