#include<bits/stdc++.h>
using namespace std;
int n,b[200003];
long long a[200003];
vector<int>v[200003],path;
bool vis[200003];
long long ans;
vector<int>res[2];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);
	ans+=a[x];
	if(b[x]!=-1&&a[x]>0)
		a[b[x]-1]+=a[x];
	if(a[x]>0)
		res[0].push_back(x+1);
	else
		res[1].push_back(x+1);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	for(int i=0;i<n;i++){
		scanf("%lld",b+i);
		if(b[i]!=-1)
			v[b[i]-1].push_back(i);
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i);
	cout<<ans<<endl;
	for(int i=0;i<res[0].size();i++)
		cout<<res[0][i]<<' ';
	for(int i=res[1].size()-1;i>=0;i--)
		cout<<res[1][i]<<' ';
}