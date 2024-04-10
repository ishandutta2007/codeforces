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

int n,k;
vi p;
set<int> nex;
vi tmp[200002];
stack<int> b;
queue<int> a;

void test() {
    for (int i: p) a.push(i);
    FOR(i,1,n+1) {
        while (sz(a) && (sz(b) == 0 || b.top() != i)) {
            b.push(a.front()); 
            a.pop();
        }
        if (b.top() == i) b.pop();
        else {
            cout << -1;
            exit(0);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k; p.resize(k);
	F0R(i,k) { 
	    cin >> p[i];
	    nex.insert(p[i]);
	}
	nex.insert(n+1);
	FORd(i,1,n+1) if (!nex.count(i)) {
	    tmp[*nex.lb(i)].pb(i);
	}
	FOR(i,1,n+2) for (int j: tmp[i]) p.pb(j);
	test();
	F0R(i,n) cout << p[i] << " ";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!