#include<bits/stdc++.h>
typedef long long LL;
int main()
{
	int T,n;
	std::vector<std::pair<int,int> >p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		LL W;scanf("%lld",&W);
		p.clear();
		for(int i=1,w;i<=n;++i)
		{
			scanf("%d",&w);
			if(w<=W)p.push_back(std::make_pair(w,i));
		}
		
		bool flag=false;
		
		std::vector<int>ans;
		LL res=0;
		for(std::size_t i=0;i<p.size();++i)
		{
			if(res+p[i].first<(W+1)/2)
			{
				res+=p[i].first;
				ans.push_back(p[i].second);
			}
			else if(res+p[i].first>W)
			{
				if(p[i].first>=(W+1)/2)
				{
					printf("1\n%d\n",p[i].second);
					flag=true;
					break;
				}
				else
				{
					printf("%llu\n",ans.size());
					for(std::size_t j=0;j<ans.size();++j)
					printf("%d ",ans[j]);
					puts("");
					flag=true;
					break;
				}
			}
			else
			{
				ans.push_back(p[i].second);
				printf("%d\n",static_cast<int>(ans.size()));
				for(std::size_t j=0;j<ans.size();++j)
				printf("%d ",ans[j]);
				puts("");
				flag=true;
				break;
			}
		}
		
		if(!flag)puts("-1");
	}
	
	return 0;
}