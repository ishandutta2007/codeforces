#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
typedef pair<int,int>pii;
typedef pair<int,pii>pi3;
bool flag[1<<16];
vector<pii>vec;
vector<pii>ans;
void calc(int node)
{
	if(flag[node])return;
	if(vec[node].first>1)return;
	if(vec[node].first==0)return;
	flag[node]=true;
	vec[vec[node].second].first--;
	vec[vec[node].second].second^=node;
	ans.push_back(make_pair(node,vec[node].second));
	calc(vec[node].second);
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		vec.push_back(make_pair(za,zb));
	}
	fill(flag,flag+num,false);
	for(int i=0;i<num;i++)calc(i);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}