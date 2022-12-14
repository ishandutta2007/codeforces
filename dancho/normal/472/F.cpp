#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int n;
int x[10020];
int y[10020];

vector<pii> xop;
vector<pii> yop;

void op(int i, int j, int a[], vector<pii>& ops)
{
	a[i] ^= a[j];
	ops.push_back(make_pair(i, j));
}

int getmsb(int x)
{
	int msb = 30;
	while (msb >= 0 && (x & (1 << msb)) == 0)
	{
		--msb;
	}
	if (msb < 0)
		return -1;
	return msb;
}

void norm(int a[], vector<pii>& ops)
{
	int s = 0;
	for (int k = 30; k >= 0; --k)
	{
		int f = -1;
		for (int i = s; i < n; ++i)
		{
			if (a[i] & (1 << k))
			{
				f = i;
				break;
			}
		}
		if (f == -1)
			continue;
		if (f != s)
		{
			op(s, f, a, ops);
		}
		for (int i = s + 1; i < n; ++i)
		{
			if (a[i] & (1 << k))
			{
				op(i, s, a, ops);
			}
		}
		++s;
	}
	
	// Reverse
	for (int i = s - 1; i >= 0; --i)
	{
		int msb = getmsb(a[i]);
		if (msb < 0)
			return;
		for (int j = i - 1; j >= 0; --j)
		{
			if (a[j] & (1 << msb))
			{
				op(j, i, a, ops);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &y[i]);
	}
	
	norm(x, xop);
	norm(y, yop);
	
	//~ printf("NORM!!\n");
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ printf("%d \n", x[i]);
	//~ }
	//~ printf("\n");
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ printf("%d \n", y[i]);
	//~ }
	//~ printf("\n");
	//~ 
	//~ for (int i = 0; i < (int) xop.size(); ++i)
	//~ {
		//~ printf("xop %d %d\n", xop[i].first, xop[i].second);
	//~ }
	
	int i = 0;
	while (i < n)
	{
		int xm = getmsb(x[i]);
		int ym = getmsb(y[i]);
		if (xm != ym)
		{
			//~ printf("I %d %d %d\n", i, xm, ym);
			//~ for (int l = 0; l < n; ++l)
				//~ printf("%d ", x[l]);
			//~ printf("\n");
			if (xm < ym)
			{
				printf("-1\n");
				return 0;
			}
			for (int j = i - 1; j >= 0; --j)
			{
				if (y[j] & (1 << xm))
				{
					op(j, i, x, xop);
				}
			}
			op(i, i, x, xop);
			int k = i + 1;
			while (k < n && x[k] > 0)
			{
				op(k - 1, k, x, xop);
				op(k, k, x, xop);
				++k;
			}
		}
		else
		{
			++i;
		}
	}

	//~ printf("NORM!!\n");
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ printf("%d \n", x[i]);
	//~ }
	//~ printf("\n");
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ printf("%d \n", y[i]);
	//~ }
	//~ printf("\n");
	
	//~ for (int i = 0; i < (int) xop.size(); ++i)
	//~ {
		//~ printf("xop %d %d\n", xop[i].first, xop[i].second);
	//~ }
	
	for (int i = 0; i < n; ++i)
	{
		if (x[i] != y[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	int m = xop.size() + yop.size();
	printf("%d\n", m);
	for (int i = 0; i < (int) xop.size(); ++i)
	{
		printf("%d %d\n", xop[i].first + 1, xop[i].second + 1);
	}
	for (int i = (int) yop.size() - 1; i >= 0; --i)
	{
		printf("%d %d\n", yop[i].first + 1, yop[i].second + 1);
	}
	return 0;
}