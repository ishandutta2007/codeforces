#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int num,mok;
	scanf("%d%d",&num,&mok);
	set<int>se;
	multiset<int>mse;
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		se.insert(zan);
		mse.insert(zan);
		if(se.size()==mok)
		{
			for(int j=0;;j++)
			{
				multiset<int>::iterator it;
				it=mse.find(vec[j]);
				mse.erase(it);
				if(mse.find(vec[j])==mse.end())
				{
					printf("%d %d\n",j+1,i+1);
					return 0;
				}
			}
		}
	}
	printf("-1 -1\n");
}