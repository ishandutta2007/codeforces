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
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 1e6 + 5, mod = 1e9 + 7;

int n;
int pot = 1, wyk = 0;
int dp[nax][22][2]; //

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

int pt(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1)
			res = res * a;
		a = a * a;
		b /= 2;
	}
	return res;
}

int dwa[105];

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	
	while(pot * 2 <= n) {
		++wyk;
		pot *= 2;
	}
	
	dwa[0] = 1;
	for(int i = 1; 20 >= i; ++i)
		dwa[i] = 2 * dwa[i - 1];
	
	dp[1][wyk][0] = 1;
	if(wyk && pot / 2 * 3 <= n) { // ? corner
		dp[1][wyk - 1][1] = 1;
	}
	
	for(int i = 1; n > i; ++i) {
		for(int j = 0; 20 >= j; ++j)
			for(int g = 0; 2 > g; ++g) {
				int trzy = (g == 0 ? 1 : 3);
				int liczba = dwa[j] * trzy;
				int ile = (n / liczba) - i;
				if(ile < 0 || liczba > n)
					continue;
				// 1. same
				add(dp[i + 1][j][g], (ll) dp[i][j][g] * ile % mod);
				// 2. dwa
				if(j > 0) {
					liczba = dwa[j - 1] * trzy;
					int liczba2 = dwa[j] * trzy;
					int ILE = n / liczba - n / liczba2;
					add(dp[i + 1][j - 1][g], (ll) dp[i][j][g] * ILE % mod);
				}
				// 3. trzy
				if(g) {
					liczba = dwa[j] * 3;
					int liczba2 = dwa[j];
					int ILE = n / liczba2 - n / liczba;
					add(dp[i + 1][j][g - 1], (ll) dp[i][j][g] * ILE % mod);
				}
			}
	}
	cout << dp[n][0][0];
					
	
	
	
	
			
	
	
		
	
    return 0;
}