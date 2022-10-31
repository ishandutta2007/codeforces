#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			printf("%c",i%k+'a');
		}
		printf("\n");
	}
}