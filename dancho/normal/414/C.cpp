#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int n, lput;
int a[1<<21];
long long inv[21][2];
int s[21];
pii p[1<<21];

int it[1<<21];

void it_add(int pos, int v)
{
	for (int i = pos; i <= lput; i += (i&(-i)))
		it[i] += v;
}

int it_get(int pos)
{
	int res = 0;
	for (int i = pos; i > 0; i -= (i&(-i)))
		res += it[i];
	return res;
}

long long count_inv(int le, int ri)
{
	long long ans = 0;
	int mi = (le + ri) / 2;
	for (int i = le; i < mi; ++i)
	{
		it_add(a[i], 1);
	}

	for (int i = mi; i < ri; ++i) {
		ans += mi - le - it_get(a[i]);
	}
	
	for (int i = le; i < mi; ++i)
	{
		it_add(a[i], -1);
	}
	
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < (1<<n); i++)
	{
		scanf("%d", &a[i]);
		p[i] = make_pair(a[i], i);
	}
	
	sort(p, p + (1<<n));
	lput = 1;
	for (int i = 0; i < (1<<n); i++)
	{
		if (i > 0 && p[i].first > p[i-1].first)
			++lput;
		a[ p[i].second ] = lput;
	}
	
	for (int i = 0; i <= n; ++i)
	{
		int ln = (1<<(n-i));
		for (int j = 0; j < (1<<n); j += ln)
		{
			inv[i][0] += count_inv(j, j + ln);
			reverse(a + j, a + j + ln);
			inv[i][1] += count_inv(j, j + ln);
			reverse(a + j, a + j + ln);
			//~ printf("INV %d %d :: %lld [%d %d]\n", i, 0, inv[i][0], j, j + ln);
			//~ printf("INV %d %d :: %lld [%d %d]\n", i, 1, inv[i][1], j, j + ln);
		}
	}
	
	int m;
	scanf("%d", &m);
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= m; ++i)
	{
		int q;
		scanf("%d", &q);
		for (int j = n - q; j <= n; ++j)
			s[j] = 1 - s[j];
		long long ans = 0;
		for (int j = 0; j <= n; ++j)
		{
			ans += inv[j][s[j]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}