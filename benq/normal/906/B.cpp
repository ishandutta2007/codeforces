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

int n,m;
bool swa = 0;
vector<vector<pii>> ans;

int hsh(pii a) {
    return a.f*m+a.s+1;
}

void gen() {
    vi k;
    for (int i = 0; i < n; i += 2) k.pb(i);
    for (int i = 1; i < n; i += 2) k.pb(i);
    F0R(i,n) F0R(j,m) ans[i][j] = {(k[i]+j)%n,j};
}

void special() {
    F0R(j,m) {
        int t = j/2;
        if (j&1) {
            ans[0][j] = {3,2*t+1};
            ans[1][j] = {1,2*t};
            ans[2][j] = {2,2*t+1};
            ans[3][j] = {0,2*t};
        } else {
            if (j != m-1) {
                ans[0][j] = {1,2*t+1};
                ans[1][j] = {3,2*t};
                ans[2][j] = {0,2*t+1};
                ans[3][j] = {2,2*t};
            } else {
                ans[0][j] = {1,2*t};
                ans[1][j] = {3,2*t};
                ans[2][j] = {0,2*t};
                ans[3][j] = {2,2*t};
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	if (n < m) {
	    swap(n,m);
	    swa = 1;
	}
	
	ans.resize(n); F0R(i,n) ans[i].resize(m);
	if (n == 1) { // number of rows
	    ans[0][0] = {0,0};
	} else if (n == 2) {
	    cout << "NO"; exit(0);
	} else if (n == 3) {
	    if (m <= 2) {
	        cout << "NO"; exit(0);
	    } else if (m == 3) {
	        cout << "YES\n";
	        cout << "8 1 6\n3 5 7\n4 9 2\n";
	        exit(0);
	    }
	} else if (n == 4) special();
	else gen();
	
	if (swa) {
	    vector<vector<pii>> t(m);
	    F0R(i,m) t[i].resize(n);
	    F0R(i,m) F0R(j,n) {
	        t[i][j] = ans[j][i];
	        swap(t[i][j].f,t[i][j].s);
	    }
	    ans = t;
	    swap(n,m);
	}
	cout << "YES\n";
	F0R(i,n) {
	    F0R(j,m) cout << hsh(ans[i][j]) << " ";
	    cout << "\n";
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!