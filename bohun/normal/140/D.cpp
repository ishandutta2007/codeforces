#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;	 		
			
const int N = 111;
const int M = 400;

int n;
int a[N];
int dp[N][M][N];

void umin(int &a, int b) {
	a = min(a, b);
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	sort(a + 1, a + n + 1);
	
	int j = 0, s = 0;
	while (j + 1 <= n && s + a[j + 1] <= 710) {
		s += a[j + 1];
		j++;
	}
	printf ("%d ", j);
	n = j; 
	
	int cost = 0;
	s = 10;
	rep(i, 1, n) {
		s += a[i];
		if (s >= 360)
			cost += abs(s - 360);
	}
	printf ("%d\n", cost);
	
	/*rep(i, 0, n)
		rep(j, 0, M - 1)
			rep(k, 0, n)
				dp[i][j][k] = 1e9;
	dp[0][0][0] = 0;
	rep(i, 1, n)
		rep(sum, 0, M - 1)
			rep(cnt, 0, n) {
				if (sum >= a[i])
					umin(dp[i][sum][cnt], dp[i - 1][sum - a[i]][cnt]);
				if (cnt >= 1)
					umin(dp[i][sum][cnt], dp[i - 1][sum][cnt - 1] + cnt * a[i]);
			}
	int out = 1e9;
	rep(sum, 0, 350)
		rep(cnt, 0, n)
			umin(out, dp[n][sum][cnt] - cnt * (350 - sum));
	printf ("%d\n", out);*/
		
	return 0;
}