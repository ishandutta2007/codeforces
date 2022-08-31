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

int n, n1;
vi num, pri;
ll sum[100000];

void gen() {
    n1 = n;
    for (int i = 2; i*i <= n1; ++i) if (n1 % i == 0) {
        while (n1 % i == 0) n1 /= i;
        pri.pb(i);
    }
    if (n1 > 1) pri.pb(n1);
}

void mult(int x) {
    num.resize(num.size()+x);
    F0Rd(i,num.size()-x) num[i+x] -= num[i];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; num.resize(n);
	F0R(i,n) {
	    char c; cin >> c;
	    num[i] = c-'a';
	}
	gen();
	for (int x: pri) mult(n/x);
	
	F0R(i,num.size()) sum[i%n] += num[i];
	F0R(i,n) if (sum[i] != 0) {
	    cout << "NO";
	    return 0;
	}
	cout << "YES";
}

// read!
// ll vs. int!