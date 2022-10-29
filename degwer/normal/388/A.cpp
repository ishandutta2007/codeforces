#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	sort(vec.begin(),vec.end());
	multiset<int>se;
	for(int i=0;i<num;i++)
	{
		if(!se.empty())
		{
			if((*se.begin())<=vec[i])
			{
				int z=(*se.begin())+1;
				se.erase(se.begin());
				se.insert(z);
				continue;
			}
		}
		se.insert(1);
	}
	printf("%d\n",int(se.size()));
}