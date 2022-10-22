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

const int mod = 998244353, nax = 51;
int n, m;
int a[nax], waga[nax];
int dp[nax][101][101];
int inv[3001];

int pt(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}

ll ulamek(int a, int b) {
	return (ll) a * inv[b] % mod;
}

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		 a -= mod;
}

int main() {
	FOR(i, 0, 3000)
		inv[i] = pt(i, mod - 2);
	ios
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	int suma = 0;
	int ones = 0;
	int twos = 0;
	FOR(i, 1, n) {
		cin >> waga[i];
		suma += waga[i];
		if(a[i])
			ones += waga[i];
		else
			twos += waga[i];
	}
	
	FOR(i, 1, n) {
		FOR(j, 0, m) {
			FOR(bil, 0, 100)
				FOR(k, 0, 100)
					dp[j][bil][k] = 0.0;
		}
		
		dp[0][50][waga[i]] = 1;
		FOR(j, 0, m - 1) 
			FOR(bil, 0, 100)
				FOR(ja, 0, 100) {
					if(dp[j][bil][ja] == 0)
						continue;
					int b = bil - 50;
					int we = ones + (j + b) / 2;
					int they = twos - (j - b) / 2;
					if(they < 0 || we < 0)
						continue;
					int all = we + they;
					int good = (a[i] == 1 ? 1 : -1);
					int bad = (good == 1 ? -1 : 1);
					if(good == -1)
						swap(we, they);
					if(we - ja < 0)
						continue;
					// 1. ja
					add(dp[j + 1][bil + good][ja + good], (ll) dp[j][bil][ja] * ulamek(ja, all) % mod);
					// 2. we
					add(dp[j + 1][bil + good][ja], (ll) dp[j][bil][ja] * ulamek(we - ja, all) % mod);
					// 3. they
					add(dp[j + 1][bil + bad][ja], (ll) dp[j][bil][ja] * ulamek(they, all) % mod);	
				}
		int ans = 0;
		FOR(bil, 0, 100)
			FOR(ja, 0, 100) {
				add(ans, (ll) ja * dp[m][bil][ja] % mod);
			}
		cout << ans << endl;
	}
			
		
		
	
	
	
	
	return 0;
}