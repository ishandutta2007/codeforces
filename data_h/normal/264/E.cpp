#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 210000;

set < pair<int, int> > I, H;

int tree_h[MAXN * 4], tree_i[MAXN * 4];
int n, m;
pair<int, int> stack[MAXN * 2]; int top;

int ask_sec(int root, int L, int R, int l, int r)
{
	if (L == l && r == R)
		return tree_i[root];
	int mid = ((L + R) >> 1);
	if (r <= mid)
		return ask_sec(root * 2, L, mid, l, r);
	else
	if (l > mid)
		return ask_sec(root * 2 + 1, mid + 1, R, l, r);
	else
		return max(ask_sec(root * 2, L, mid, l, mid), ask_sec(root * 2 + 1, mid + 1, R, mid + 1, r));
}

int ask_high(int root, int L, int R, int l, int r)
{
	if (L == l && r == R)
		return tree_h[root];
	int mid = ((L + R) >> 1);
	if (r <= mid)
		return ask_high(root * 2, L, mid, l, r);
	else
	if (l > mid)
		return ask_high(root * 2 + 1, mid + 1, R, l, r);
	else
		return max(ask_high(root * 2, L, mid, l, mid), ask_high(root * 2 + 1, mid + 1, R, mid + 1, r));
}

int find(int root, int l, int r, int v)
{
	if (l == r)
		return root;
	int mid = (l + r) / 2;
	if (v <= mid)
		return find(root * 2, l, mid, v);
	else
		return find(root * 2 + 1, mid + 1, r, v);
}

void change(int h, int p, int v)
{
	//printf("change h: %d  p: %d  v: %d\n", h, p, v);
	h += n;
	//h = find(1, 0, n, h);
	tree_h[h] = v;
	while(h > 1)
	{
		h >>= 1;
		tree_h[h] = max(tree_h[h * 2], tree_h[h * 2 + 1]);
	}
	p += n;
	//p = find(1, 0, n, p);
	tree_i[p] = v;
	while(p > 1)
	{
		p >>= 1;
		tree_i[p] = max(tree_i[p * 2], tree_i[p * 2 + 1]);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int bn;
	scanf("%d %d", &bn, &m);
	for(n = 1; n < bn * 2 || n < m * 2; n *= 2);
	for(int i = 1; i <= m; i++)
	{
		int type;
		scanf("%d", &type);
		set< pair<int, int> >::iterator it;
		if (type == 1)
		{
			int p, h;
			scanf("%d %d", &p, &h);
			h += m - i;
			top = 0;
			it = H.begin();
			while(it != H.end() && it->first < h)
			{
				stack[++top] = *it;
				change(it->first, it->second, 0);
				//H.erase(*H.begin());
				++it;
			}
			stack[++top] = make_pair(h, p);
			for(int i = top; i >= 1; i--) 
				change(stack[i].first, stack[i].second, ask_sec(1, 0, n, stack[i].second + 1, n) + 1);
			H.insert(make_pair(h, p));
			I.insert(make_pair(p, h));
		}else
		{
			int x;
			scanf("%d", &x);
			it = I.begin();
			top = 0;
			for(int i = 1; i <= x; i++, ++it)
			{
				stack[++top] = *it;
				change(it->second, it->first, 0);
			}
			//printf("erase pos %d\n", stack[top].first);
			H.erase(make_pair(stack[top].second, stack[top].first));
			I.erase(make_pair(stack[top].first, stack[top].second));
			top--;
			for(int i = top; i >= 1; i--)
				change(stack[i].second, stack[i].first, ask_high(1, 0, n, stack[i].second + 1, n) + 1);
		}
		printf("%d\n", ask_sec(1, 0, n, 0, n));
	}
	return 0;
}