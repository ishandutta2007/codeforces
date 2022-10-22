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

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int nax = 300005;

ll n, m;
string a, b;
int ile[1000005][26];
ll ans = 0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> a >> b;
	int A = ss(a);
	int B = ss(b);
	ll lcm = (ll) A * B / __gcd(A, B);
	int g = __gcd(A, B);
	for(int i = 0; i < A; ++i) {
		int r = (i % g);
		ile[r][a[i] - 'a']++;
	}
	for(int i = 0; i < B; ++i) {
		int r = i % g;
		ans += ile[r][b[i] - 'a'];
	}
	cout << (ll) n * A - (ll) ans * ((ll) n * A / lcm);
	
	
	
	
				
	
	
	return 0;
}