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

const int nax = 1005, INF = 1e9 + 111, mod = 1e9 + 7;

int n, t[nax];
string s[nax];
int a[nax];
int ile[nax][5];

int main() {
	ios
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> s[i];
		s[i] = '2' + s[i];
		FOR(j, 1, ss(s[i]) - 1)
			ile[j][s[i][j] - 'A']++;
	}
	int ans = 0;
	FOR(i, 1, m) {
		cin >> a[i];
		int maks = 0;
		FOR(j, 0, 4)
			maks = max(maks, ile[i][j]);
		ans += a[i] * maks;
	}
	cout << ans;
	
	
 
    return 0;
}