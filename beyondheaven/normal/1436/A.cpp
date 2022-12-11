#include<bits/stdc++.h>
int main()
{
	int T;std::cin>>T;
	while(T--)
	{
		int s=0,x,n,m;
		std::cin>>n>>m;
		for(int i=1;i<=n;++i)
		{
			std::cin>>x;
			s+=x;
		}
		if(s==m)puts("YES");
		else puts("NO");
	}
	return 0;
}