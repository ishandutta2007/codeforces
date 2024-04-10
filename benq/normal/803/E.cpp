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

pair<bool,char> dp[1001][2001];

int main() {
	dp[0][1000] = {1,'Z'};
	int n,k; cin >> n >> k;
	F0R(i,n) {
		char t; cin >> t;
		if (t == 'W') {
			FOR(j,1000-i,1000+i+1) if (abs(j-1000)<k) if (dp[i][j].f) dp[i+1][j+1] = {1,'W'};
		} else if (t == 'D') {
			FOR(j,1000-i,1000+i+1) if (abs(j-1000)<k) if (dp[i][j].f) dp[i+1][j] = {1,'D'};
		} else if (t == 'L') {
			FOR(j,1000-i,1000+i+1) if (abs(j-1000)<k) if (dp[i][j].f) dp[i+1][j-1] = {1,'L'};
		} else {
			FOR(j,1000-i,1000+i+1) if (abs(j-1000)<k) if (dp[i][j].f) {
				dp[i+1][j-1].f = dp[i+1][j].f = dp[i+1][j+1].f = 1;
				dp[i+1][j+1].s = 'W';
				dp[i+1][j].s = 'D';
				dp[i+1][j-1].s = 'L';
			}
		}
	}
	string ans;
	if (dp[n][1000+k].f) {
		pii cur = {n,1000+k};
		while (cur.f>0) {
			ans += dp[cur.f][cur.s].s;
			if (dp[cur.f][cur.s].s == 'W') cur.s --;
			else if (dp[cur.f][cur.s].s == 'L') cur.s++;
			cur.f --;
		}
		reverse(ans.begin(),ans.end());
		cout << ans;
		return 0;
	}
	if (dp[n][1000-k].f) {
		pii cur = {n,1000-k};
		while (cur.f>0) {
			ans += dp[cur.f][cur.s].s;
			if (dp[cur.f][cur.s].s == 'W') cur.s --;
			else if (dp[cur.f][cur.s].s == 'L') cur.s++;
			cur.f --;
		}
		reverse(ans.begin(),ans.end());
		cout << ans;
		return 0;
	}
	cout << "NO";
}