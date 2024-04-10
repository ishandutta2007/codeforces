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

int n;
multiset<char> a, b;
char ans[300000];
int lst;

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string A, B; cin >> A >> B;
	n = A.length();
	F0R(i,n) a.insert(A[i]);
	while (a.size() > (n+1)/2) a.erase(prev(a.end()));
	F0R(i,n) b.insert(B[i]);
	while (b.size() > n/2) b.erase(b.begin());
}

int main() {
    init();
    lst = n-1;
    F0R(i,n) {
        if (i % 2 == 0) {
            if (b.size() > 0 && *a.begin() < *b.rbegin()) {
                ans[i] = *a.begin(); a.erase(a.begin());
            } else {
                // all elements in a >= that of b
                // put the greatest last?
                ans[lst--] = *a.rbegin(); a.erase(prev(a.end()));
            }
        } else {
            if (a.size() > 0 && *a.begin() < *b.rbegin()) {
                ans[i] = *b.rbegin();  b.erase(prev(b.end()));
            } else {
                // all elements in a >= that of b
                // put the smallest last
                ans[lst--] = *b.begin(); b.erase(b.begin());
            }
        }
    }
    F0R(i,n) cout << ans[i];
}

// read!
// ll vs. int!