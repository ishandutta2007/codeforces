#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MAXN = 200000;
const long long inf = 1e18;
int n;
struct box
{
	long long k, a;
}p[MAXN], u[MAXN];


int cmp(box a, box b)
{
	return a.k < b.k;
}

void calc(long long &res, long long base, long long times)
{
	long long tmp = base;
	while(times)
	{
		if (times & 1)
		{
			if (res > inf / tmp)
				res = inf;
			else
				res *= tmp;
		}
		times >>= 1;
		if (tmp > inf / tmp)
			tmp = inf;
		else
			tmp *= tmp;
	}
}

int solve(long long len)
{
	long long hollow = 1;
	calc(hollow, 4, len - p[n].k);
	for(int i = n; i >= 1; i--)
	{
		if (hollow < p[i].a)
			return 0;
		hollow -= p[i].a;
		calc(hollow, 4, p[i].k - p[i - 1].k);
	}
	return 1;
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%I64d %I64d", &p[i].k, &p[i].a);
	}
	sort(p + 1, p + n + 1, cmp);
	int bn = n; n = 0;
	for(int i = 1; i <= bn; i++)
	{
		if (n && p[n].k == p[i].k)
			p[n].a += p[i].a;
		else
			p[++n] = p[i];
	}
	long long hollow = 0;
	for(int i = n; i >= 1; i--)
	{
		long long use = min(hollow, (long long)p[i].a);
		p[i].a -= use;	
		hollow += p[i].a;
		calc(hollow, 4, p[i].k - p[i - 1].k);
	}
	while(n && p[n].a == 0)
		n--;
	long long l = p[n].k + 1, r = 2000000000, mid;
	while(l < r)
	{
		mid = (l + r) / 2;
		if (solve(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%I64d\n", l);
	return 0;
}