#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;	

const int N = 1e5 + 10;

int n;
ll s[N], e[N];
int dp[N][2];

bool DP[N];

void brute(int S, int E) {
	rep(i, S, 2 * E) DP[i] = 0;
	per(i, S, E - 1) {
		DP[i] = (!DP[2 * i] | !DP[i + 1]);
		printf ("%d ", DP[i]);
	}
	printf ("\n");
}
	
int t[2];

bool gra(ll S, ll E, vector<int> v) {
	vector <int> now;	
	while (true) {
		ll L = (E + 1) / 2;
		t[0] = t[1] = 0;
		for (auto it : v) t[it] = 1;
		if (t[0] == 0) {
			now = {0, 1};
		}
		else {
			int y = E % 2;
			if (t[y] == 1) now = {y};
			else now = {!y};
		}
		if (L <= S) {
			t[0] = t[1] = 0;
			for (auto it : now) t[it] = 1;
			return t[S % 2];
		}
		v = now;
		E = L;
	}
}

bool play2(ll S, ll E) {
	E++;
	return gra(S, E, {});
}

bool play1(ll S, ll E) {
	E++;
	return gra(S, E, {0, 1});
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) 
		scanf ("%lld%lld", &s[i], &e[i]);
	per(i, 1, n) {
		if (i == n) {
			dp[i][0] = play1(s[i], e[i]);
			dp[i][1] = play2(s[i], e[i]);
		}
		else {
			int X = play1(s[i], e[i]);
			int Y = play2(s[i], e[i]);
			if (X == true)
				dp[i][0] |= !dp[i + 1][0];
			if (Y == true)
				dp[i][0] |= dp[i + 1][0];
			
			if (X == true)
				dp[i][1] |= !dp[i + 1][1];
			if (Y == true)
				dp[i][1] |= dp[i + 1][1];
		}
	}
	printf ("%d %d\n", dp[1][0], dp[1][1]);
		
	
	
	return 0;
}