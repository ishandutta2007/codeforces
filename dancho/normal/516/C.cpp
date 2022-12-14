#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int bsz = 800;

int n, m;
int N ;
int d[300020], hi[300020];
long long s[600020], h[600020];

long long mxsm[800], midf[800], bsl[800];

long long lsl(int x, int y, long long &mn)
{
	long long bsl = -1;
	for (int i = x; i <= y; ++i)
	{
		if (mn != (1LL << 62) && s[i] + h[i] - mn > bsl)
			bsl = s[i] + h[i] - mn;
		mn = min(mn, s[i] - h[i]);
	}
	return bsl;
}

long long solve(int x, int y)
{
	long long mn = (1LL << 62);
	long long sl = -1;
	if (x / bsz == y / bsz)
	{
		return lsl(x, y, mn);
	}
	sl = max(sl, lsl(x, (x / bsz + 1) * bsz - 1, mn));
	for (int b = x / bsz + 1; b < y / bsz; ++b)
	{
		sl = max(sl, bsl[b]);
		if (mxsm[b] - mn > sl)
			sl = mxsm[b] - mn;
		mn = min(mn, midf[b]);
	}
	sl = max(sl, lsl((y / bsz) * bsz, y, mn));
	return sl;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &hi[i]);
		h[i] = hi[i] + hi[i];
		h[i + n] = hi[i] + hi[i];
	}
	
	s[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		s[i + 1] = s[i] + d[i];
	}
	for (int i = n; i < 2 * n; ++i)
	{
		s[i + 1] = s[i] + d[i - n];
	}
	
	N = 2 * n;
	memset(mxsm, -1, sizeof(mxsm));
	memset(midf, 63, sizeof(midf));
	memset(bsl, -1, sizeof(bsl));
	for (int i = 0; i < N; ++i)
	{
		int b = i / bsz;
		if (midf[b] != midf[N + 1] && s[i] + h[i] - midf[b] > bsl[b])
		{
			bsl[b] = s[i] + h[i] - midf[b];
		}
		
		mxsm[b] = max(mxsm[b], s[i] + h[i]);
		midf[b] = min(midf[b], s[i] - h[i]);
	}
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		
		--a; --b;
		long long sol;
		if (a > b)
		{
			sol = solve(b + 1, a - 1);
		}
		else
		{
			sol = solve(b + 1, a + n - 1);
		}
		printf("%I64d\n", sol);
	}
	
	return 0;
}