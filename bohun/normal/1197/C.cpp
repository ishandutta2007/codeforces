#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		
const int mod = 1e9 + 7, nax = 300005;
int n, k;
int t[nax];
multiset <int> s;
ll ans = 0;


int main() {
	ios
	cin >> n >> k;
	k--;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	FOR(i, n) {
		if(i < n)
			s.insert(t[i] - t[i + 1]);
		
	}
	ans = t[n] - t[1];
	while(k--) {
		ans += *s.begin();
		s.erase(s.begin());
	}
	cout << ans;
	
	
	return 0;
}