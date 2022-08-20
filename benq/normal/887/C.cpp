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

vi a;
vector<vi> posi = {
    {1,3,5,7,9,11,24,22},
    {2,4,6,8,10,12,23,21},
    {13,14,5,6,17,18,21,22},
    {15,16,7,8,19,20,23,24},
    {9,10,19,17,4,3,14,16},
    {11,12,20,18,2,1,13,15}
};

bool test(vi A) {
    FOR(i,1,7) for (int j = 4*i-3; j <= 4*i; ++j) if (A[j] != A[4*i]) return 0;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	a.resize(25);
	FOR(i,1,25) cin >> a[i];
	for (auto b: posi) {
	    vi A = a;
	    F0R(i,b.size()) A[b[i]] = a[b[(i+2)%8]];
	    if (test(A)) {
	        cout << "YES";
	        return 0;
	    }
	    F0R(i,b.size()) A[b[i]] = a[b[(i+6)%8]];
	    if (test(A)) {
	        cout << "YES";
	        return 0;
	    }
	}
	cout << "NO";
}

// read!
// ll vs. int!