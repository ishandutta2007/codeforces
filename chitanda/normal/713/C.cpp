#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long ABS(long long a)
{return a<0? -a: a;}

map <long long, int> mp;
long long dp[2][5005], val[5005], m[5005];

int main()
{   
	int i, j, n, delta, maxi, top;
	scanf("%d", &n);
	for(i=0; i<n; i++)
    {
			scanf("%lld", &m[i]);
			m[i]-=i;
			mp[m[i]]++;
    }
	i=0;
	for(map<long long, int>::iterator it=mp.begin(); it!=mp.end(); it++)
		val[i++]=it->first;
	top=i;
	for(j=0; j<top; j++)
		dp[1][j]=ABS(m[0]-val[j]);
	for(i=1; i<n; i++)
    {
			for(j=0; j<top; j++)
				dp[0][j]=dp[1][j];
			for(j=0; j<top; j++)
        {
					dp[1][j]=dp[0][j]+ABS(m[i]-val[j]);
					if (j)
            {
							delta=ABS(m[i]-val[j])-ABS(m[i]-val[j-1]);
							if (dp[1][j]>dp[1][j-1]+delta)
								dp[1][j]=dp[1][j-1]+delta;
            }
        }
    }
	maxi=0;
	for(j=1; j<top; j++)
		if (dp[1][j]<dp[1][maxi])
			maxi=j;
	printf("%lld\n", dp[1][maxi]);

}