#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int lx[202020], ly[202020], ux[202020], uy[202020];
int a[202020], b[202020], c[202020], d[202020];
void get(int e, int f, int g, int h, int i, int j, int k, int l)
{
	if (max(e, i) <= min(g, k) && max(f, j) <= min(h, l))
	{
		printf("%d %d\n", max(e, i), max(f, j));
		exit(0);
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d%d%d%d", &lx[i], &ly[i], &ux[i], &uy[i]);
	a[num] = b[num] = -2020202020, c[num] = d[num] = 2020202020;
	for (int i = num - 1; i >= 0; i--)a[i] = max(a[i + 1], lx[i]), b[i] = max(b[i + 1], ly[i]), c[i] = min(c[i + 1], ux[i]), d[i] = min(d[i + 1], uy[i]);
	int p = -2020202020, q = -2020202020, r = 2020202020, s = 2020202020;
	for (int i = 0; i < num; i++)
	{
		get(p, q, r, s, a[i + 1], b[i + 1], c[i + 1], d[i + 1]);
		p = max(p, lx[i]), q = max(q, ly[i]), r = min(r, ux[i]), s = min(s, uy[i]);
	}
}