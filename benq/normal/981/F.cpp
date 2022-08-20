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
const int MX = 200001;

int n,L,a[MX],b[MX],cum[MX];

void ad(int l, int r) {
	if (l > r) return;
	while (l < 0) l += n, r += n;
	if (r >= n) {
		ad(0,r-n);
		r = n-1;
	}
	cum[l] ++ ;
	cum[r+1] --;
}

ll get(int x) {
	ll z = 0;
	while (x < 0) {
		z -= L;
		x += n;
	}
	while (x >= n) {
		z += L;
		x -= n;
	}
	return z+b[x];
}

bool ok (int mid) {
	F0R(i,n) cum[i] = 0;
	int l = -2*n, r = -2*n;
	F0R(i,n) {
		while (a[i]-mid > get(l)) l ++;
		while (a[i]+mid >= get(r+1)) r ++;
		//cout << "HI " << l << " " << r << " " << get(l) << " " << get(r) << "\n";
		ad(l-i,r-i);
	}
	F0R(i,n) {
		if (i) cum[i] += cum[i-1];
		if (cum[i] == n) return 1;
	}
	return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> L;
	F0R(i,n) cin >> b[i];
	F0R(i,n) cin >> a[i];
	sort(b,b+n);
	sort(a,a+n);
	int lo = 0, hi = L/2;
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (ok(mid)) hi = mid;
		else lo = mid+1;
	}
	cout << lo;
}