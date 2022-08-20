#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;

int n,S,cst[100001];
ll tot = 0;

void test(ll mid) {
    vector<ll> tmp;
    FOR(i,1,n+1) tmp.pb(cst[i]+i*mid);
    sort(tmp.begin(),tmp.end());
    tot = 0;
    F0R(i,mid) tot += tmp[i];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> S;
	FOR(i,1,n+1) cin >> cst[i];
	int lo = 0, hi = n;
	while (lo < hi) {
	    int mid = (lo+hi+1)/2;
	    test(mid);
	    if (tot <= S) lo = mid;
	    else hi = mid-1;
	}
	test(lo);
	cout << lo << " " << tot;
}

// read!
// ll vs. int!