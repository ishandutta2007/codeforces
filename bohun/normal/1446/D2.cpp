#include <bits/stdc++.h>
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int N = 4e5 + 50;
const int B = 300;

int n, a[N], cnt[N], last[N], ans, where[N];
vector<int> vec[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		cnt[a[i]]++;
		vec[a[i]].pb(i);
	}
	int M = max_element(cnt + 1, cnt + n + 1) - cnt;
	
	for (int k = 1; k <= n; ++k) {
		if (k == M || sz(vec[k]) <= B) 
			continue;
			
		fill(last, last + 2 * n + 1, n + 1);
		int sum = n;
		last[sum] = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == M) sum++;
			if (a[i] == k) sum--;
			ans = max(ans, i - last[sum]);
			if (last[sum] == n + 1)
				last[sum] = i;
		}			
	}
	
	vec[M].insert(vec[M].begin(), 0);
	vec[M].pb(n + 1);
		
	for (int occ = 1; occ <= B; ++occ) {
		fill(where + 1, where + n + 1, n + 1);
		for (int k = 1; k <= n; ++k) {
			if (k == M) continue;
			for (int i = occ - 1; i < sz(vec[k]); ++i)
				where[vec[k][i - (occ - 1)]] = vec[k][i];
		}
		
		for (int i = n - 1; 1 <= i; --i)
			where[i] = min(where[i], where[i + 1]);
		
		for (int i = 0;	i + occ + 1 < sz(vec[M]); ++i) {
			int L = vec[M][i] + 1, R = vec[M][i + occ + 1] - 1;
			if (where[L] <= R)
				ans = max(ans, R - L + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}