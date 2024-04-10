#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)
#define po(x) cerr << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;	
	
const int nax = 100005;	

int n, d;
int t[nax], ans[nax];
ld best = 0;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	
	int so_far = 0;
	for(int i = n; 1 <= i; --i) {
		so_far = so_far - 1;
		so_far = max(so_far, t[i] + 1);
		ans[i] = so_far;
	}
	ll g = 0;
	for(int i = 1; i <= n; ++i) {
		ans[i] = max(ans[i], ans[i - 1]);
		g += ans[i] - t[i] - 1;
	}
	cout << g;
	
	
	
	
	
	return 0;
}