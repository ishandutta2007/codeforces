#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
struct Fenwick_tree
{
	int arr[100005], n; 
	inline void init(int _n)
	{
		n = _n; 
		memset(arr, 0, sizeof(arr)); 
	}
	inline void modify(int pos, int x)
	{
		for (; pos <= n; pos += pos & -pos)
			arr[pos] += x; 
	}
	inline int query(int pos)
	{
		int res = 0; 
		for (; pos; pos -= pos & -pos)
			res += arr[pos]; 
		return res; 
	}
} tree[15][15][5]; 
inline int trans(char c)
{
	switch (c)
	{
	case 'A':
		return 0; 
	case 'C':
		return 1; 
	case 'G':
		return 2; 
	case 'T':
		return 3; 
	}
}
char s[100005], t[15]; 
int main()
{
	// freopen("C.in", "r", stdin); 
	scanf("%s", s); 
	int n = strlen(s); 
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < 4; k++)
				tree[i][j][k].init(n); 
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 10; j++)
			tree[j][i % j][trans(s[i])].modify(i + 1, 1); 
	}
	int q; 
	scanf("%d", &q);
	while (q--)
	{
		int tp; 
		scanf("%d", &tp); 
		if (tp - 1)
		{
			int l, r; 
			scanf("%d%d%s", &l, &r, t); 
			int m = strlen(t); 
			l--; 
			int st = m - l % m, ans = 0;
			for (int i = 0; i < m; i++)
				ans += tree[m][i][trans(t[(st + i) % m])].query(r) - tree[m][i][trans(t[(st + i) % m])].query(l); 
			printf("%d\n", ans);
		}
		else
		{
			int x; 
			char c; 
			scanf("%d %c", &x, &c); 
			x--; 
			for (int i = 1; i <= 10; i++)
				tree[i][x % i][trans(s[x])].modify(x + 1, -1); 
			for (int i = 1; i <= 10; i++)
				tree[i][x % i][trans(c)].modify(x + 1, 1); 
			s[x] = c; 
		}
	}
	return 0; 
}