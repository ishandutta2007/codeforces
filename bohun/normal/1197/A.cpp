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
const int mod = 1e9 + 7, nax = 100005;
int n;
int t[nax];

int main() {
	ios
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		FOR(i, n)
			cin >> t[i];
		sort(t + 1, t + n + 1);
		int X = t[n - 1];
		int pos = n - 1;
		while(pos >= 1 && pos > X)
			--pos;
		if(pos == 0)
			cout << 0 << endl;
		else
			cout << pos - 1 << endl;
	}
	
	
	
	
	return 0;
}