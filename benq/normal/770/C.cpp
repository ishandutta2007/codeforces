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

int N,K, in[100001], need[100001];
vi S, res, adj[100001], radj[100001];
vi co, ans;

void process(int ind) {
    if (need[ind]) return;
    need[ind] = 1;
    co.pb(ind);
    for (int i: adj[ind]) process(i);
}

void topo() {
    queue<int> todo;
    FOR(i,1,N+1) if (need[i]) {
        in[i] = adj[i].size();
        if (in[i] == 0) todo.push(i);
    }
    while (todo.size()) {
        int x = todo.front(); todo.pop();
        ans.pb(x);
        for (int i: radj[x]) if (need[i]) {
            in[i] --;
            if (in[i] == 0) todo.push(i);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> K; S.resize(K);
	F0R(i,K) cin >> S[i];
	FOR(i,1,N+1) {
	    int x; cin >> x;
	    F0R(j,x) {
	        int y; cin >> y;
	        adj[i].pb(y);
	        radj[y].pb(i);
	    }
	}
	
	for (int i: S) process(i);
	topo();
	if (co.size() != ans.size()) {
	    cout << -1;
	    return 0;
	}
	cout << ans.size() << "\n";
	for (int i: ans) cout << i << " ";
}


// read!
// ll vs. int!