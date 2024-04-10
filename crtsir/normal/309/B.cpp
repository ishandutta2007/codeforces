#include<bits/stdc++.h>
using namespace std;
string s[1000002];
int n,c,r,cnt[1000002],fa[1000002],top,a[1000002],ans[1000002],vis[1000002];
vector<int>v[1000002];
void dfs(int x){
	a[top++]=x;
	vis[x]=1;
	ans[x]=a[max(0,top-1-r)]-x;
	for(int i=0;i<v[x].size();i++)if(!vis[v[x][i]])dfs(v[x][i]);
	top--;
}
int main(){
	cin>>n>>r>>c;
	for(int i=0;i<n;i++)cin>>s[i];
	int cc=0;
	int j=0;
	for(int i=0;i<=n;i++)
	{ 
		if(s[i].size()>c)
			j=i+1,
			fa[i]=i,
			cc=0;
		else
		{ 
			for(j;j<n&&cc<=c+1;j++)cc+=(s[j].size()+1);
			fa[i]=j-(cc>c+1); 
			cc-=(s[i].size()+1);
		}
		if(fa[i]!=i)
			v[fa[i]].push_back(i);
	}
	for(int i=0;i<=n;i++)
		if(fa[i]==i)
			top=0, 
			dfs(i);
	//top=0;dfs(n);
	int maxn=0;
	for(int i=0;i<=n;i++)maxn=max(maxn,ans[i]);
	for(int i=0;i<n;i++)
		if(ans[i]==maxn&&s[i].size()<=c){
			for(j=0;j<r;j++){
				int cc=0;
				for(;i<n&&cc+s[i].size()+1<=c+1;i++){cc+=s[i].size()+1,cout<<s[i];if(cc<c)cout<<' ';} 
				cout<<endl;
			}
			return 0;
		}
}