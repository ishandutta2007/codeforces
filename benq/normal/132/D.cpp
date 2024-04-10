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

int dp[1000000][2], ori;
string n; 

int main() {
	cin >> n; ori = n.length();
	while (n[n.length()-1] == '0') n.erase(n.length()-1,1);
	F0Rd(i,n.length()) {
		if (i == n.length()-1) {
			dp[i][0] = 1;
			dp[i][1] = 1;
		} else if (n[i] == '0') {
			dp[i][0] = dp[i+1][0]; // 0
			dp[i][1] = 1+min(dp[i+1][1],dp[i+1][0]); // 1
		} else {
			dp[i][0] = 1+min(dp[i+1][0],dp[i+1][1]); // 1
			dp[i][1] = dp[i+1][1]; // 0
		}
	}
	vector<pii> ans;
	
	int cur = 0;
	F0R(i,n.length()) {
		if (i == n.length()-1) ans.pb({cur,i});
		else if (n[i] == '0') {
			if (cur == 0) continue;
			else {
				// cur == 1
				if (dp[i+1][1]<dp[i+1][0]) ans.pb({cur,i});
				else {
					ans.pb({cur,i-1});
					cur = 0;
				}
			}
		} else {
			if (cur == 1) continue;
			else {
				if (dp[i+1][0]<dp[i+1][1]) ans.pb({cur,i});
				else {
					ans.pb({cur,i-1});
					cur = 1;
				}
			}
		}
	}
	
	cout << dp[0][0] << "\n";
	for (auto i: ans) {
		if (i.f % 2 == 0) cout << '+';
		else cout << '-';
		cout << "2^" << ori-1-i.s << "\n";
	}
}