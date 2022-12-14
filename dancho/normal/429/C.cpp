#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int b[32];
int *c;

int btree[1<<14][14];

int bfor[1<<14][14][2];

int tree(int ma, int le);

// forest with at least two trees.
int forest(int ma, int le, int ml = 2)
{
	//~ printf("FOR %d %d %d\n", ma, le, ml);
	int pm = 0;
	if (ml == 2)
		pm = 1;
	if (bfor[ma][le][pm] != -1)
		return bfor[ma][le][pm];
	if (ma == (1LL<<m) - 1)
	{
		if (le >= ml)
			return 1;
		return 0;
	}
	if (ml <= 1)
	{
		if (tree(ma, le))
		{
			bfor[ma][le][pm] = 1;
			return 1;
		}
	}

	int i;
	for (i = m - 1; i >= 0; --i)
	{
		if (!(ma & (1 << i)))
		{
			break;
		}
	}
	int nma = 0;
	for (int sma = 0; sma < (1 << i); ++sma)
	{
		int mm = (ma & sma);
		nma = (ma | sma | (1<<i));
		for (int l = 0; l <= le; ++l)
		{
			//~ printf("SUBTREE %d %lld %d\n", ma, (1LL<<m) - 1 - sma - (1<<i) + mm, nma);
			if (tree((1LL<<m) - 1 - sma - (1<<i) + mm, l))
			{
				if (forest(nma, le - l, ml - 1))
				{
					bfor[ma][le][pm] = 1;
					break;
				}
			}
		}
	}
	if (bfor[ma][le][pm] != 1)
		bfor[ma][le][pm] = 0;
	//~ printf("FOR %d %d %d : %d\n", ma, le, pm, bfor[ma][le][pm]);
	return bfor[ma][le][pm];
}

int tree(int ma, int le)
{
	//~ printf("CT %d %d __ %d\n", ma, le, m);
	if (btree[ma][le] != -1)
		return btree[ma][le];
	if (ma == (1LL<<m) - 1)
	{
		if (le == 1)
			return 1;
		return 0;
	}

	int fr = le;
	int mf = 0;
	int fi = 0;
	for (int i = 0; i < m; ++i)
	{
		if (!((1<<i) & ma))
		{
			++fr;
			if (c[i] > mf)
			{
				mf = c[i];
				fi = i;
			}
		}
	}
	//~ printf("OP %d %d\n", mf, fr);
	if (mf != fr)
	{
		btree[ma][le] = 0;
		return btree[ma][le];
	}

	int nm = ma;
	// fi is the root.
	nm = (nm | (1 << fi));
	btree[ma][le] = forest(nm, le);
	return btree[ma][le];
}

int main()
{
	scanf("%d", &n);
	c = b;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	if (n == 1)
	{
		if (c[0] == 1)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}

	sort(c, c + n);
	if (c[n-1] != n)
	{
		printf("NO\n");
		return 0;
	}
	
	int le = 0;
	while (c[0] == 1 && le < n)
	{
		++le;
		++c;
	}

	m = n - le;
	//~ for (int i = 0; i < m; ++i)
		//~ printf("%d ", c[i]);
	//~ printf("\n");
	//~ printf("O %d %d %d\n", n, m, le);
	if (m > 13)
	{
		printf("NO\n");
		return 0;
	}

	memset(btree, -1, sizeof(btree));
	memset(bfor, -1, sizeof(bfor));

	//~ printf("TT %d %d __ %d\n", 0, le, m);
	if (tree(0, le))
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}