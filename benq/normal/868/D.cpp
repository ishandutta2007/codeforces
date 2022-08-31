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

int n, m;
string s[101];
string fst[201], lst[201];
bool ok[201][11][1024];

void process(int ind, string s) {
    if (s.length() > 10) return;
    int ans = 0;
    F0R(i,s.length()) if (s[i] == '1') ans ^= (1<<i);
    ok[ind][s.length()][ans] = 1;
}

void fin(int x) {
    FORd(j,1,11) {
        bool z = 1;
        F0R(k,1<<j) if (!ok[x][j][k]) {
            z = 0;
            break;
        }
        if (z) {
            cout << j << "\n";
            return;
        }
    }
    cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; 
	FOR(i,1,n+1) {
	    cin >> s[i];
	    fst[i] = lst[i] = s[i];
	    if (fst[i].length() > 10) fst[i] = fst[i].substr(0,10);
	    if (lst[i].length() > 10) lst[i] = lst[i].substr(lst[i].length()-10,10);
	    
	    F0R(j,s[i].length()) FOR(k,j,s[i].length()) process(i,s[i].substr(j,k-j+1));
	}
	cin >> m;
	FOR(i,n+1,n+m+1) {
	    int a,b; cin >> a >> b;
	    FOR(j,1,11) F0R(k,1<<j) ok[i][j][k] = ok[a][j][k]|ok[b][j][k];
	    F0R(i1,lst[a].length()) F0R(j1,fst[b].length()) if (lst[a].length()-i1+j1+1 <= 10) {
	        process(i,lst[a].substr(i1,lst[a].length()-i1)+fst[b].substr(0,j1+1));
	    }
	    fst[i] = fst[a]+fst[b];
	    if (fst[i].length() > 10) fst[i] = fst[i].substr(0,10);
	    lst[i] = lst[a]+lst[b];
	    if (lst[i].length() > 10) lst[i] = lst[i].substr(lst[i].length()-10,10);
 	    fin(i);
	}
}

// read!
// ll vs. int!