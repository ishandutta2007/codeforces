#include<bits/stdc++.h>
using namespace std;
int n,m,p[100003],ans[100003];
int dfs(int x){
	if(p[x]==x)return x;
	p[x]=dfs(p[x]);
	return p[x];
}
int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++)p[i]=i;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		p[dfs(x)]=dfs(y);
	}
	for(int i=0;i<m;i++)ans[dfs(i)]++;
	for(int i=0;i<m;i++)n-=max(0,ans[i]-1);
	cout<<n; 
}