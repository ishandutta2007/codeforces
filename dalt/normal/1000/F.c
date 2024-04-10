
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX_N 500000
#define PART 1000

typedef struct _Query {
	int l;
	int r;
	int a;
} Query;
Query queries[MAX_N];
int a[MAX_N + 1];
int indexes[MAX_N];
int cnt[MAX_N];
int summary[PART];

int Compare(const void *a, const void *b)
{
	int i1 = *(int*)a;
	int i2 = *(int*)b;
	int c = queries[i1].l / PART - queries[i2].l / PART;
	return c ? c : (queries[i1].r - queries[i2].r);
}

inline void Add(int i)
{
	cnt[i]++;
	switch (cnt[i])
	{
	case 1:
		summary[i / PART]++; break;
	case 2:
		summary[i / PART]--; break;
	}
}

inline void Remove(int i)
{
	cnt[i]--;
	switch (cnt[i])
	{
	case 0:
		summary[i / PART]--; break;
	case 1:
		summary[i / PART]++; break;
	}
}

inline int Qry()
{
	for (int i = 0; i < PART; i++)
	{
		if (summary[i] != 0)
		{
			for (int j = i * PART; ; j++)
			{
				if (cnt[j] != 1)
				{
					continue;
				}
				return j;
			}
		}
	}

	return 0;
}

void Solve() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &(queries[i].l), &(queries[i].r));
		indexes[i] = i;
	}

	qsort(indexes, q, sizeof(int), Compare);

	int l = queries[indexes[0]].l;
	int r = queries[indexes[0]].l - 1;
	for (int i = 0; i < q; i++)
	{
		int left = queries[indexes[i]].l;
		int right = queries[indexes[i]].r;

		while (l > left)
		{
			Add(a[--l]);
		}
		while (r < right)
		{
			Add(a[++r]);
		}
		while (l < left)
		{
			Remove(a[l++]);
		}
		while (r > right)
		{
			Remove(a[r--]);
		}

		queries[indexes[i]].a = Qry();
	}

	for (int i = 0; i < q; i++)
	{
		printf("%d ", queries[i].a);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\DATABASE\\TESTCASE\\CR46F.in", "r", stdin);
	freopen("E:\\DATABASE\\TESTCASE\\CR46F.out", "w", stdout);
#endif

	Solve();

	return 0;
}