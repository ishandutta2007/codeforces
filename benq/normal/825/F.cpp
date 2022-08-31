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

int dp[8001][8001], ans[8001], sum[8001];
string s;

int main() {
	cin >> s;
	F0Rd(i,s.length()) F0Rd(j,s.length()) 
	    if (s[i] == s[j]) dp[i][j] = 1+dp[i+1][j+1];
	
	FOR(i,1,8001) sum[i] = to_string(i).length();
	F0R(i,s.length()) ans[i] = MOD;
	
	F0Rd(i,s.length())
	    FOR(j,1,s.length()-i+1)
	        for (int k = i+j; k <= s.length() && dp[i][k-j] >= j; k += j)
	            ans[i] = min(ans[i],ans[k]+j+sum[(k-i)/j]);
	  
	cout << ans[0];
}