#include<bits/stdc++.h>
using namespace std;
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int n;
map<int,vector<int> > g; 
void dfs(int v,int pre)
{
	printf("%d",v);
	for(int i=0;i< g[v].size();i++)
	{
		int u = g[v][i];
		if(u != pre)
		{
			printf(" ");
			dfs(u,v);
		}
	}
	cout<<endl;
}
int main()
{
	int u,v;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
//	cout<<"finish"<<endl;
	for(auto k : g)
	{
		if(k.second.size() == 1)
		{
			dfs(k.first,-1);
			break; 
		}
	}
	return 0;
}