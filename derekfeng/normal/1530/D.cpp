#include <bits/stdc++.h>
using namespace std;
int T,n,a[200004],b[200004],ans;
int t,sta[200004];
bool vis[200004],ins[200004],used[200004],fnd[200004];
void dfs(int x){
	sta[t++]=x;ins[x]=vis[x]=1;
	if(vis[a[x]]){
		if(ins[a[x]]){
			used[x]=1;
			for(int i=t-2;;i--){
				used[sta[i]]=1;
				if(sta[i]==a[x])break;
			}
		}
	}else dfs(a[x]);
	t--;ins[x]=0;
}
void sol(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)ins[i]=vis[i]=used[i]=fnd[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=0;
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	vector<int>ord,v1,v2;
	for(int i=1;i<=n;i++)if(!used[i])ord.push_back(i);
	for(int i=1;i<=n;i++)if(used[i])ord.push_back(i);
	for(auto x:ord)if(!fnd[a[x]])fnd[a[x]]=1,b[x]=a[x],ans++;
	for(int i=1;i<=n;i++)if(b[i]==0)v1.push_back(i);
	for(int i=1;i<=n;i++)if(!fnd[i])v2.push_back(i);
	for(auto x:v1){
		int y=v2.back();
		if(x!=y)b[x]=y,v2.pop_back(); 
		else if(v2.size()>1){
			v2.pop_back();
			int z=v2.back();
			b[x]=z;v2.pop_back();v2.push_back(y); 
		}else{
			for(auto z:v1)if(z!=y){
				b[x]=b[z],b[z]=y;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";puts("");
}
int main(){
	cin>>T;
	while(T--)sol();
}