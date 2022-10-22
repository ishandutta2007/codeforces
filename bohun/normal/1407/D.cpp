#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

const int N = 3e5 + 100;

int n;
int h[N], h2[N], dp[N];
vector <int> up, down;
vector <int> S1, S2;
map <int, int> id1, id2;

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", h + i);
		h2[i] = -h[i];
		
		if (i > 1) {
			dp[i] = dp[i - 1] + 1;
			
			while (!S1.empty() && h[S1.back()] > h[i]) S1.pop_back();
			
			while (!S2.empty() && h2[S2.back()] > h2[i]) S2.pop_back();
			
			if (!S1.empty()) dp[i] = min(dp[i], dp[S1.back()] + 1);
			
			if (!S2.empty()) dp[i] = min(dp[i], dp[S2.back()] + 1);
			
			while (!up.empty() && h[up.back()] >= h[i]) {
				dp[i] = min(dp[i], dp[up.back()] + 1);
				up.pop_back();
			}
			
			while (!down.empty() && h2[down.back()] >= h2[i]) {
				dp[i] = min(dp[i], dp[down.back()] + 1);
				down.pop_back();
			}
			
		}
				
		up.pb(i);
		down.pb(i);
		
		id1[h[i]] = i;
		id2[h2[i]] = i;
		
		S1.pb(i);
		S2.pb(i);
	}
	printf ("%d\n", dp[n]);
		
	return 0;
}