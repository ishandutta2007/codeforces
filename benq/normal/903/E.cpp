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

int k,n, dif[5000];
string s[5000], S[5000];
set<char> z;
bool ok0 = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> k >> n;
	F0R(i,k) {
	    cin >> s[i];
	    S[i] = s[i];
	    for (char c: s[i]) z.insert(c);
	    sort(all(S[i]));
	    if (i > 0 && S[i] != S[i-1]) {
	        cout << -1;
	        return 0;
	    }
	}
	if (sz(z) != n) ok0 = 1;
	F0R(i,k) F0R(j,n) if (s[0][j] != s[i][j]) dif[i] ++;
	F0R(i,n) FOR(j,i+1,n) {
	    bool ok = 1;
	    FOR(a,1,k) {
	        int d = dif[a]-(s[a][i]!=s[0][i])+(s[a][j]!=s[0][i])-(s[a][j]!=s[0][j])+(s[a][i]!=s[0][j]);
	        if (!(d == 2 || (d == 0 && ok0))) {
	            ok = 0;
	            break;
	        }
	    }
	    if (ok) {
	        swap(s[0][i],s[0][j]);
	        cout << s[0];
	        return 0;
	    }
	}
	cout << -1;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!