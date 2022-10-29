#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef pair<int,int>pii;
int main()
{
	string str;
	cin>>str;
	char now='2';
	vector<pii>vec;
	for(int i=0;i<str.size();i++)
	{
		if(now!=str[i])
		{
			now=str[i];
			vec.push_back(make_pair(now-'0',1));
		}
		else
		{
			vec[vec.size()-1].second++;
		}
	}
	reverse(vec.begin(),vec.end());
	int ret=0;
	int pt=0;
	if(vec[0].first==0)
	{
		ret+=vec[0].second;
		pt++;
	}
	vector<pii>ans;
	for(;pt+2<vec.size();pt+=2)
	{
		if(vec[pt].second==1)
		{
			ans.push_back(make_pair(0,ret));
		}
		else
		{
			if(vec[pt].second>=2)
			{
				ans.push_back(make_pair(1,ret));
				if(vec[pt+1].second==1)
				{
					vec[pt+1].second--;
					vec[pt+2].second++;
				}
				else
				{
					ans.push_back(make_pair(0,ret+vec[pt].second));
				}
			}
		}
		ret+=vec[pt].second+vec[pt+1].second;
	}
	if(vec[vec.size()-1].second==1)
	{
		ans.push_back(make_pair(0,ret));
	}
	else
	{
		ans.push_back(make_pair(1,ret));
		ans.push_back(make_pair(0,ret+vec[vec.size()-1].second));
	}
	printf("%d\n",int(ans.size()));
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i].first==0)
		{
			printf("+2^%d\n",ans[i].second);
		}
		else
		{
			printf("-2^%d\n",ans[i].second);
		}
	}
}