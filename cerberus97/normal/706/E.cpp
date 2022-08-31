/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

#define up 0
#define left 1
#define down 2
#define right 3

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5, D = 4;

struct Node
{
	int val;
	Node *link[D];
}mat[N][N];

int dir[D][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool in_range(int i, int j, int n, int m);

int main()
{
	fast_cin();
	int n, m, q;
	cin >> n >> m >> q;
	Node *start = &mat[1][1];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> mat[i][j].val;
			for (int k = 0; k < D; ++k)
			{
				int x = i + dir[k][0], y = j + dir[k][1];
				if (in_range(x, y, n, m))
					mat[i][j].link[k] = &mat[x][y];
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		mat[i][0].link[right] = &mat[i][1];
		mat[i][1].link[left] = &mat[i][0];
		mat[i][m+1].link[left] = &mat[i][m];
		mat[i][m].link[right] = &mat[i][m+1];
	}
	for (int j = 1; j <= m; ++j)
	{
		mat[0][j].link[down] = &mat[1][j];
		mat[1][j].link[up] = &mat[0][j];
		mat[n+1][j].link[up] = &mat[n][j];
		mat[n][j].link[down] = &mat[n+1][j];
	}


	while (q--)
	{
		int a, b, c, d, h, w;
		cin >> a >> b >> c >> d >> h >> w;

		Node *r1 = start, *r2 = start;
		for (int i = 1; i < a; ++i)	r1 = r1->link[down];
		for (int i = 1; i < b; ++i)	r1 = r1->link[right];
		for (int i = 1; i < c; ++i)	r2 = r2->link[down];
		for (int i = 1; i < d; ++i)	r2 = r2->link[right];

		int i = 1, j = 1;
		for (; j <= w; ++j)
		{
			swap(r1->link[up], r2->link[up]);
			swap(r1->link[up]->link[down], r2->link[up]->link[down]);
			if (j < w)
			{
				r1 = r1->link[right];
				r2 = r2->link[right];
			}
		}
		--j;

		for (; i <= h; ++i)
		{
			swap(r1->link[right], r2->link[right]);
			swap(r1->link[right]->link[left], r2->link[right]->link[left]);
			if (i < h)
			{
				r1 = r1->link[down];
				r2 = r2->link[down];
			}
		}
		--i;

		for (; j >= 1; --j)
		{
			swap(r1->link[down], r2->link[down]);
			swap(r1->link[down]->link[up], r2->link[down]->link[up]);
			if (j > 1)
			{
				r1 = r1->link[left];
				r2 = r2->link[left];
			}
		}
		++j;

		for (; i >= 1; --i)
		{
			swap(r1->link[left], r2->link[left]);
			swap(r1->link[left]->link[right], r2->link[left]->link[right]);
			if (i > 1)
			{
				r1 = r1->link[up];
				r2 = r2->link[up];
			}
		}
		++i;

		if (a == 1 and b == 1)
			start = r2;

		else if (c == 1 and d == 1)
			start = r1;
	}

	Node *cur = start;
	for (int i = 1; i <= n; ++i)
	{
		Node *row_begin = cur;
		for (int j = 1; j <= m; ++j)
		{
			cout << cur->val << ' ';
			if (j < m)
				cur = cur->link[right];
		}
		cout << '\n';
		if (i < n)
			cur = row_begin->link[down];
	}
}

bool in_range(int i, int j, int n, int m)
{
	return (i > 0 and j > 0 and i <= n and j <= m);
}