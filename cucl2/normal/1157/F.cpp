#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int a[200005];
int cs[200005];

int main() {
	scanf("%d", &N);
	repi(i, N) scanf("%d", a + i);
	repi(i, N) ++cs[a[i]];
	int ans = 0;
	int bg, en;
	rep(i, 200005) {
		if (!cs[i]) continue;
		int j = i + 1;
		while (cs[j] >= 2) ++j;
		if (!cs[j]) --j;
		int sm = 0;
		for (int k = i; k <= j; ++k) sm += cs[k];
		if (sm > ans) {
			ans = sm;
			bg = i; en = j;
		}
		i = max(i, j - 1);
	}
	printf("%d\n", ans);
	vector<int> out;
	for (int i = bg; i <= en; ++i) out.push_back(i);
	for (int i = en; i >= bg; --i) for (int j = 1; j < cs[i]; ++j) out.push_back(i);
	for (int i : out) printf("%d ", i);
	puts(""); return 0;
}