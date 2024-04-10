/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, q, ans[1501][26]; 
string s;
//
void solve(int m, char c) {
	int R = -1, cm = 0;
	F0R(L,s.length()) {
		if (L != 0 && R >= L-1 && s[L-1] != c) cm --;
		R = max(R,L-1);
		while (R < (int)s.length()-1 && (s[R+1] == c || cm < m)) {
			R++;
			if (s[R] != c) cm++;
		}
		ans[m][c-'a'] = max(ans[m][c-'a'],R-L+1);
	}
}

int main() {
	cin >> n >> s >> q;
	F0R(i,q) {
		int m; char c; cin >> m >> c;
		if (ans[m][c-'a'] == 0) solve(m,c);
		cout << ans[m][c-'a'] << "\n";
	}
}