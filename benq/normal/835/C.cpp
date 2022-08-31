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

int arr[11][101][101]; // each max brightness, each mod,

int query(int cur, int x1, int x2, int y1, int y2) {
    return arr[cur][x2][y2]-arr[cur][x1-1][y2]-arr[cur][x2][y1-1]+arr[cur][x1-1][y1-1];
}

int main () {
	int n,q,c; cin >> n >> q >> c;
	for (int i = 0; i < n; ++i) {
	    int x,y,s; cin >> x >> y >> s;
	    for (int j = 0; j < c+1; ++j) arr[j][x][y] += ((s+j)%(c+1));
	}
	
	for (int i = 0; i < 11; ++i) 
	    for (int j = 1; j < 101; ++j)
	        for (int k = 1; k < 101; ++k) {
	            arr[i][j][k] += (arr[i][j-1][k]+arr[i][j][k-1]-arr[i][j-1][k-1]);
	        }
	        
	for (int i = 0; i < q; ++i) {
	    int t, x1, y1, x2, y2;
	    cin >> t >> x1 >> y1 >> x2 >> y2;
	    cout << query(t%(c+1),x1,x2,y1,y2) << "\n";
	}
}
// read!
// ll vs. int!