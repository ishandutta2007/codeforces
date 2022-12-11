#include<bits/stdc++.h>
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		printf("1%c"," \n"[i==n]);
	}
	return 0;
}