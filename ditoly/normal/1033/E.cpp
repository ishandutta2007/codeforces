#include<bits/stdc++.h>
using namespace std;
int query(vector<int>&v)
{
	if(v.size()<2)return 0;
	printf("? %d\n",v.size());
	for(int i=0;i<v.size();++i)printf("%d ",v[i]);
	puts("");
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int query(int x,vector<int>&v)
{
	v.push_back(x);
	int res=query(v);
	v.pop_back();
	return res-query(v);
}
#define MN 600
int n,u[MN+5],dep[MN+5],fa[MN+5];
vector<int> R[3];
void get(int x,vector<int>&v,vector<int>&t,int s)
{
	if(!s)return;
	int cnt=0;
	if(s==v.size()){for(int i=0;i<v.size();++i)t.push_back(v[i]);return;}
	vector<int> a,b;
	for(int i=0;i<v.size()/2;++i)a.push_back(v[i]);
	for(int i=v.size()/2;i<v.size();++i)b.push_back(v[i]);
	int p=query(x,a);
	get(x,a,t,p);
	get(x,b,t,s-p);
}
void dfs(int x)
{
	R[u[x]].push_back(x);
	vector<int> v,t;
	for(int i=1;i<=n;++i)if(!u[i])v.push_back(i);
	get(x,v,t,query(x,v));
	for(int i=0;i<t.size();++i)u[t[i]]=3-u[x],fa[t[i]]=x,dep[t[i]]=dep[x]+1;
	for(int i=0;i<t.size();++i)dfs(t[i]);
}
int main()
{
	scanf("%d",&n);
	u[1]=1;dfs(1);
	int x=query(R[1]),y=query(R[2]);
	if(!x&&!y)
	{
		printf("Y %d\n",R[1].size());
		for(int i=0;i<R[1].size();++i)printf("%d ",R[1][i]);
		return 0;
	}
	x=x?1:2;
	for(int i=0;i<R[x].size();++i)
	{
		int s=R[x][i];
		swap(R[x][i],R[x].back());
		R[x].pop_back();
		vector<int> t;
		get(s,R[x],t,query(s,R[x]));
		R[x].push_back(s);
		swap(R[x][i],R[x].back());
		if(t.size())
		{
			vector<int> a,b;
			while(s!=t[0])
				if(dep[s]>dep[t[0]])a.push_back(s),s=fa[s];
				else b.push_back(t[0]),t[0]=fa[t[0]];
			printf("N %d\n",a.size()+b.size()+1);
			for(int i=0;i<a.size();++i)printf("%d ",a[i]);
			printf("%d ",s);
			for(int i=b.size();i--;)printf("%d ",b[i]);
			return 0;
		}
	}
}