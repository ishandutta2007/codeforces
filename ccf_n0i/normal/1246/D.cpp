#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,j,sf[100005],len[100005],til[100005];
vector<int> son[100005];
vector<int> ans;
bool cmp(int x,int y)
{
	return len[x]<len[y];
}
void dfs(int x)
{
	if(son[x].empty())
	{
		len[x]=1;til[x]=x;
		return;
	}
	int i,_;
	for(i=0;i<son[x].size();i++)
	{
		dfs(son[x][i]);
	}
	sort(son[x].begin(),son[x].end(),cmp);
	sf[son[x][0]]=x;
	for(i=1;i<son[x].size();i++)
	{
		sf[son[x][i]]=til[son[x][i-1]];
		rep(_,len[son[x][i-1]]) ans.push_back(son[x][i]);
	}
	til[x]=til[son[x][son[x].size()-1]];
	len[x]=len[son[x][son[x].size()-1]]+1;
}
int main()
{
	scanf("%d",&n);
	rep(i,n-1)
	{
		int x;
		scanf("%d",&x);
		son[x+1].push_back(i+1);
	}
	dfs(1);
	stack<int> stk;
	int t=til[1];
	while(t!=1){stk.push(t);t=sf[t];}
	printf("0");while(!stk.empty()){printf(" %d",stk.top()-1);stk.pop();}
	printf("\n%d\n",ans.size());for(i=0;i<ans.size();i++) printf("%d ",ans[i]-1);
	return 0;
}