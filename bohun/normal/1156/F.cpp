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
// tree<int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;		
const int mod = 998244353;
int n;
int a;
int ile[5005];
int dp[2][5005];
int inv[5005];

int pt(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1)
			r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}

int ulamek(int a, int b) {
	return (ll) a * inv[b] % mod;
}

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

int main() {
	FOR(i, 0, 5000)
		inv[i] = pt(i, mod - 2);
	ios
	cin >> n;
	ile[0]++;
	FOR(i, 1, n) {
		cin >> a;
		ile[a]++;
	}
	for(int i = n; 0 <= i; --i) {
		int ja = i % 2;
		int on = !ja;
		
		FOR(j, 0, 5000) {
			dp[ja][j] = 0;
		}
		FOR(j, 0, 5000) {
			if(!ile[j])
				continue;
			add(dp[ja][j], ulamek(ile[j] - 1, n - i));
			add(dp[ja][j], dp[on][j + 1]);
		}
		if(i) {
		for(int j = 5000; 0 <= j; --j) {
			dp[ja][j] = (ll) dp[ja][j] * ulamek(ile[j], n - i + 1) % mod;
			add(dp[ja][j], dp[ja][j + 1]);
		}
		}
	}
	cout << dp[0][0] << endl;
	
	
			
	
	
		
	
	
	
	return 0;
}