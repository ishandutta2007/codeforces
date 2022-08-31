#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
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

pii A,B,C;

bool col (pii A, pii B, pii C) {
    B.f -= A.f, B.s -= A.s, C.f -= A.f, C.s -= A.s;
    return B.f*C.s == B.s*C.f;
}

ll dist(pii X, pii Y) {
    return (Y.f-X.f)*(Y.f-X.f)+(Y.s-X.s)*(Y.s-X.s);    
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> A.f >> A.s >> B.f >> B.s >> C.f >> C.s;
	if(col(A,B,C)) {
	    cout << "No";
	    return 0;
	}
	if (dist(A,B) == dist(B,C)) cout << "Yes";
	else cout << "No";
}

// read!
// ll vs. int!