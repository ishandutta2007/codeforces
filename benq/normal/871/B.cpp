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

int n, p[5000], b[5000];
vi x;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    // int x = P[a]^D[b]; 
    int x; cin >> x; 
    return x;
}

void test(int ind) {
    F0R(i,n) p[i] ^= ind, b[i] ^= ind;
    bool ok = 1;
    F0R(i,n) if (p[i] > n-1 || b[p[i]] != i) {
        ok = 0;
        break;
    }
    F0R(i,n) p[i] ^= ind, b[i] ^= ind;
    if (ok) x.pb(ind);
}

int main() {
	cin >> n;
	F0R(i,n) b[i] = query(0,i);
	F0R(i,n) p[i] = query(i,0)^b[0];
	F0R(i,n) test(i);
	cout << "!" << endl;
	cout << x.size() << endl;
	F0R(i,n) cout << (p[i]^x[0]) << " ";
	cout << endl;
}

// read!
// ll vs. int!