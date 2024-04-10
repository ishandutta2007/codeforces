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

int xdir[4] = {1,0,-1,0}, ydir[4] = {0,1,0,-1};
int n,m,ans;
char g[50][50];
pii st;
string z;

bool valid (pii cur) {
    if (cur.f < 0 || cur.f >= n || cur.s < 0 || cur.s >= m) return 0;
    if (g[cur.f][cur.s] == '#') return 0;
    return 1;
}

void test(vi v) {
    pii cur = st;
    for (char c: z) {
        int C = int(c-'0');
        cur.f += xdir[v[C]], cur.s += ydir[v[C]];
        if (!valid(cur)) return;
        if (g[cur.f][cur.s] == 'E') {
            // cout << "HI " << cur.f << " " << cur.s << "\n";
            ans ++;
            return;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    F0R(i,n) F0R(j,m) {
        cin >> g[i][j];
        if (g[i][j] == 'S') st = {i,j};
    }
    cin >> z;
	vi v = {0,1,2,3};
	do {
	    test(v);
	} while (next_permutation(all(v)));
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!