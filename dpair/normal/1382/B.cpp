#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int t;
	scanf("%d", &t);
	while(t --)
	{
		int n, tot = 0;
		scanf("%d", &n);
		for (register int i = 1;i < n;i ++)
		{
			scanf("%d", &a[i]);
		}
		scanf("%*d");
		for (register int i = n - 1;i >= 1;i --)
		{
			if(a[i] == 1) tot ^= 1;
			else
			{
				tot = 0;	
			}	
		}
		if(tot) printf("Second\n");
		else printf("First\n");
	}
}