#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int nax = 1e6 + 111;
const int mod = 1e9 + 7;

int q;
int r, n;

int sito[nax];

map <int, int> mapa;

int dp[nax][21];

int ans = 0;

int main() {
	dp[0][0] = 1;
	for(int i = 1; i <= 20; ++i)
		dp[0][i] = 2;
	for(int i = 1; i < nax; ++i)
		for(int j = 0; j <= 20; ++j)
			for(int g = 0; g <= j; ++g)
				dp[i][j] = (dp[i][j] + dp[i - 1][g]) % mod;
	
	for(int i = 2; i < nax; ++i)
		if(!sito[i])
			for(int j = i; j < nax; j += i)
				sito[j] = i;
	
	scanf("%d", &q);
	while(q--) {
		mapa.clear();
		scanf("%d %d", &r, &n);
		while(n > 1) {
			mapa[sito[n]] += 1;
			n /= sito[n];
		}
		ans = 1;
		for(auto it : mapa)
			ans = (ll) ans * dp[r][it.se] % mod;
		printf("%d\n", ans);
	}
				 
	
	
	return 0;
}