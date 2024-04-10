#include<bits/stdc++.h>
using namespace std;
int m,l[103],r[103];
bool vis[103];
vector<int>v[103];
bool in(int x,int y)
{
	return ((l[y]<l[x]&&l[x]<r[y])||(l[y]<r[x]&&r[x]<r[y]));
}
void dfs(int x)
{
	vis[x]=true;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);
	return ;
}
int n=-1,k,a,b;
/*10
1 -1365 -865
1 1244 1834
2 1 2
1 -1508 -752
2 3 2
2 2 1
1 -779 595
1 -1316 877
2 2 1
1 -698 1700*/
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>k>>a>>b;
		if(k==1)
		{
			++n;
			l[n]=a,r[n]=b;
			for(int j=0;j<n;j++)
				{if(in(j,n))v[j].push_back(n);if(in(n,j))v[n].push_back(j);} 
		}
		else
		{
			--a;
			--b;
			memset(vis,false,sizeof(vis));
			dfs(a);
			printf("%s\n",vis[b]?"YES":"NO");
		}
	}
}