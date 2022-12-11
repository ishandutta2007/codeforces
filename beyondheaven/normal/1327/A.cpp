#include<bits/stdc++.h>
int main()
{
	int T,n,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(((n-k)&1)||(n<1LL*k*k))puts("NO");
		else puts("YES");
	}
	return 0;
}