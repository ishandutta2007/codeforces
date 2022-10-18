#include<stdio.h>
#include<string.h>

typedef __int64 LL;

LL ans[10] =
{
	0,
	1,
	2, 
	9,
	64,
	625,
	7776,
	117649,
	2097152
};

LL MOD = 1000000007;

LL bigmod(LL a, LL b)
{
	if(b==0) return 1;
	LL x = bigmod(a, b/2);
	x = (x*x)%MOD;
	if(b&1) x = (x*a)%MOD;
	return x;
}

int sum;
int here[10];

int check(int a)
{
	int vis[10], i, now;
	memset(vis, 0, sizeof(vis));

	//if(here[0]==0) return 0;

	for(i = 1; i < a; i++)
	{
		memset(vis, 0, sizeof(vis));
		now = i;
		vis[now] = 1;
		while( now != 0 )
		{
			now = here[now];
			if(vis[now]==1) break;
			vis[now] = 1;
		}		

		if(now) return 0;
	}

	return 1;
}

void f(int a, int at)
{
	if(a == at)
	{
		if(check(a))
			sum++;
		return;
	}

	int i;
	for(i = 0; i < a; i++)
	{
//		if(at==i) continue;
		here[at] = i;
		f(a, at+1);
	}
}

int main()
{
	int i;

/*	for(i = 2; i <= 8; i++)
	{
		sum = 0;
		f(i, 0);
		printf("%d %d\n", i, sum);
	}
*/

	int n, k;

	scanf("%d%d",&n,&k);

	LL s = ans[k];
	if(n>k) s = (s*bigmod(n-k, n-k))%MOD;

	printf("%I64d\n", s);

	return 0;
}