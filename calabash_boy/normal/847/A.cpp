#include <cstdio>
#include <cstdlib>

#define MAXN 110

int n;
int l[MAXN], r[MAXN];
int fa[MAXN];
int lz[MAXN], rz[MAXN], lc, rc;

int getfa(int n)
{
	if (fa[n] == 0)
		return n;

	fa[n] = getfa(fa[n]);
	return fa[n];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &l[i], &r[i]);

	for (int i = 1; i <= n; i++) {
		if (!l[i])
			lz[lc++] = i;
		else if (getfa(l[i]) != getfa(i))
			fa[getfa(i)] = l[i];

		if (!r[i])
			rz[rc++] = i;
		else if (getfa(r[i]) != getfa(i))
			fa[getfa(i)] = r[i];
	}

	for (int i = 0; i < lc - 1; i++) {
		int j = i;
		while (getfa(lz[i]) == getfa(rz[j]))
			j++;

		int tmp = rz[j];
		rz[j] = rz[i];
		rz[i] = tmp;

		l[lz[i]] = rz[i];
		r[rz[i]] = lz[i];
		fa[getfa(lz[i])] = rz[i];
	}

	for (int i = 1; i <= n; i++)
		printf("%d %d\n", l[i], r[i]);

	return 0;
}