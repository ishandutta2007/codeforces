#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef pair<int,int>pii;
typedef pair<pii,int>pi3;
int main()
{
	FILE *fr=fopen("input.txt","r");
	FILE *fw=fopen("output.txt","w");
	int num;
	fscanf(fr,"%d",&num);
	map<int,vector<pii> >ma;
	for(int i=0;i<num;i++)
	{
		int za,zb,zc;
		fscanf(fr,"%d%d%d",&za,&zb,&zc);
		ma[zb].push_back(make_pair(za,0));
		ma[zc].push_back(make_pair(za,1));
	}
	multiset<int>se;
	se.insert(0);
	vector<pii>ans;
	map<int,vector<pii> >::iterator po=ma.begin();
	for(;;)
	{
		if(po==ma.end())
		{
			break;
		}
		pair<int,vector<pii> >zan=*po;
		multiset<int>::iterator it=se.end();
		it--;
		int bef=*it;
		for(int i=0;i<zan.second.size();i++)
		{
			if(zan.second[i].second==0)
			{
				se.insert(zan.second[i].first);
			}
			else
			{
				it=se.find(zan.second[i].first);
				se.erase(it);
			}
		}
		it=se.end();
		it--;
		if(bef!=*it)
		{
			ans.push_back(make_pair(zan.first,bef));
			ans.push_back(make_pair(zan.first,*it));
		}
		po++;
	}
	fprintf(fw,"%d\n",int(ans.size()));
	for(int i=0;i<ans.size();i++)
	{
		fprintf(fw,"%d %d\n",ans[i].first,ans[i].second);
	}
}