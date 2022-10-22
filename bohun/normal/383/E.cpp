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

const int nax = (1 << 24) + 1, N = (1 << 24);
int n;
int dp[nax];
string s[10001];
ll ans = 0;

int main() {
	ios
	cin >> n;
	FOR(i, 1, n) {
		cin >> s[i];
		ll maska = 0;
		FOR(j, 0, 2)
			maska |= (1 << (s[i][j] - 'a'));
		dp[maska]++;
	}
	FOR(j, 0, 23)
		FOR(i, 0, N)
			if((1 << j) & i)
				dp[i] += dp[i ^ (1 << j)];
	FOR(i, 0, N - 1) {
		int bad = n - dp[N - 1 - i];
		ans ^= (ll) bad * bad;
	}
	cout << ans;
	
	
	
	
	
	return 0;
}