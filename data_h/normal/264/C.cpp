#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200000;
const long long inf = 20000000000000ll;

int n, q;
int c[MAXN], v[MAXN], flag[MAXN];
long long a, b, cv[MAXN], hl[MAXN], hr[MAXN];
struct node
{
	int col;
	long long val;
}l, r;

int main()
{

	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for(int i = 1; i <= q; i++)
	{
		scanf("%I64d %I64d", &a, &b);
		for(int j = 1; j <= n; j++)
			cv[j] = -inf;
		l.val = 0; l.col = -1;
		r.val = 0; r.col = -2;
		for(int j = 1; j <= n; j++)
		{
			long long tmp = cv[c[j]] + a * v[j];
			if (c[j] != l.col)
				tmp = max(tmp, l.val + b * v[j]);
			else
				tmp = max(tmp, r.val + b * v[j]);
			
			if (c[j] != l.col && c[j] != r.col)
			{
				if (tmp > l.val)
					r = l, l.val = tmp, l.col = c[j];
				else
				if (tmp > r.val)
					r.val = tmp, r.col = c[j];
			} else
			if (c[j] == l.col && tmp > l.val)
				l.val = tmp;
			else
			if (c[j] == r.col && tmp > r.val)
				r.val = tmp;
			
			if (r.val > l.val)
				swap(l, r);
			cv[c[j]] = max(cv[c[j]], tmp);
			//printf("l: %I64d %I64d\n", l.val, r.val);
		}
		printf("%I64d\n", l.val);
	}
	return 0;
}