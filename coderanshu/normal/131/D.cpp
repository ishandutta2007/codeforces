#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=3005;
vector<int> v[N];
bool vis[N],cycle[N];
stack<int> st;
int ans[N];
bool done=false;

void dfs(int s=1,int p=-1)
{
	st.push(s);
	vis[s]=true;
	for(auto j:v[s])
	{
		if(!vis[j])
			dfs(j,s);
		else if(vis[j] && j!=p)
		{
		    done=true;
			while(st.top()!=j)
			{
				int x=st.top();st.pop();
				cycle[x]=true;
			}
			cycle[st.top()]=true;
		}
		if(done)
		    return ;
	}
	st.pop();
}
void dfs2(int s,int dep=0)
{
	vis[s]=true;
	ans[s]=dep;
	for(auto j:v[s])
		if(!vis[j])
			dfs2(j,dep+1);
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y),v[y].pb(x);
	}
	dfs();
	for(int i=1;i<=n;++i)
		vis[i]=cycle[i];
	for(int i=1;i<=n;++i)
		if(cycle[i])
			dfs2(i);
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}