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

int n,k,x, cur[1024], tmp[1024];

void solve() {
    memset(tmp,0,sizeof tmp);
    int cnum = 0;
    F0R(i,1024) {
        int lo = cnum+1, hi = cnum+cur[i];
        if (!(lo&1)) lo++;
        if (!(hi&1)) hi--;
        int o = (hi-lo)/2+1;
        int e = cur[i]-o;
        cnum += cur[i];
        tmp[i^x] += o;
        tmp[i] += e;
    }
    F0R(i,1024) cur[i] = tmp[i];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> x;
	F0R(i,n) {
	    int z; cin >> z;
	    cur[z] ++;
	}
	F0R(i,k) solve();
	int mx = -MOD, mn = MOD;
	F0R(i,1024) if (cur[i]) {
	    mx = i;
	    mn = min(mn,i);
	}
	cout << mx << " " << mn;
}

// read!
// ll vs. int!