#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 210000, MAXM = MAXN * 2;

int n, m;

struct eglist
{
	int other[MAXM], last[MAXM], succ[MAXM], sum;
	void clear()
	{
		memset(last, 0, sizeof(last));
		sum = 0;
	}
	void AddEdge(int a, int b)
	{
		other[++sum] = b, succ[sum] = last[a], last[a] = sum;
		//other[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
}e, quer;

struct node
{
	int l, r, layer, sum;
	node()
	{
		layer = sum = 0;
	}
	void clear()
	{
		layer = 0; sum = 0;
	}
}T[MAXN * 4];

int iorder[MAXN], oorder[MAXN];

int q[MAXN], eq[MAXN], hash[MAXN], ans[MAXN];

void Build(int root, int l, int r)
{
//	printf("%d %d %d\n", root, l, r);
	T[root].l = l; T[root].r = r;
	T[root].clear();
	if (l == r)
		return ;
	int mid = (l + r) / 2;
	Build(root * 2, l, mid);
	Build(root * 2 + 1, mid + 1, r);
}

inline void update(node &a, node &b, node &c)
{
	if (a.l == a.r)
		a.sum = (a.layer > 0);
	else
	if (a.layer)
		a.sum = a.r - a.l + 1;
	else
		a.sum = b.sum + c.sum;
}

void ins(int root, int l, int r, int val)
{
	//printf("func ins %d %d %d %d", root, l, r, val);
	if (T[root].l == l && T[root].r == r)
	{
		//printf("check %d %d\n", val, T[root].layer);
		T[root].layer += val;
		//if (T[root].layer < 0)
		//printf("check %d %d\n", val, T[root].layer);
		update(T[root], T[root * 2], T[root * 2 + 1]);
		return;
	}
	int mid = (T[root].l + T[root].r) / 2;
	if (l > mid)
		ins(root * 2 + 1, l, r, val);
	else
	if (r <= mid)
		ins(root * 2, l, r, val);
	else
	{
		ins(root * 2, l, mid, val);
		ins(root * 2 + 1, mid + 1, r, val);
	}
	update(T[root], T[root * 2], T[root * 2 + 1]);
}

void DfsOrder()
{
	memset(hash, 0, sizeof(hash));
	int num = 0, top = 0;
	q[++top] = 1; eq[top] = e.last[1];
	iorder[1] = ++num;
	hash[1] = 1;
	while(top)
	{
		if (eq[top] == 0)
		{
			oorder[q[top]] = num;
			top--;
			continue;
		}
		int curx = e.other[eq[top]]; eq[top] = e.succ[eq[top]];
		if (hash[curx])
			continue;
		q[++top] = curx; eq[top] = e.last[curx];
		iorder[curx] = ++num;
		hash[curx] = 1;
	}
}

void Dfs()
{
	memset(hash, 0, sizeof(hash));
	int top = 0;
	q[++top] = 1; eq[top] = e.last[1];
	hash[1] = 1;
	for(int i = quer.last[1]; i; i = quer.succ[i])
	{
		int y = quer.other[i];
		//printf("ins now : %d  l: %d  r : %d  val: %d\n", 1, iorder[y], oorder[y], 1);
		ins(1, iorder[y], oorder[y], 1);
	}
	//return;
	ans[1] = T[1].sum;
	while(top)
	{
		int curx = q[top];
		if (eq[top] == 0)
		{
			for(int i = quer.last[curx]; i; i = quer.succ[i])
			{
				int y = quer.other[i];	
				//printf("ins now : %d  l: %d  r : %d  val: %d\n", curx, iorder[y], oorder[y], -1);
				ins(1, iorder[y], oorder[y], -1);
			}
			top--;
			continue;
		}
		curx = e.other[eq[top]]; eq[top] = e.succ[eq[top]];
		if (hash[curx])
			continue;
		q[++top] = curx; eq[top] = e.last[curx];
		for(int i = quer.last[curx]; i; i = quer.succ[i])
		{
			int y = quer.other[i];
			//printf("ins now : %d  l: %d  r : %d  val: %d\n", curx, iorder[y], oorder[y], 1);
			ins(1, iorder[y], oorder[y], 1);
		}
		ans[curx] = T[1].sum;
		hash[curx] = 1;
	}
}

int main()
{

	// init
	e.clear();
	quer.clear();
	//work
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e.AddEdge(a, b);
		e.AddEdge(b, a);
	}
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		quer.AddEdge(a, b); quer.AddEdge(a, a);
		quer.AddEdge(b, a); quer.AddEdge(b, b);
	}
	DfsOrder();
	//printf("step1\n");
	Build(1, 1, n);
	//printf("step2\n");
	
	/*for(int i = 1; i <= n; i++)
		printf("%d %d\n", iorder[i], oorder[i]);
	return 0;
	*/
	Dfs();
	//printf("step3\n");
	for(int i = 1; i <= n; i++)
		printf("%d%c", ans[i] ? ans[i] - 1 : ans[i], i == n ? '\n' : ' ');
	return 0;
}