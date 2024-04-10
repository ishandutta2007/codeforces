#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		

int n, t[(1 << 20)];
int dp[(1 << 22) + 1], N = (1 << 22);

int main() {
	ios
	cin >> n;
	FOR(i, 1, n)
		cin >> t[i];
	FOR(i, 0, N)
		dp[i] = -1;
	FOR(i, 1, n)
		dp[t[i]] = t[i];
	FOR(i, 0, 21)
		FOR(j, 0, N)
			if(((1 << i) & j) && dp[j ^ (1 << i)] != -1)
				dp[j] = dp[j ^ (1 << i)];
	FOR(i, 1, n)
		cout << dp[((1 << 22) - 1 - t[i])] << " ";
	
	
	
	return 0;
}