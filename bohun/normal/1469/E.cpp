#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	

int n, k, ban[1 << 21], one[1 << 21];
char s[1 << 21];

void solve() {
	scanf("%d%d%s", &n, &k, s);
	for (int i = 0; i < n; ++i)
		one[i + 1] = one[i] + (s[i] == '0');
	int p = 0;
	while ((1 << p) <= n && p < k) p++;
	fill(ban, ban + (1 << p), 0);
	for (int i = 0; i + k <= n; ++i) {
		if (one[i] != one[i + k - p]) continue;
		int mask = 0;
		for (int j = 0; j < p; ++j)
			if (s[i + k - 1 - j] == '0')
				mask += (1 << j);
		ban[mask] = 1;
	}
	int res = 0;
	while (res < (1 << p) && ban[res]) res++;			
	if (res == (1 << p)) return printf("NO\n"), void(0);
	printf("YES\n");
	for (int i = 0; i < k - p; ++i)
		printf("0");
	for (int i = p - 1; 0 <= i; --i)
		printf("%d", res >> i & 1);
	puts("");
}
	

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}