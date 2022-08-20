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

int n, ans = MOD;
vi w;

int test(vi w1) {
    int rem = 0;
    F0R(i,w1.size()/2) rem += w1[2*i+1]-w1[2*i];
    return rem;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; w.resize(2*n);
	F0R(i,2*n) cin >> w[i];
	sort(w.begin(),w.end());
	F0R(i,w.size()) FOR(j,i+1,w.size()) {
	    vi w1 = w;
	    w1.erase(w1.begin()+j);
	    w1.erase(w1.begin()+i);
	    ans = min(ans,test(w1));
	}
	cout << ans;
}

// read!
// ll vs. int!