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

const int nax = 55, mod = 1e9 + 7;
int n, S, ans;
int t[nax][2];

int aa[55][55][2555];
int cc[55][2555];
int dp[55][55][55][4];
int sil[55];
int ile[55];

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	sil[0] = 1;
	for(int i = 1; i <= 50; ++i)
		sil[i] = (ll) sil[i - 1] * i % mod;
	
	cin >> n >> S;
	aa[0][0][0] = cc[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i][0] >> t[i][1];
		t[i][1]--;
		ile[t[i][1]]++;
		if(t[i][1] <= 1) {
			for(int a = ile[0]; 0 <= a; --a)
				for(int b = ile[1]; 0 <= b; --b) 
					for(int s = 2500; 0 <= s; --s) {
						int ns = s + t[i][0];
						if(ns > 2500)
							continue;
						int na = a + (t[i][1] == 0);
						int nb = b + (t[i][1] == 1);
						add(aa[na][nb][ns], aa[a][b][s]);
					}
		}
		else {
			for(int c = ile[2]; 0 <= c; --c) {
				for(int s = 2500; 0 <= s; --s) {
					int ns = s + t[i][0];
					if(ns > 2500)
						continue;
					int nc = c + 1;
					add(cc[nc][ns], cc[c][s]);
				}
			}
		}
	}
	
	dp[0][0][0][3] = 1;
	for(int a = 0; a <= 50; ++a)
		for(int b = 0; b <= 50; ++b)
			for(int c = 0; c <= 50; ++c) 
				for(int l = 0; l <= 3; ++l)
					for(int nowy = 0; nowy <= 2; ++nowy) {
						if(nowy == l)
							continue;
						int na = a + (nowy == 0);
						int nb = b + (nowy == 1);
						int nc = c + (nowy == 2);
						add(dp[na][nb][nc][nowy], dp[a][b][c][l]);
					}
	
	for(int a = 0; a <= ile[0]; ++a)
		for(int b = 0; b <= ile[1]; ++b)
			for(int c = 0; c <= ile[2]; ++c) 
				for(int s = 0; s <= 2500; ++s) {
					int res = sil[a];
					res = (ll) res * sil[b] % mod;
					res = (ll) res * sil[c] % mod;
					res = (ll) res * ((ll) dp[a][b][c][0] + dp[a][b][c][1] + dp[a][b][c][2]) % mod;
					res = (ll) res * aa[a][b][s] % mod;
					res = (ll) res * cc[c][S - s] % mod;
					add(ans, res);
				}
	cout << ans;
	
			
						
	
	
				
	
	
	return 0;
}