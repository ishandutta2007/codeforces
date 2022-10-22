#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

int n, m;
char s[1 << 18];
int mx[1 << 18][2], mn[1 << 18][2], sum[1 << 18];

void solve() {
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1, b = 0; i <= n; ++i) {
		b += (s[i] == '+' ? 1 : -1);
		mx[i][0] = max(mx[i - 1][0], b);
		mn[i][0] = min(mn[i - 1][0], b);
		sum[i] = b;
	}
	mx[n + 1][1] = mn[n + 1][1] = 0;
	for (int i = n, b = 0; i >= 1; --i) {
		b += (s[i] == '-' ? 1 : -1);
		mx[i][1] = max(mx[i + 1][1], b);
		mn[i][1] = min(mn[i + 1][1], b);
	}
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int a = sum[r] - sum[l - 1]; 
		printf("%d\n", max(mx[l - 1][0], mx[r + 1][1] + sum[n] - a) - min(mn[l - 1][0], mn[r + 1][1] + sum[n] - a) + 1);
	}	
}	

int main() {
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}