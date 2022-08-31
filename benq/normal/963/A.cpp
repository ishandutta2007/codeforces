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

const int MOD = 1000000009;
const ll INF = 1e18;
const int MX = 100001;


    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
ll mul(ll a, ll b) { return a*b%MOD; }
ll sub(ll a, ll b) { return (a-b+MOD)%MOD; }
ll di (ll a, ll b) { return a*inv(b)%MOD; }
ll ad (ll a, ll b) { return (a+b)%MOD; }

int n,a,b,k;
string s;
ll ans = 0;

void calc(int x) {
    ll t = mul(po(a,k-1-x),po(b,x));
    ll z;
    if (po(a,k) == po(b,k)) {
        z = mul(t,mul((n+1)/k,po(a,n+1-k)));
    } else {
        z = mul(t,di(sub(po(a,n+1),po(b,n+1)),sub(po(a,k),po(b,k))));
    }
    if (s[x] == '+') ans = ad(ans,z);
    else ans = sub(ans,z);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b >> k;
    cin >> s;
    F0R(i,k) calc(i);
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)