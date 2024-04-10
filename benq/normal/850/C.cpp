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

map<int,int> fac;
map<int,int> vals;
int n, ans = 0;

void process(int x) {
    for (int i = 2; i*i <= x; ++i) if (x % i == 0) {
        int f = 0;
        while (x % i == 0) x /= i, f++;
        fac[i] |= 1<<f;
    }   
    if (x != 1) fac[x] |= (1<<1);
}

int get(int x) {
    if (x == 0) return 0;
    if (vals.count(x)) return vals[x];
    set<int> cur;
    FOR(i,1,30) if ((1<<i) <= x) {
        int x1 = (x%(1<<i))|(x>>i);
        if (x1&1) x1 ^= 1;
        cur.insert(get(x1));
    }
    for (int i = 0;;++i) if (cur.find(i) == cur.end()) return vals[x] = i;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int a; cin >> a;
	    process(a);
	}
	for (auto a: fac) ans ^= get(a.s);
	if (ans == 0) cout << "Arpa";
	else cout << "Mojtaba";
}

// read!
// ll vs. int!