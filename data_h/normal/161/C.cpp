#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 32;
struct seg
{
	int l, r, flag;
}s1, s2;
int Ans, dep = 30;

void Init()
{
	scanf("%d %d %d %d",&s1.l,&s1.r,&s2.l,&s2.r);
}

void Solve(seg &a,int x)
{
	if (a.l == a.r && a.l == x)
	{
		dep = 1;
		return;
	}
	if (a.l < x && a.r > x && a.flag == 0)
	{
		a.r -= x;
		a.flag = 1;
		return;
	}
	
	if (a.l >= x)
	{
		if (a.l == x)
			a.l = 1;
		else
			a.l -= x;
	}
	else
	if (a.flag)
	{
		a.l = 1, a.r = x - 1, a.flag = 0;
		return;
	}
	
	if (a.r >= x)
	{
		if (a.flag)
		{
			a.l = 1, a.r = x - 1, a.flag = 0;
			return;
		}
		else
		{
			if (a.r == x)
				a.r = x - 1;
			else
				a.r -= x;
		}
	}
}

void fresh(int l1,int r1,int l2,int r2)
{
	if (r1 >= l2 && r2 >= l1)
	{
		Ans = max(Ans, min(r1, r2) - max(l1, l2) + 1);
	}
}

void Work()
{

	while(dep)
	{
		int st = 1, mid = (1 << (dep - 1)), ed = (1 << dep) - 1;
		if (s2.flag)
			swap(s1, s2);
		if (s1.flag)
		{
			if (s2.flag)
			{
				fresh(st, s1.r, st, s2.r);
				fresh(s1.l, ed, st, s2.r);
				fresh(st, s1.r, s2.l, ed);
				fresh(s1.l, ed, s2.l, ed);
			}
			else
			{
				fresh(s2.l, s2.r, st, s1.r);
				fresh(s2.l, s2.r, s1.l, ed);
			}
		}
		else
			fresh(s1.l, s1.r, s2.l, s2.r);
			
		Solve(s1, mid);
		Solve(s2, mid);
		dep--;
	}
}

int main()
{
	Init();
	Work();
	printf("%d\n",Ans);
	return 0;
}