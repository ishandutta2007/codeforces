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
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;

const int nax = 200000 + 111, INF = 1e9 + 111, mod = 1e9 + 7;

int n;
int t[nax];
int sum;

int main() {
	ios
	cin >> n;
	ll SUM = 0;
	ll MAKS = 0;
	FOR(i, 1, n) {
		cin >> t[i];
		SUM += t[i];
		MAKS = max(MAKS, 1ll * t[i]);
		sum = (sum + t[i]) % 2;
	}
	SUM -= MAKS;
	
	cout << (sum == 0 && (SUM >= MAKS) ? "YES" : "NO");
	
	
 
    return 0;
}