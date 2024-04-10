#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500000, dex = 27;

int d, N;
char str[MAXN], st[MAXN];
long long sp[MAXN], sr[MAXN], mi[MAXN];

void Init()
{
	scanf("%d\n", &d);
	gets(str + 1);
	N = strlen(str + 1);	
	mi[0] = 1; 
	for(int i = 1;i <= N;i++)
		mi[i] = mi[i - 1] * dex;
} 

int same(int l, int r)
{
	sp[r] = sp[r - 1] + (str[r] - 'a') * mi[r - 1];
	sr[r] = sr[r - 1] + (str[r] - 'a') * mi[N - r];	
	if (l <= 0)
		return 0;
	long long s1 = (sp[r] - sp[l - 1]) * mi[N - r];
	long long s2 = (sr[r] - sr[l - 1]) * mi[l - 1];
	return s1 == s2;
}

int Dfs(int dep, int ok)
{
	if (dep > N)
		return ok;
	if (dep < 1)
	   return ok;
	if (ok)
	{
		for(str[dep] = 'a';str[dep] <= 'z';str[dep]++)
		{
			if (!same(dep - d + 1, dep) && !same(dep - d, dep))
            {
                return Dfs(dep + 1, 1);
            }
		}
		return 0;
	}
	else
	{
		for(++str[dep];str[dep] <= 'z';str[dep]++)
		{
			if (!same(dep - d + 1, dep) && !same(dep - d, dep))
            {
                 return Dfs(dep + 1, 1);
            } 
		}
		return Dfs(dep - 1, 0);
	}
}

void Work()
{
	int i;
	for(i = 1;i <= N;i++)
		if (same(i - d + 1, i) || same(i - d, i))
			break;
	if (i > N)
		i = N;
	if (Dfs(i, 0))
		puts(str + 1);
	else
		puts("Impossible");
}

int main()
{
	Init();
	Work();
	return 0;
}