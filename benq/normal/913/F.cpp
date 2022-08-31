#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vl> mat;

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

const int MOD = 998244353;
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 2001;

ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }
ll norm (ll b) { return (b%MOD+MOD)%MOD; }

int n;
ll prob, scc[MX][MX], SCC[MX], ans[MX];

void input() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int a,b; cin >> a >> b; 
    prob = norm(a*inv(b));
}

void genSCC() {
    scc[0][0] = 1;
    FOR(i,1,n+1) {
        scc[i][0] = 1;
        FOR(j,1,i+1)  scc[i][j] = norm(scc[i-1][j-1]*po(norm(1-prob),i-j)+scc[i-1][j]*po(prob,j)); // not in
    }
    
    FOR(i,1,n+1) {
        SCC[i] = 1;
        FOR(j,1,i) SCC[i] = norm(SCC[i]-scc[i][j]*SCC[j]);
    }
    // what is the probability that there is exactly one SCC in group of size i
}

ll getProb(int i, int j) {
    return norm(scc[i][j]*SCC[j]);
}

int main() {
    input();
    genSCC();
    FOR(i,2,n+1) {
        ll b = 0;
        FOR(j,1,i+1) b = norm(b+getProb(i,j)*norm(ans[j]+ans[i-j]+j*(j-1)/2+j*(i-j)));
        ans[i] = norm(b*inv(norm(1-getProb(i,i))));
    }
    cout << ans[n];
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)