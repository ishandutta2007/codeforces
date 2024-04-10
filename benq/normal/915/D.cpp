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
const int MX = 501;

vi adj[MX];
int N,M, in[MX];
vi res;

bool test(int nex) {
    queue<int> todo; res.clear();
    FOR(i,1,N+1) in[i] = 0;
    FOR(i,1,N+1) for (int j: adj[i]) in[j] ++;
    FOR(i,1,N+1) if (in[i] == 0) todo.push(i);
    
    while (sz(todo)) {
        int x = todo.front(); todo.pop();
        res.pb(x);
        for (int i: adj[x]) {
            in[i] --;
            if (!in[i]) todo.push(i);
        }
    }
    if (in[nex] == 1) {
        todo.push(nex);
        in[nex] --;
    }
    while (sz(todo)) {
        int x = todo.front(); todo.pop();
        res.pb(x);
        for (int i: adj[x]) if (i != nex) {
            in[i] --;
            if (!in[i]) todo.push(i);
        }
    }
    /*for (int i: res) cout << i << " ";
    cout << "\n";
    cout << "HI " << sz(res) << " " << nex << " " << in[nex] << "\n";*/
    return sz(res) == N;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> M;
	F0R(i,M) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b);
	}
	FOR(i,1,N+1) if (test(i)) {
	    cout << "YES";
	    return 0;
	}
	cout << "NO";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!