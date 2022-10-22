#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define DOW(i, n) for(int i = n - 1; 0 <= i; --i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 1e6 + 111;

int a[nax];
int dp[nax];
int b[nax];
vector <int> pr[nax];

int main() {
	for(int i = 2; i < nax; ++i)
		if(!b[i]) {
			for(int j = i; j < nax; j += i) {
				pr[j].pb(i);
				b[j] = 1;
			}
		}
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int b;
		scanf("%d", &b);
		a[b] = 1;
	}
	int best = 0;
	for(int i = 1; i < nax; ++i) {
		for(auto it : pr[i])
			dp[i] = max(dp[i], dp[i / it]);
		dp[i] += a[i];
		best = max(best, dp[i]);
	}
	printf("%d", best);
	
	
	return 0;
}