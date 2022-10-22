#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	
	
int n, cnt[200010];
	
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		fill(cnt + 1, cnt + n + n + 5, 0);
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d", &a);
			cnt[a]++;
		}
		int res = 0, prv = 0;
		for (int i = 1; i <= 2 * n + 1; ++i) {
			if (prv > 0) {
				res++;
				prv = cnt[i];
			}
			else if (cnt[i] > 0) {
				res++;
				prv = cnt[i] - 1;
			}
			else prv = 0;
		}
		printf("%d\n", res);
	}
	
	return 0;
}