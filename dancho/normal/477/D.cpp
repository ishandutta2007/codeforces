#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
const int bs = 2;

long long qpow(long long v, long long st)
{
	long long r = 1;
	while (st)
	{
		if (st & 1)
		{
			r = r * v;
			if (r >= mod)
				r %= mod;
		}
		v = v * v;
		if (v >= mod)
			v %= mod;
		st /= 2;
	}

	return r;
}

int n;
char x[5020];

long long ha[5020];
long long bp[5020];
long long bpinv[5020];

// get num l to r inclusive
long long getNum(int l, int r)
{
	long long num;
	if (!l)
		num = ha[r];
	else
	{
		long long red = ha[l - 1] * bp[r - (l-1)];
		if (red >= mod)
			red %= mod;
		//~ printf("GN %d %d :: %lld %lld %lld\n", l, r, red, ha[l - 1], ha[r]);
		num = ha[r] - red + mod;
		if (num >= mod)
			num %= mod;
	}
	return num;
}

int fdif[5020][5020];

int gfd(int i, int j)
{
	if (i > j)
		swap(i, j);
	if (j >= n)
		return i;
	if (fdif[i][j] != -1)
		return fdif[i][j];
	if (x[i] == x[j])
	{
		fdif[i][j] = gfd(i + 1, j + 1);
	}
	else
		fdif[i][j] = i;
	return fdif[i][j];
}

int GML;
int mlen[5020][5020];
int mlag[5020][5020];

int getMl(int b, int e);

int getmlag(int e, int mx)
{
	if (mx > n)
	{
		return mlen[5010][5010];
	}
	if (mlag[e][mx] != mlag[5010][5010])
		return mlag[e][mx];
	mlag[e][mx] = min(getMl(e, mx), getmlag(e, mx + 1));

	return mlag[e][mx];
}

int getMl(int b, int e)
{
	if (e == n)
	{
		return e - b;
	}
	if (mlen[b][e] != mlen[5010][5010])
	{
		return mlen[b][e];
	}
	if (2 * e - b > n)
	{
		return mlen[5010][5010];
	}
	if (x[e] != '1')
		return mlen[5010][5010];

	mlen[b][e] = getmlag(e, 2 * e - b + 1);

	int k = gfd(b, e);
	if (k >= e || x[k] < x[e + k - b])
	//~ if (getNum(b, e-1) == getNum(e, 2 * e - b - 1))
	{
		//~ printf("EQ %d %d :: %d %d\n", b, e - 1, e, 2 * e - b - 1);
		mlen[b][e] = min(mlen[b][e], getMl(e, 2 * e - b));
	}
	if (mlen[b][e] < e - b)
		mlen[b][e] = e - b;
	//~ printf("MLEN %d %d :: %d <> %lld %lld [%d %d]\n", b, e, mlen[b][e], getNum(b, e - 1), getNum(e, 2 * e - b-1), e, 2 * e - b-1);
	return mlen[b][e];
}

int dp[5020][5020];
int dpag[5020][5020];

int getDPsm(int b, int e)
{
	if (e > n)
		return (1 << 29);
	if (e == n)
	{
		return getNum(b, e - 1);
	}
	if (x[e] != '1')
	{
		return (1 << 29);
	}
	if (dp[b][e] != -1)
		return dp[b][e];
	if (2 * e - b > n)
	{
		return (1 << 29);
	}

	dp[b][e] = (1 << 29);
	for (int x = 2 * e - b + 1; x - e <= 15; ++x)
	{
		dp[b][e] = min(dp[b][e], getDPsm(e, x) + 1);
	}
	int k = gfd(b, e);
	if (k >= e || x[k] < x[e + k - b])
	//~ if (getNum(b, e - 1) == getNum(e, 2 * e - b - 1))
	{
		dp[b][e] = min(dp[b][e], getDPsm(e, 2 * e - b) + 1);
	}
	//~ printf("DP %d %d :: %lld\n", b, e, dp[b][e]);
	return dp[b][e];
}

int getDPbi(int b, int e);

int getDPag(int e, int mx)
{
	if (mx - e > GML)
		return (1 << 29);
	if (mx > n)
	{
		return (1 << 29);
	}
	if (dpag[e][mx] != -1)
		return dpag[e][mx];
	dpag[e][mx] = min(getDPbi(e, mx), getDPag(e, mx + 1));
	return dpag[e][mx];
}

int getDPbi(int b, int e)
{
	if (e > n)
		return (1 << 29);
	if (e - b > GML)
	{
		return (1 << 29);
	}

	if (e == n)
	{
		return 0;
	}
	if (x[e] != '1')
	{
		return (1 << 29);
	}
	if (dp[b][e] != -1)
		return dp[b][e];
	if (2 * e - b > n)
	{
		return (1 << 29);
	}

	dp[b][e] = getDPag(e, 2 * e - b + 1) + 1;
	int k = gfd(b, e);
	if (k >= e || x[k] < x[e + k - b])
	//~ if (getNum(b, e - 1) == getNum(e, 2 * e - b - 1))
	{
		dp[b][e] = min(dp[b][e], getDPbi(e, 2 * e - b) + 1);
	}
	return dp[b][e];
}

int getScnt(int b, int e);

int scntag(int e, int mx)
{
	if (mx > n)
	{
		return 0;
	}
	if (dpag[e][mx] != -1)
		return dpag[e][mx];
	dpag[e][mx] = getScnt(e, mx) + scntag(e, mx + 1);
	if (dpag[e][mx] >= mod)
		dpag[e][mx] -= mod;
	return dpag[e][mx];
}

int getScnt(int b, int e)
{
	if (e > n)
		return 0;
	if (e == n)
	{
		return 1;
	}
	if (x[e] != '1')
	{
		return 0;
	}
	if (dp[b][e] != -1)
		return dp[b][e];
	if (2 * e - b > n)
	{
		return 0;
	}

	dp[b][e] = scntag(e, 2 * e - b + 1);

	int k = gfd(b, e);
	if (k >= e || x[k] < x[e + k - b])
	//~ if (getNum(b, e - 1) == getNum(e, 2 * e - b - 1))
	{
		dp[b][e] += getScnt(e, 2 * e - b);
		if (dp[b][e] >= mod)
			dp[b][e] -= mod;
	}
	//~ printf("cnt %d %d :: %d\n", b, e, dp[b][e]);
	return dp[b][e];
}

int main()
{
	memset(fdif, -1, sizeof(fdif));
	scanf("%s", x);
	n = strlen(x);
	if (x[0] == '0' && n == 1)
	{
		printf("0\n0\n");
		return 0;
	}
	ha[0] = x[0] - '0';
	bp[0] = 1LL;
	for (int i = 1; i < n; i++)
	{
		bp[i] = bp[i - 1] * bs;
		if (bp[i] >= mod)
			bp[i] %= mod;
		bpinv[i] = qpow(bp[i], mod - 2);
	}
	
	for (int i = 1; i < n; ++i)
	{
		ha[i] = ha[i - 1] * bs + (x[i] - '0');
		if (ha[i] >= mod)
			ha[i] %= mod;
	}

	memset(mlen, 63, sizeof(mlen));
	memset(mlag, 63, sizeof(mlag));
	int gml = n;
	for (int i = 1; i <= n; ++i)
	{
		gml = min(gml, getMl(0, i));
	}

	//~ printf("%d\n", gml);
	GML = gml;
	long long ssol;
	if (GML <= 15)
	{
		memset(dp, -1, sizeof(dp));
		ssol = (1LL << 62);
		for (int i = 1; i <= n && i <= 15; ++i)
		{
			ssol = min(ssol, getDPsm(0, i) + 1LL);
		}
		//~ printf("SSOL %lld __ %d\n", ssol, GML);
	}
	else
	{
		memset(dp, -1, sizeof(dp));
		memset(dpag, -1, sizeof(dpag));
		ssol = (1LL << 62);
		for (int i = 1; i <= n; ++i)
		{
			ssol = min(ssol, getDPbi(0, i) + 1LL);
		}
		long long nm = 0;
		for (int i = n - GML; i < n; ++i)
		{
			nm = nm * 2 + x[i] - '0';
			if (nm >= mod)
				nm %= mod;
		}
		ssol += nm;
		if (ssol >= mod)
			ssol %= mod;
	}

	memset(dp, -1, sizeof(dp));
	memset(dpag, -1, sizeof(dpag));
	long long scnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		scnt += getScnt(0, i);
		if (scnt >= mod)
			scnt %= mod;
	}

	printf("%lld\n", scnt);
	printf("%lld\n", ssol);

	return 0;
}