#include<bits/stdc++.h>
#define oo 0x3f3f3f3f
#define cl(x) memset(x, 0, sizeof(x))
#define maxn 50010
#define mo 1000000007
#define fr first
#define sc second
#define mp make_pair
#define pii pair<int, int>
#define debug(x) cerr<<#x<<" = "<<x<<endl
typedef long long ll;
using namespace std;
void gn(int &x) {
	x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
}
int n, a[maxn], l[maxn], r[maxn], ans[maxn];
pii b[maxn];
int main() {
	gn(n);
	for (int i = 1; i <= n; ++i) {
		gn(a[i]);
		l[i] = n - a[i];
		if (i == 1) r[n] = a[i]; else r[i - 1] = a[i];
	}
	for (int i = 1; i <= n; ++i)
		b[i] = mp(r[i] - l[i], i);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i)
		ans[b[i].sc] = i - 1;
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], (i == n ? '\n' : ' '));
	return 0;
}