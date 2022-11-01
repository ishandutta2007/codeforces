#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MAXN = 6000;

struct node
{
	int val;
	double x;
}p[MAXN];
int f[MAXN];
int n, m;
int cmp(node a, node b)
{
	return a.x < b.x;
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %lf", &p[i].val, &p[i].x);
	}
	sort(p + 1, p + n + 1, cmp);
	f[0] = 0;
	int mm = 0;
	for(int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for(int j = 1; j < i; j++)
		if (p[j].val <= p[i].val)
			f[i] = max(f[i], f[j] + 1);
		mm = max(mm, f[i]);
	}
	printf("%d\n", n - mm);
	return 0;
}