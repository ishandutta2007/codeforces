#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cout << #x << " = " << x << endl
 
using namespace std;

const int nax = 1e5 + 111;
const long long inf = 1e18;

int n;
ll a[nax];
ll dp[61][nax];
int gdzie[nax];

vector <pair<ll, int>> gao, gao2; 

ll daj(int n, int k) {
	if(n < 0) {
		if(k == 0)
			return 0;
		return inf;
	}
	return dp[n][k];
}
			

int main() {
	for(int i = 0; i <= 60; ++i)
		for(int j = 0; j < nax; ++j)
			dp[i][j] = inf;
			
	scanf("%d", &n);
	ll MAX = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
		MAX = max(MAX, a[i]);
		gao2.pb({0, i});
	}
	for(int i = 0; i < n; ++i)
		a[i] = MAX - a[i];
	
	sort(gao2.begin(), gao2.end());
	
	for(int i = 0; i <= 60; ++i) {
		
		gao.clear();
		ll U = (1LL << (i + 1)) - 1;
		ll ones = 0;
		for(int j = 0; j < n; ++j) {
			gao.pb({U & a[j], j});
			if((1LL << i) & a[j])
				ones += 1;
		}
		sort(gao.begin(), gao.end());
		reverse(gao.begin(), gao.end());
		
		int Last = -1;
		
		for(int j = 0; j < n; ++j) {
			if((1LL << i) & gao[j].fi)
				Last = j;
			gdzie[gao[j].se] = j;
		}
			
		// p = 0 c = 0
		
		dp[i][0] = min(dp[i][0], daj(i - 1, 0) + ones);
		
		// p = 0 c = 1
		
		dp[i][Last + 1] = min(dp[i][Last + 1], daj(i - 1, 0) + n - ones);
		
		// p > 0 c = 0 / 1
		
		int Lastzero = -1;
		int Lastone = -1;
		if(i != 0) {
			for(int j = 0; j < n; ++j) {
				auto it = gao2[j];
				if(((1LL << i) & a[it.se]))
					Lastone = gdzie[it.se];
				else
					Lastzero = gdzie[it.se];
					
				// c = 0;
				assert(ones + j + 1 - 2 * (Lastone + 1) >= 0);
				dp[i][Lastone + 1] = min(dp[i][Lastone + 1], daj(i - 1, j + 1) + ones + j + 1 - 2 * (Lastone + 1));
				
				// c = 1
				int d = max(Last, Lastzero);
				assert(n + ones + j + 1 - 2 * (d + 1) >= 0);
				dp[i][d + 1] = min(dp[i][d + 1], daj(i - 1, j + 1) + n + ones + j + 1 - 2 * (d + 1));
			}
		}
		gao2 = gao;
		
		/*cout << i << " Elo \n";
		for(int j = 0; j <= n; ++j)
			cout << j << " " << dp[i][j] << endl;
		cout << endl;
		*/
	}
	printf("%lld", dp[60][0]);
	
 
	return 0;
}