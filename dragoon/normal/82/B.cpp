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

vector<int> V[40000],Y[200];
int counts[300];

int main()
{
	int n,nn,ok,cnt;
	int i,j,mmin,k,a,sz;

	scanf("%d",&n);
	nn = n*(n-1)/2;

	mmin = 1000000;

	for(i=0;i<nn;i++)
	{
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&a);
			V[i].push_back(a);

			if(a<mmin) mmin=a;
		}
	}

	if(n==2)
	{
		printf("1 %d\n",V[0][0]);
		printf("%d",V[0].size()-1);
		for(i=V[0].size()-1;i>=1;i--)
			printf(" %d",V[0][i]);
		printf("\n");
		return 0;
	}


	sz = 0;
	for(i=0;i<nn;i++)
	{
		ok = 0;
		for(j=V[i].size()-1;j>=0;j--)
		{
			if(V[i][j]==mmin)
			{
				ok = 1;
				break;
			}
		}

		if(ok)
		Y[sz++] = V[i];
	}

	for(i=0;i<sz;i++)
		sort(Y[i].begin(),Y[i].end());

	for(i=0;i<2;i++)
		for(j=Y[i].size()-1;j>=0;j--)
			counts[Y[i][j]]++;

	cnt=0;
	for(i=1;i<=200;i++)
		if(counts[i]==2)
			cnt++;

	printf("%d",cnt);
	for(i=1;i<=200;i++)
		if(counts[i]==2)
			printf(" %d",i);
	printf("\n");

	for(i=0;i<sz;i++)
	{
		cnt=0;
		for(j=Y[i].size()-1;j>=0;j--)
			if(counts[ Y[i][j] ] != 2)
				cnt++;

		printf("%d",cnt);
		for(j=Y[i].size()-1;j>=0;j--)
			if(counts[ Y[i][j] ] != 2)
				printf(" %d",Y[i][j]);
		printf("\n");
	}

	return 0;
}