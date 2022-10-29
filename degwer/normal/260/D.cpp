#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
typedef pair<pii,int>pi3;
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>va,vb;
	int flag=0;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		flag+=zb;
		if(za==0)
		{
			va.push_back(make_pair(zb,i));
		}
		else
		{
			vb.push_back(make_pair(zb,i));
		}
	}
	if(!flag)
	{
		for(int i=0;i<va.size();i++)
		{
			printf("%d %d 0\n",va[i].second+1,vb[0].second+1);
		}
		for(int i=1;i<vb.size();i++)
		{
			printf("%d %d 0\n",va[0].second+1,vb[i].second+1);
		}
		return 0;
	}
	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());
	int pta=0,ptb=0;
	vector<pi3>ans;
	for(;;)
	{
		if(pta==va.size()||ptb==vb.size())
		{
			break;
		}
		if(va[pta].first>vb[ptb].first)
		{
			ans.push_back(make_pair(make_pair(va[pta].second,vb[ptb].second),vb[ptb].first));
			va[pta].first-=vb[ptb].first;
			ptb++;
		}
		else
		{
			ans.push_back(make_pair(make_pair(va[pta].second,vb[ptb].second),va[pta].first));
			vb[ptb].first-=va[pta].first;
			pta++;
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		printf("%d %d %d\n",ans[i].first.first+1,ans[i].first.second+1,ans[i].second);
	}
}