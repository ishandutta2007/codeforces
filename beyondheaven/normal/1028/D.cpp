#include<bits/stdc++.h>
typedef long long LL;
const LL Mod=1e9+7;
std::priority_queue<int>BUY;
std::priority_queue<int,std::vector<int>,std::greater<int>>SELL;
std::set<int>Unknown;
int n;
char opt[20];
int main()
{
	scanf("%d",&n);
	LL ans=1;
	for(int i=1,x;i<=n;++i)
	{
		scanf("%s%d",opt,&x);
		if(opt[1]=='D')//ADD
		{
			if(!BUY.empty()&&x<BUY.top())BUY.push(x);
			else if(!SELL.empty()&&x>SELL.top())SELL.push(x);
			else Unknown.insert(x);
		}
		else//ACCEPT
		{
			if(!BUY.empty()&&x==BUY.top())
			{
				BUY.pop();
				for(auto v:Unknown)
				SELL.push(v);
				Unknown.clear();
			}
			else if(!SELL.empty()&&x==SELL.top())
			{
				SELL.pop();
				for(auto v:Unknown)
				BUY.push(v);
				Unknown.clear();
			}
			else if(Unknown.count(x))
			{
				ans=ans*2%Mod;
				for(auto v:Unknown)
				if(v>x)SELL.push(v);
				else if(v<x)BUY.push(v);
				Unknown.clear();
			}
			else
			{
				puts("0");
				return 0;
			}
		}
	}
	ans=ans*(Unknown.size()+1)%Mod;
	printf("%lld\n",ans);
	return 0;
}