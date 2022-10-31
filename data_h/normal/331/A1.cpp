#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 3 * 110000;
const long long inf = (1ll << 60);
long long pre[MAXN], last[MAXN], sum[MAXN];

int a[MAXN], l, r;
map<int, int> L, R;
vector<int> anss;
int n;
long long ans = -inf;

int modify(int x) {
	return x > 0 ? x : 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int x = a[i];
		if (L.count(x)) {
			L[x] = min(L[x], i);
			R[x] = max(R[x], i);
		} else {
			L[x] = R[x] = i;
		}
	}
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + modify(a[i]);
	for(int i = 1; i <= n; i++) {
		int ll = L[a[i]], rr = R[a[i]];
		if (ll == rr)
			continue;
		long long tmp = sum[rr - 1] - sum[ll] + 2 * a[i];
		if (tmp > ans)
			ans = tmp, l = ll, r = rr;
	}
	printf("%I64d ", ans);
	for(int i = 1; i <= n; i++)
		if (i < l || i > r || l < i && i < r && a[i] <= 0) {
			anss.push_back(i);
		}
	printf("%d\n", anss.size());
	for(int i = 0; i < anss.size(); i++)
		printf("%d%c", anss[i], i + 1 == anss.size() ? '\n' : ' ');
}