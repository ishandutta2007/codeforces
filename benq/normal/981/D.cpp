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

int n,k;
bool tmp[51][51];
ll A[51];

bool posi(ll x) {
	F0R(j,k+1) F0R(i,n+1) tmp[i][j] = 0;
	tmp[0][0] = 1;
	FOR(j,1,k+1) FOR(i,1,n+1) {
		ll sum = 0;
		for (int I = i; I > 0; I--) {
			sum += A[I];
			if ((sum&x) == x) tmp[i][j] |= tmp[I-1][j-1];
		}
	}
	return tmp[n][k];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    FOR(i,1,n+1) cin >> A[i];
    ll x = 0;
	F0Rd(i,60) if (posi(x^(1LL<<i))) x ^= (1LL<<i);
	cout << x;
}