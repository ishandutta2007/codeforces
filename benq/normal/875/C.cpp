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

int n,m, cur[100001], done[100001];
vi num[100000], adj[100001];

void process(int ind) {
    F0R(i,min(num[ind].size(),num[ind+1].size())) if (num[ind][i] != num[ind+1][i]) {
        adj[num[ind][i]].pb(num[ind+1][i]);
        if (num[ind][i] > num[ind+1][i]) cur[num[ind][i]] = 1, cur[num[ind+1][i]] = 0;
        //cout << num[ind][i] << " " << num[ind+1][i] << "\n";
        // if the first one is zero, then the second one is zero
        return;
    }
    if (num[ind].size() > num[ind+1].size()) {
        cout << "No";
        exit(0);
    }
}

void test(int ind) {
    if (cur[ind] != 0 || done[ind]) return;
    done[ind] = 1;
    for (int i: adj[ind]) if (ind < i && cur[i] == -1) {
        cur[i] = 0;
        test(i);
    }
}

void check() {
    FOR(i,1,m+1) for (int j: adj[i]) {
        if (i > j && (cur[i] == 0 || cur[j] == 1)) {
            cout << "No";
            exit(0);
        } 
        if (i < j && (cur[i] == 0 && cur[j] == 1)) {
            cout << "No";
            exit(0);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,1,m+1) cur[i] = -1;
	F0R(i,n) {
	    int x; cin >> x;
	    F0R(j,x) {
	        int z; cin >> z;
	        num[i].pb(z);
	    }
	}
	F0R(i,n-1) process(i);
	//cout << "HI\n";
	//FOR(i,1,m+1) cout << cur[i] << "\n";
	FOR(i,1,m+1) test(i);
	FOR(i,1,m+1) if (cur[i] == -1) cur[i] = 1;
	
	check();
	cout << "Yes\n";
	vi ans; FOR(i,1,m+1) if (cur[i] == 1) ans.pb(i);
	cout << ans.size() << "\n";
	for (int i: ans) cout << i << " ";
}

// read!
// ll vs. int!