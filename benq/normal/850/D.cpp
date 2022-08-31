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

int m, a[31], ans[61][61];
bool ok[32][62][1831][2]; // current d, current # of elements, current sum
pair<pii,pii> pre[32][62][1831][2];

void construct (vi el) {
    F0R(i,el.size()) {
        if (el[i]) {
            int co = el[i], k = el[el.size()-el[i]];
            FOR(j,i+1,el.size()) if (el[j] < k) {
                co--;
                ans[i][j] = 1; // i beats j
            }
            if (co) {
                int z = i+1; while (el[z] > k) z++;
                FOR(j,z,z+co) ans[i][j] = 1;
            }
        }
        FOR(j,i+1,el.size()) if (!ans[i][j]) {
            ans[j][i] = 1;
            el[j] --;
        }
    }
    
    cout << el.size() << "\n";
    F0R(i,el.size()) {
        F0R(j,el.size()) cout << ans[i][j];
        cout << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> m; F0R(i,m) cin >> a[i];
	sort(a,a+m);
	
	ok[0][0][0][1] = 1;
	
	F0R(i,m+1) F0R(j,62) F0R(k,1831) F0R(x,2) if (ok[i][j][k][x]) {
	    if (i != 0 && j+1 <= 61 && k+a[i-1] <= 1830 && k+a[i-1] >= (j+1)*j/2) {
	        ok[i][j+1][k+a[i-1]][1] = 1;
	        pre[i][j+1][k+a[i-1]][1] = {{i,j},{k,x}};
	    }
	    if (i != m && x == 1) { // well, you need at least one
	        ok[i+1][j][k][0] = 1;
	        pre[i+1][j][k][0] = {{i,j},{k,x}};
	    }
	}
	FOR(j,1,62) if (ok[m][j][j*(j-1)/2][1]) {
	    vi tmp;
	    pair<pii,pii> cur = {{m,j},{j*(j-1)/2,1}};
	    while (cur.f.s) {
	        auto t = pre[cur.f.f][cur.f.s][cur.s.f][cur.s.s];
	        if (t.f.s != cur.f.s) tmp.pb(cur.s.f-t.s.f);
	        cur = t;
	    }
	    construct(tmp);
	    return 0;
	} 
	cout << "=(";
}

// read!
// ll vs. int!