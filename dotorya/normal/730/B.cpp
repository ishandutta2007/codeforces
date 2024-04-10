//*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define mp make_pair

typedef long long ll;
typedef pair<ll, ll> pll;

int n, m;
int T;

int main()
{
	int i, j, k, l;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		if(n == 1)
		{
			printf("! 1 1\n");
			fflush(stdout);
			continue;
		}
		int ma, mi;
		printf("? 1 2\n");
		fflush(stdout);
		char res[10];
		scanf("%s", res);
		if(res[0] == '<') ma=2, mi=1;
		else ma=1, mi=2;
		for(i=3;i<=n;i+=2)
		{
			int uma, umi;
			if(i == n)
			{
				uma=umi=n;
			}
			else
			{
				printf("? %d %d\n", i, i+1);
				fflush(stdout);
				scanf("%s", res);
				if(res[0] == '<') uma=i+1, umi=i;
				else uma=i, umi=i+1;
			}
			printf("? %d %d\n", ma, uma);
			fflush(stdout);
			scanf("%s", res);
			if(res[0] == '<') ma=uma;
			printf("? %d %d\n", mi, umi);
			fflush(stdout);
			scanf("%s", res);
			if(res[0] == '>') mi=umi;
		}
		printf("! %d %d\n", mi, ma);
		fflush(stdout);
	}
	return 0;
}
//*/