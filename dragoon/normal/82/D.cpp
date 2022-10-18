#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

inline int MAX(int a, int b)
{
	if(a>b) return a;
	return b; 
}

inline int MIN(int a, int b)
{
	if(a<b) return a;
	return b; 
}

int dp[1002][1002];
int n;
int man[1002];

int DP(int prev, int at)
{
	int &ret = dp[prev][at];
	
	if(ret) return ret;

	if(at==n+1)
	{
		return ret=man[prev];
	}

	if(at==n)
	{
		return ret = MAX(man[prev], man[n]);
	}

	ret = MAX(man[prev], man[at]) + DP(at+1,at+2);
	ret = MIN(ret, MAX(man[prev], man[at+1]) + DP(at,at+2));
	ret = MIN(ret, MAX(man[at], man[at+1]) + DP(prev,at+2));

	return ret;
}

void PDP(int prev, int at)
{
	int ret = DP(prev,at);

	if(at==n+1)
	{
		printf("%d\n",prev);
		return;
	}

	if(at==n)
	{
		printf("%d %d\n",prev,n);
		return;
	}

	if(ret == MAX(man[prev], man[at]) + DP(at+1,at+2))
	{
		printf("%d %d\n",prev,at);
		PDP(at+1,at+2);
		return;
	}

	if(ret == MAX(man[prev], man[at+1]) + DP(at,at+2))
	{
		printf("%d %d\n",prev,at+1);
		PDP(at,at+2);
		return;
	}

	if(ret == MAX(man[at], man[at+1]) + DP(prev,at+2))
	{
		printf("%d %d\n",at,at+1);
		PDP(prev,at+2);
		return;
	}
}

int main()
{
	int i,ans,j;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&man[i]);
	}

	if(n==1) 
	{
		printf("%d\n",man[1]);
		printf("1\n");
		return 0;
	}
	else if(n==2)
	{
		printf("%d\n",MAX(man[1],man[2]));
		printf("1 2\n");
		return 0;
	}

	////

	ans = MAX(man[1],man[2])+DP(3, 4);
	ans = MIN(ans, MAX(man[1],man[3])+DP(2, 4));
	ans = MIN(ans, MAX(man[2],man[3])+DP(1, 4));

	for(i=1;i<=3;i++)
		for(j=i+1;j<=3;j++)
			if(ans == MAX(man[i], man[j]) + DP(6 - i - j, 4))
			{
				printf("%d\n",ans);
				printf("%d %d\n",i,j);
				PDP(6 - i - j, 4);
//				printf("\n");
				return 0;
			}

	return 0;
}