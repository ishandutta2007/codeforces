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

int h,m,s,t1,t2;
vector<double> pos;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> h >> m >> s >> t1 >> t2;
	
	if (t2 < t1) swap(t1,t2);
	
	pos.pb((h%12)+double(60*m+s)/3600);
	pos.pb(double(60*m+s)/300);
	pos.pb(double(s)/5);
	
	int ans = 2;
	for (auto a: pos) if (t1 < a && a < t2) {
	    ans --;
	    break;
	}
	for (auto a: pos) if (t2 < a || a < t1) {
	    ans --;
	    break;
	}
	if (ans > 0) cout << "YES";
	else cout << "NO";
}

// read!
// ll vs. int!