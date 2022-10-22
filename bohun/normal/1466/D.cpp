#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	
	
int n, w[1 << 17], deg[1 << 17], ord[1 << 17];
	
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ll res = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%d", w + i), deg[i] = 0, ord[i] = i, res += w[i];
		for (int i = 1; i < n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			deg[a]++;
			deg[b]++;
		}
		sort(ord + 1, ord + n + 1, [&](int a, int b) {
			return w[a] > w[b];
		});
		int j = 1;
		for (int i = 1; i < n; ++i) {
			printf("%lld ", res);
			while (deg[ord[j]] == 1) j++;
			res += w[ord[j]];
			deg[ord[j]]--;
		}
		puts("");
	}
	
	return 0;
}