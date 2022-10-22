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

int n, T;
char s[200005];
int cnt[4];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%s", s + 1);
		n = strlen(s + 1);
		rep(j, 1, 3) cnt[j] = 0;
		int j = 1;
		int ans = n + 1;
		rep(i, 1, n) {
			while ((!cnt[1] || !cnt[2] || !cnt[3]) && j <= n) {
				cnt[s[j] - '0']++;
				j++;
			}
			if (cnt[1] && cnt[2] && cnt[3])
				ans = min(ans, j - i);
			cnt[s[i] - '0']--;
		}
		if (ans == n + 1) ans = 0;
		printf ("%d\n", ans);
	}
	
	
	return 0;
}