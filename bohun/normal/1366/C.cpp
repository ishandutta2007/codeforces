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

const int N = 101;

int T, n, m, a[N][N];

int cnt[N][2];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &m);
		rep(i, 1, n)
			rep(j, 1, m)
				scanf ("%d", &a[i][j]);
		
		rep(i, 0, 100)
			cnt[i][0] = cnt[i][1] = 0;
				
		rep(i, 1, n)
			rep(j, 1, m) {
				int b = i + j - 2;
				int c = n + m - i - j;
				if (b != c) 
					cnt[min(b, c)][a[i][j]]++;
			}
		int ans = 0;
		rep(i, 0, 100)
			ans += min(cnt[i][0], cnt[i][1]);
		printf ("%d\n", ans);
	}
			
	
	return 0;
}