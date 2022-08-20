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

ll k;
int A[4][4], B[4][4];
map<pii,int> lst;
pii nex[4][4], ori;
ll ans[2];

int process(pii x) {
    if (x.f == x.s) return -1;
    if (x.f == 3 && x.s == 2) return 0;
    else if (x.f == 2 && x.s == 1) return 0;
    else if (x.f == 1 && x.s == 3) return 0;
    return 1;
}

void solve(ll mult, pii tmp) {
    pii tmp1 = tmp;
    ll z[2] = {0,0};
    while (1) {
        int t = process(tmp1);
        if (t != -1) z[t] ++;
        tmp1 = nex[tmp1.f][tmp1.s];
        if (tmp1 == tmp) break;
    }
    z[0] *= mult, z[1] *= mult;
    ans[0] += z[0], ans[1] += z[1];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> k >> ori.f >> ori.s;
	FOR(i,1,4) FOR(j,1,4) cin >> A[i][j];
	FOR(i,1,4) FOR(j,1,4) cin >> B[i][j];
	
	FOR(i,1,4) FOR(j,1,4) nex[i][j] = {A[i][j], B[i][j]};
	for (ll i = 1; i <= k;) {
	    if (lst.count(ori)) {
	        int per = i-lst[ori];
	        while ((k-i)%per != 0) {
	            int t = process(ori);
	            if (t != -1) ans[t] ++;
	            ori = nex[ori.f][ori.s];
	            i++;
	        }
    	    int t = process(ori);
    	    if (t != -1) ans[t] ++;
	        ori = nex[ori.f][ori.s];
	        solve((k-i)/per,ori);
	        break;
	    }
	    int t = process(ori);
	    if (t != -1) ans[t] ++;
	    lst[ori] = i;
	    ori = nex[ori.f][ori.s];
	    i++;
	}
	cout << ans[0] << " " << ans[1];
}

// read!
// ll vs. int!