#include<bits/stdc++.h>
using namespace std;
int n,m,k,tmp;
vector<int>v[100003],V[2],path;
bool canuse[100003],vis[100003];
void dfs(int x,int p){
	if(!tmp)return;
	tmp--;
	canuse[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p&&!canuse[v[x][i]])
			dfs(v[x][i],x);
}
void dfs2(int x,bool tp,int p){
	V[tp].push_back(x); 
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p&&canuse[v[x][i]])
			dfs2(v[x][i],tp^1,x);
}
void dfs3(int x,int p)
{
	if(vis[x]){
		cout<<"2\n";
		int cntt=0;
		for(int i=path.size()-1;i>=0;i--)
		{
			cntt++;
			if(path[i]==x)break;
		}
		cout<<cntt<<endl;
		for(int i=path.size()-1;i>=0;i--)
		{
			cout<<path[i]+1<<' ';
			if(path[i]==x)break;
		}
		exit(0);
	}
	path.push_back(x);
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p&&canuse[v[x][i]])
			dfs3(v[x][i],x);
	vis[x]=0;
	path.pop_back();
} 
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	tmp=k;
	dfs(0,-1);
	dfs3(0,-1);
	dfs2(0,0,-1);
	cout<<1<<endl;
	if(V[0].size()<=V[1].size())
		for(int i=0;i<(k+1)/2;i++)
			cout<<V[1][i]+1<<' ';
	else
		for(int i=0;i<(k+1)/2;i++)
			cout<<V[0][i]+1<<' ';
}