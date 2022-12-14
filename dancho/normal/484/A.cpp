#include <cstdio>
#include <cstring>

int pc(long long x)
{
	if (!x)
		return 0;
	return (x & 1) + pc(x / 2);
}

long long l, r;
long long f[67][2][2];

long long sol(int p, int fl, int fr)
{
	if (f[p][fl][fr] != -1)
		return f[p][fl][fr];
	int bl, br;
	bl = br = 0;
	if (l & (1LL<<p))
		bl = 1;
	if (r & (1LL<<p))
		br = 1;
	//~ printf("SL %d %d %d\n", p, fl, fr);
	if (p == 0)
	{
		if (fr == 0 && !br)
		{
			return 0;
		}
		return 1;
	}
	long long bsol = 0;
	int nfl, nfr;
	if (fl || !bl)
	{
		nfl = fl;
		nfr = fr;
		if (!fr && br)
			nfr = 1;
		long long c = sol(p - 1, nfl, nfr);
		if (pc(c) > pc(bsol) || (pc(c) == pc(bsol) && c < bsol))
			bsol = c;
	}
	if (fr || br)
	{
		nfl = fl;
		nfr = fr;
		if (!fl && !bl)
			nfl = 1;
		long long c = sol(p - 1, nfl, nfr) + (1LL << p);
		if (pc(c) > pc(bsol) || (pc(c) == pc(bsol) && c < bsol))
			bsol = c;
	}

	return (f[p][fl][fr] = bsol);
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		scanf("%lld %lld", &l, &r);
		memset(f, -1, sizeof(f));
		printf("%lld\n", sol(62, 0, 0));
	}
	return 0;
}