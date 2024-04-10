#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int>pii;
vector<int>pat[100000];
int main()
{
	int num,way;
	scanf("%d%d",&num,&way);
	set<pii>se;
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
		se.insert(make_pair(za,zb));
		se.insert(make_pair(zb,za));
	}
	if(num<=9)
	{
		vector<int>vec;
		for(int i=0;i<num;i++)
		{
			vec.push_back(i);
		}
		for(;;)
		{
			bool f=true;
			for(int i=0;i<way;i++)
			{
				if(se.find(make_pair(vec[i],vec[(i+1)%num]))!=se.end())
				{
					f=false;
					break;
				}
			}
			if(f)
			{
				for(int i=0;i<way;i++)
				{
					printf("%d %d\n",vec[i]+1,vec[(i+1)%num]+1);
				}
				return 0;
			}
			if(!next_permutation(vec.begin(),vec.end()))
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	vector<pii>ans;
	int now=0;
	set<int>rem;
	for(int i=1;i<num;i++)
	{
		rem.insert(i);
	}
	for(int i=0;i<num-9;i++)
	{
		set<int>::iterator it=rem.begin();
		for(;;)
		{
			if(se.find(make_pair(now,(*it)))==se.end())
			{
				ans.push_back(make_pair(now,(*it)));
				now=*it;
				rem.erase(it);
				break;
			}
			it++;
		}
	}
	set<int>::iterator it=rem.begin();
	vector<int>vec;
	for(int i=num-8;i<num;i++)
	{
		vec.push_back((*it));
		it++;
	}
	for(;;)
	{
		bool f=true;
		for(int i=0;i<7;i++)
		{
			if(se.find(make_pair(vec[i],vec[i+1]))!=se.end())
			{
				f=false;
				break;
			}
		}
		if(se.find(make_pair(ans[ans.size()-1].second,vec[0]))!=se.end()||se.find(make_pair(vec[vec.size()-1],ans[0].first))!=se.end())
		{
			f=false;
		}
		if(f)
		{
			ans.push_back(make_pair(ans[ans.size()-1].second,vec[0]));
			for(int i=0;i<7;i++)
			{
				ans.push_back(make_pair(vec[i],vec[i+1]));
			}
			ans.push_back(make_pair(vec[vec.size()-1],ans[0].first));
			break;
		}
		if(!next_permutation(vec.begin(),vec.end()))
		{
			abort();
			return 0;
		}
	}
	for(int i=0;i<way;i++)
	{
		printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	}
}