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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

int V1,V2,V3,VM;
int A1,A2,A3;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> V1 >> V2 >> V3 >> VM;
	A3 = max(VM,V3);
	A2 = max(V2,max(A3+1,2*VM+1));
	A1 = max(V1,A2+1);
	if (V1 > A1 || 2*V1 < A1) {
	    cout << -1;
	    return 0;
	}
	if (V2 > A2 || 2*V2 < A2) {
	    cout << -1;
	    return 0;
	}
	if (V3 > A3 || 2*V3 < A3) {
	    cout << -1;
	    return 0;
	}
	if (VM > A3 || 2*VM < A3) {
	    cout << -1;
	    return 0;
	}
	cout << A1 << "\n" << A2 << "\n" << A3;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!