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

string s,t;
vector<vi> dp;
int nex[100001][26];
int F[100001];

void genex () {
	F[0] = F[1] = 0; // always true
  	FOR(i,2,t.length()+1) {
		int j = F[i-1];
	    for( ; ; ) {
	    	if(t[j] == t[i-1]) { 
		        F[i] = j+1; 
		        break; 
		    }
		    if(j == 0) {
		    	F[i] = 0; 
		   		break; 
		    }
		    j = F[j];
	    }
	}
	F0R(i,t.length()+1) F0R(j,26) {
		if (i < t.length() && t[i] == ('a'+j)) nex[i][j] = i+1;
		else nex[i][j] = nex[F[i]][j];
		// cout << i << " " << j << " " << nex[i][j] << "\n";
	}
}

int main() {
	cin >> s >> t; dp.resize(s.length()+1);
	F0R(i,s.length()+1) {
		dp[i].resize(t.length()+1);
		F0R(j,t.length()+1) dp[i][j] = -MOD;
	}
	genex();
	
	dp[0][0] = 0;
	
	F0R(i,s.length()) {
		if (s[i] == '?') {
			F0R(j,t.length()+1) F0R(k,26) {
				int n = nex[j][k];
				if (n == t.length()) dp[i+1][n] = max(dp[i+1][n],dp[i][j]+1);
				else dp[i+1][n] = max(dp[i+1][n],dp[i][j]);
			}
		} else {
			F0R(j,t.length()+1) {
				int n = nex[j][s[i]-'a'];
				if (n == t.length()) dp[i+1][n] = max(dp[i+1][n],dp[i][j]+1);
				else dp[i+1][n] = max(dp[i+1][n],dp[i][j]);
			}
		}
	}
	
	int ans = 0;
	F0R(j,t.length()+1) ans = max(ans,dp[s.length()][j]);
	cout << ans;
}