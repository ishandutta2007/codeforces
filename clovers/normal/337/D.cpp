#include<bits/stdc++.h>
using namespace std;
const int N=200001;
int n,m,d;
int p[N],bl[N],dp1[N],dp2[N];
vector<int> v[N];
 
struct node{
	int x;
	bool operator < (const node &rhs) const{
		return x>rhs.x;
	}
};
 
void dfs(int u,int f)
{
	multiset<node> st;
	st.clear();
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f) continue;
		dfs(to,u);
		node tmp; tmp.x=dp1[to];
		st.insert(tmp);
	}
	node ttt=*st.begin();
	if(ttt.x!=-1&&!st.empty()) dp1[u]=ttt.x+1;
}
 
void dfs2(int u,int f)
{
	multiset<node> st;
	st.clear();
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f) continue;
		if(dp2[u]!=-1) dp2[to]=dp2[u]+1;
		node tmp; tmp.x=dp1[to];
		st.insert(tmp);
	}
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f) continue;
		node tmp; tmp.x=dp1[to];
		st.erase(st.lower_bound(tmp));
		node mx=*st.begin();
		if(!st.empty()&&mx.x!=-1) dp2[to]=max(dp2[to],mx.x+2); 
		st.insert(tmp);
	}
	st.clear();
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f) continue;
		dfs2(to,u);
	}
}
 
int main()
{
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++) 
	{
		scanf("%d",&p[i]);
		bl[p[i]]=1;
		dp1[p[i]]=0; dp2[p[i]]=0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
	//	cout<<i<<" "<<dp1[i]<<" "<<dp2[i]<<endl;
		if(max(dp1[i],dp2[i])<=d) ans++;
	}
	cout<<ans<<endl;
	return 0;
}