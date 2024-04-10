#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 600000;

struct block
{
	int l, r;
}bck[MAXN];
int top;
int n, t, notv[MAXN], head, tail, lasth;
char str[MAXN];

int ok(int init)
{
	top = 0;
	head = tail = 0; head++;
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		res++;
		if (str[i] == 'H')
		{
			if (init)
				init--;
			else
				notv[++tail] = i;
		} else
		if (str[i] == 'S')
		{
			init++;
			if (head <= tail)
			{
				init--;
				int x = notv[head++];
				if (i >= lasth && head > tail)
					res += i - x;
				else
					res += (i - x) * 2;
				while(top)
				{
					long long tmp = (bck[top].r - bck[top].l) * 2;
					if (i >= lasth && head > tail)
						tmp += i - x;
					else
						tmp += (i - x) * 2;
					long long cmb = 0;
					if (i >= lasth && head > tail)
						cmb += i - bck[top].l;
					else
						cmb += (i - bck[top].l) * 2;
					
					if (cmb <= tmp)
					{
						res = res - tmp + cmb;
						x = bck[top].l; 
						top--;
					}
					else
						break;
				}
				bck[++top].l = x; bck[top].r = i;
			}
		}
		if (i >= lasth && head > tail)
			break;
	}
	if (head <= tail)
		return 0;
	int la = lasth;
	while(top)
	{
		if (bck[top].r > la)
		{
			top--;
			continue;
		}
		long long tmp = (bck[top].r - bck[top].l) * 2;;
		long long cmb = la - bck[top].l;
		if (cmb <= tmp)
		{
			res = res - tmp + cmb;
			la = bck[top].l;
			top--;
		} else
		break;
	}
	return res <= t;
}

int main()
{

	scanf("%d %d\n", &n, &t);
	gets(str + 1);
	lasth = 1;
	for(int i = 1; i <= n; i++)
		if (str[i] == 'H')
			lasth = i;
	int l = 0, r = n, mid;
	while(l < r)
	{
		mid = (l + r) / 2;
		if (ok(mid))
			r = mid;
		else
			l = mid + 1;
	}
	//l = 0;
	if (!ok(l))
		printf("-1\n");
	else
		printf("%d\n", l);
	return 0;
}