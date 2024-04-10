#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MAXN 100005

using namespace std;

typedef long long LL;
int n;
int a[MAXN];
int inc[MAXN], dec[MAXN];
LL pos[MAXN], neg[MAXN];
LL isum[MAXN], dsum[MAXN];
LL ans, tmp;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)
		if (a[i] > inc[i-1])
			inc[i] = a[i];
		else
			inc[i] = inc[i-1] + 1;
	for (int i = n; i > 0; i--)
		if (a[i] > dec[i+1])
			dec[i] = a[i];
		else
			dec[i] = dec[i+1] + 1;

	for (int i = 1; i <= n; i++) {
		isum[i] = isum[i-1] + inc[i];
		pos[i] = pos[i-1] + a[i];
	}
	for (int i = n; i > 0; i--) {
		dsum[i] = dsum[i+1] + dec[i];
		neg[i] = neg[i+1] + a[i];
	}

	ans = 0x7fffffffffffffff;
	for (int i = 1; i <= n; i++) {
		tmp = (isum[i-1] - pos[i-1]) + (dsum[i+1] - neg[i+1]);
		tmp += max(inc[i], dec[i]) - a[i];

		ans = min(ans, tmp);
	}

	printf("%I64d\n", ans);

	return 0;
}