#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int flag[100][2];
typedef pair<int,int>pii;
vector<pii>pat[100];
vector<int>ans;
bool han;
void dfs(int node,int fl,int za)
{
	if(flag[node][za]!=-1)
	{
		if(flag[node][za]!=fl)
		{
			han=false;
		}
		return;
	}
	flag[node][za]=fl;
	if(fl==1)
	{
		ans.push_back(node);
	}
	for(int i=0;i<pat[node].size();i++)
	{
		dfs(pat[node][i].first,fl^pat[node][i].second,za);
	}
}
int main()
{
	int cit,way;
	scanf("%d%d",&cit,&way);
	for(int i=0;i<way;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--;
		zb--;
		pat[za].push_back(make_pair(zb,1-zc));
		pat[zb].push_back(make_pair(za,1-zc));
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<cit;j++)
		{
			flag[j][i]=-1;
		}
	}
	vector<int>ret;
	for(int i=0;i<cit;i++)
	{
		if(flag[i][0]==-1)
		{
			bool jud=false;
			for(int j=0;j<2;j++)
			{
				ans.clear();
				han=true;
				dfs(i,j,j);
				if(han)
				{
					jud=true;
					for(int k=0;k<ans.size();k++)
					{
						ret.push_back(ans[k]);
					}
					break;
				}
			}
			if(!jud)
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("%d\n",int(ret.size()));
	for(int i=0;i<ret.size();i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ret[i]+1);
	}
	printf("\n");
}