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
const int MX = (1<<15)+1;

int n,m,cur, par[MX], ans;
bitset<MX> use;
vi tmp[2];
    
int get(int x) { // path compression
	if (par[x] != x) par[x] = get(par[x]);
	return par[x];
}

bool unite(int x, int y) { // union-by-rank
	x = get(x), y = get(y);
	if (x == y) return 0;
	if (rand()&1) swap(x,y);
	par[y] = x;
	return 1;
}

int nex = 0;

int getnex() {
    while (use[nex]) nex++;
    use[nex] = 1;
    return nex;
}

int con() {
    char c; cin >> c;
    if (c >= 'A') return int(c-'A')+10;
    return c-'0';
}

void process() {
    swap(tmp[0],tmp[1]);
    use.reset();
    FOR(i,1,2*m+1) par[i] = i;
    F0R(i,m) if (tmp[0][i]) use[tmp[0][i]] = 1;
    nex = 1;
    
    F0R(i,m/4) {
        int c = con();
        F0R(j,4) {
            if (c&(1<<(3-j))) {
                if (4*i+j > 0 && tmp[1][4*i+j-1]) tmp[1][4*i+j] = tmp[1][4*i+j-1];
                else {
                    tmp[1][4*i+j] = getnex();
                    ans ++;
                }
            } else tmp[1][4*i+j] = 0;
        }
    }
    F0R(i,m) if (tmp[0][i] && tmp[1][i]) ans -= unite(tmp[0][i],tmp[1][i]);
    F0R(i,m) tmp[1][i] = get(tmp[1][i]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m; 
	tmp[0].resize(m), tmp[1].resize(m);
	F0R(i,n) process();
	cout << ans;
}

// read!
// ll vs. int!