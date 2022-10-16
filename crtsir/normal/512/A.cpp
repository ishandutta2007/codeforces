#include<bits/stdc++.h>
using namespace std;
int n,cnt;
vector<int>v[212];
string s[103];
char ans[103];
bool vis[103],alive[103];
void dfs(int x){
	vis[x]=1;
	alive[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);
		else
			if(alive[v[x][i]]){
				cout<<"Impossible";
				exit(0);
			}
	alive[x]=0;
	ans[cnt++]=char(x+'a');
}
int main(){
	cin>>n>>s[0];
	for(int i=1;i<n;i++)
	{
		cin>>s[i];
		int m1=0,m2=0;
		for(;m1<s[i-1].size()&&m2<s[i].size();m1++,m2++)
			if(s[i][m2]!=s[i-1][m1])
			{
				v[s[i][m2]-'a'].push_back(s[i-1][m1]-'a');
				break;
			}
		if(m1==s[i].size()&&s[i]!=s[i-1])
		{
			cout<<"Impossible";
			return 0;
		}
	}
	for(int i=0;i<26;i++)
		if(!vis[i])
			dfs(i);
	for(int i=0;i<26;i++)
		cout<<ans[i];
}