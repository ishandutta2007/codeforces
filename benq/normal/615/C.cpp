#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

string s,t, revs;
int dp[2100][2100][2], curindex = 0, n = 0, x0 = 0, x1=0;
vi ans;

void filldp() {
	for (int i = s.length()-1; i >= 0; --i) {
		if (s[i] == t[t.length()-1]) dp[i][t.length()-1][0] = 1;
		if (revs[i] == t[t.length()-1]) dp[i][t.length()-1][1] = 1;
	}	
	
	for (int j = t.length()-1; j >= 0; --j) {
		if (s[s.length()-1] == t[j]) dp[s.length()-1][j][0] = 1;
		if (revs[s.length()-1] == t[j]) dp[s.length()-1][j][1] = 1;
	}
	
	for (int j = t.length()-2; j >= 0; --j) {
		for (int i = s.length()-2; i >= 0; --i) {
			if (t[j] == s[i]) {
				dp[i][j][0] = dp[i+1][j+1][0]+1;
			}
			if (t[j] == revs[i]) {
				dp[i][j][1] = dp[i+1][j+1][1]+1;
			}
		}
	}
}

int findmax(int x) {
	int ans = 0;
	F0R(i,s.length()) {
		if (dp[i][x][0] > ans) {
			ans = dp[i][x][0];
			x0 = i+1;
			x1 = i+1+ans-1;
		}
		if (dp[i][x][1] > ans) {
			ans = dp[i][x][1];
			x0 = s.length()-i;
			x1 = s.length()-i-ans+1;
		}
	}
	return ans;
}

int main() {
	cin >> s >> t;
	for(int i = s.length()-1; i >= 0; --i) revs += s[i];

	filldp();
	while (curindex<t.length()) {
		int u = findmax(curindex);
		if (u == 0) {
			cout << -1;
			return 0;
		}
		curindex += u;
		ans.pb(x0);
		ans.pb(x1);
		n++;
	}
	cout << n << endl;
	F0R(i,n) cout << ans[2*i] << " " << ans[2*i+1] << endl;
	return 0;
}