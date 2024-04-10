#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	int n;
	int x;
	scanf("%d",&n);
	int k=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]=1;
		while(a[k]==1)
			printf("%d ",k--);
		puts("");
	}
	return 0;
}