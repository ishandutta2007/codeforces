#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int p1[10004][502];
int p2[10004][502];
int n, m, x[10004], y[10004];

int Parent1(int at, int node)
{
	if( p1[at][node]==node )
		return node;
	return p1[at][node] = Parent1(at, p1[at][node]);
}

void Connect1(int at, int a, int b)
{
	int p = Parent1(at, a);
	int q = Parent1(at, b);

	if( rand()%2 )
		swap(p, q);

	p1[at][p] = q;

}

int Parent2(int at, int node)
{
	if( p2[at][node]==node  )
		return node;
	return p2[at][node] = Parent2(at, p2[at][node]);
}

void Connect2(int at, int a, int b)
{
	int p = Parent2(at, a);
	int q = Parent2(at, b);

	if( rand()%2 )
		swap(p, q);

	p2[at][p] = q;
}

void process()
{
	int i, j;

	for(i = 1; i <= n; i++)
		p1[0][i] = i;

	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
			p1[i][j] = p1[i-1][j];

		Connect1(i, x[i], y[i]);
	}

	for(i = 1; i <= n; i++)
		p2[m+1][i] = i;

	for(i = m; i >= 1; i--)
	{
		for(j = 1; j <= n; j++)
			p2[i][j] = p2[i+1][j];

		Connect2(i, x[i], y[i]);
	}
}

int p[502];

int Parent(int x)
{
	if(p[x]==x)
		return x;
	return p[x] = Parent(p[x]);
}

void Connect(int a, int b)
{
	a = Parent(a);
	b = Parent(b);

	if(rand()%2)
		swap(a, b);

	p[a] = b;
}

int Solve(int l, int r)
{
	int i;

	for(i = 1; i <= n; i++)
		p[i] = i;

	for(i = 1; i <= n; i++)
	{
		Connect(i, Parent1(l-1, i));
		Connect(i, Parent2(r+1, i));
	}

	int ret = 0;
	for(i = 1; i <= n; i++)
		if( Parent(i) == i )
			ret++;

	return ret;
}

int main()
{
	int i, q, l, r, ans;

	scanf("%d %d", &n, &m);

	for(i = 1; i <= m; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	process();

	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d", &l, &r);
		ans = Solve(l, r);
		printf("%d\n", ans);
	}

	return 0;
}