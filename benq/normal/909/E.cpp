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

int N,M,E[100001], in[100001], ans;
queue<int> ok[2];
vi adj[100001];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> M;
	F0R(i,N) cin >> E[i];
	F0R(i,M) {
	    int T1, T2; cin >> T1 >> T2;
	    in[T1] ++; adj[T2].pb(T1);
	}
	
	F0R(i,N) if (in[i] == 0) ok[E[i]].push(i);
	while (sz(ok[0]) || sz(ok[1])) {
	    while (sz(ok[0])) {
	        int x = ok[0].front(); ok[0].pop();
	        for (int i: adj[x]) {
	            in[i] --;
	            if (in[i] == 0) ok[E[i]].push(i);
	        }
	    }
	    
	    bool z = 0;
	    while (sz(ok[1])) {
	        z = 1;
	        int x = ok[1].front(); ok[1].pop();
	        for (int i: adj[x]) {
	            in[i] --;
	            if (in[i] == 0) ok[E[i]].push(i);
	        }
	    }
	    ans += z;
	}
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!