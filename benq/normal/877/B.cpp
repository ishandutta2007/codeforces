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

int num[5001][2], mx = 0;
string s;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	F0R(i,s.length()) {
	    num[i+1][0] = num[i][0];
	    num[i+1][1] = num[i][1];
	    num[i+1][s[i]-'a'] ++;
	}
	F0R(i,s.length()+1) FOR(j,i,s.length()+1) {
	    int len = num[i][0]+(num[j][1]-num[i][1])+num[s.length()][0]-num[j][0];
	    // cout << i << " " << j << " " << len << "\n";
	    mx = max(mx,len);
	}
	cout << mx;
}

// read!
// ll vs. int!