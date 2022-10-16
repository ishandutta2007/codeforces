#include<bits/stdc++.h>
using namespace std;
vector<int>v[101];
string s[101];
int tot=-1,ans[101];
bool vis[101],isg[101],q=true;
void dfs(int x)
{
	vis[x]=true;
	isg[x]=true;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);
		else
			if(isg[v[x][i]])
				q=false;
	isg[x]=false;
	ans[++tot]=x;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=1;i<n;i++)
	{
		int j;
		int m1=s[i-1].size(),m2=s[i].size();
		for(j=0;j<m1&&j<m2&&s[i-1][j]==s[i][j];j++);
		if(j<m1&&j<m2)
			v[s[i-1][j]-'a'].push_back(s[i][j]-'a');
		else
			if(m1>m2)
				q=false;
	}
	for(int i=0;i<26;i++)
		if(!vis[i])
			dfs(i);
	if(q)
		for(int i=tot;i>-1;i--)
			putchar(ans[i]+'a');
	else
		cout<<"Impossible";
}