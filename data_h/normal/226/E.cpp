#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 210000;
const int lg = 18;

int q[MAXN], fa[lg + 2][MAXN];
int in[MAXN], out[MAXN], dep[MAXN], destroy[MAXN];
struct node
{
	int l, r, sum;
	node *child[2];
	inline void update()
	{
		sum = child[0]->sum + child[1]->sum;
	}
}Me[MAXN * 20];
int use = 0;

node *root[MAXN];
struct eglist
{
	int other[MAXN], succ[MAXN], last[MAXN], sum;
	void clear()
	{
		memset(last, 0, sizeof(last));
		sum = 0;
	}
	void AddEdge(int a, int b)
	{
		other[++sum] = b, succ[sum] = last[a], last[a] = sum;
	}
}e;

int n, m, rt;

int R[MAXN], E[MAXN], seq[MAXN];

void Dfs(int rt)
{
	int top = 0, len = 0;
	R[++top] = rt; E[rt] = e.last[rt];
	seq[++len] = rt; in[rt] = len; dep[rt] = 1;
	while(top)
	{
		int x = R[top];
		if (E[x] == 0)
		{
			seq[++len] = -x; 
			out[x] = len;
			top--;
			continue;
		}
		int y = e.other[E[x]];
		E[x] = e.succ[E[x]];
		R[++top] = y, E[y] = e.last[y];
		seq[++len] = y; in[y] = len;
		dep[y] = dep[x] + 1;
	}
}

node *Build(int l, int r)
{
	node *tmp = &Me[++use];
	tmp->l = l; tmp->r = r;
	tmp->sum = 0;
	if (l < r)
	{
		int mid = (l + r) / 2;
		tmp->child[0] = Build(l, mid);
		tmp->child[1] = Build(mid + 1, r);
		tmp->update();
	}
	return tmp;
}

node *insert(node *root, int pos, int val)
{
	node *tmp = &Me[++use];
	*tmp = *root;
	if (root->l == root->r)
	{
		tmp->sum = root->sum + val;
		return tmp;
	}
	int mid = (root->l + root->r) / 2;
	if (pos <= mid)
		tmp->child[0] = insert(root->child[0], pos, val);
	else
		tmp->child[1] = insert(root->child[1], pos, val);
	tmp->update();
	return tmp;
}

int calc(node *root, int l, int r)
{
	if (root->l == l && root->r == r)
		return root->sum;
	int mid = (root->l + root->r) / 2;
	if (r <= mid)
		return calc(root->child[0], l, r);
	else
	if (l > mid)
		return calc(root->child[1], l, r);
	else
		return calc(root->child[0], l, mid) + calc(root->child[1], mid + 1, r);
}

int find(int a, int b)
{
	if (dep[a] < dep[b])
		swap(a, b);
	for(int i = lg; i >= 0; i--)
		if (dep[fa[i][a]] >= dep[b])
			a = fa[i][a];
	if (a == b)
		return a;
	for(int i = lg; i >= 0; i--)
		if (fa[i][a] != fa[i][b])
			a = fa[i][a], b = fa[i][b];
	return fa[0][a];
}

int main()
{

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &fa[0][i]);
		if (fa[0][i])
			e.AddEdge(fa[0][i], i);
		else
			rt = i;
	}
	for(int i = 1; i <= lg; i++)
		for(int j = 1; j <= n; j++)
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
	Dfs(rt);
	/*
	for(int i = 1; i <= 2 * n; i++)
		printf("%d ", seq[i]);
	printf("\n");
	for(int i = 1; i <= n; i++)
	{
		printf("%d %d\n", in[i], out[i]);
	}
	return 0;
	*/
	root[0] = Build(1, 2 * n);
	memset(destroy, 0, sizeof(destroy));
	scanf("%d", &m);
	for(int year = 1; year <= m; year++)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int num;
			scanf("%d", &num);
			if (num == 4)
				num = 4;
			root[year] = insert(root[year - 1], in[num], 1);
			root[year] = insert(root[year], out[num], -1);
			destroy[num] = year;
		} else
		{
			root[year] = root[year - 1];
			int a, b, k, y;
			scanf("%d %d %d %d", &a, &b, &k, &y);
			if (k == 0)
			{
				printf("-1\n");
				continue;
			}
			if (destroy[a] <= y)
				k++;
			int c = find(a, b);
			int x = a;
			if (a != c)
			{
				for(int i = lg; i >= 0; i--)
					if (dep[fa[i][x]] > dep[c])
					{
						int now = fa[i][x];
						int res = dep[a] - dep[now] + 1 - 
								  calc(root[year], in[now], in[a]) + 
								  calc(root[y], in[now], in[a]);
						if (res < k)
							x = fa[i][x];
					}
				if (fa[0][x] != c)
					x = fa[0][x];
				int v1 = dep[a] - dep[x] + 1 - 
						 calc(root[year], in[x], in[a]) +
						 calc(root[y], in[x], in[a]);
				if (v1 == k)
				{
					printf("%d\n", x);
					continue;
				}
				k -= v1;
			}
			x = b;
			for(int i = lg; i >= 0; i--)
				if (dep[fa[i][x]] >= dep[c])
				{
					int now = fa[i][x];
					int res = dep[now] - dep[c] + 1 - 
					 		  calc(root[year], in[c], in[now]) + 
							  calc(root[y], in[c], in[now]);
					if (res >= k)
						x = fa[i][x];
				}
			int v2 = dep[x] - dep[c] + 1 -
					 calc(root[year], in[c], in[x]) + 
					 calc(root[y], in[c], in[x]);
			if (v2 == k && x != b)
			{
				printf("%d\n", x);
				continue;
			}
			printf("-1\n");
		}
	}
	return 0;
}