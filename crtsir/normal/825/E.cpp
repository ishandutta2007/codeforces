#include<bits/stdc++.h>
using namespace std;
bool vis[100003];
int n,m,ans[100003],cntt,cnt[100003];
vector<int>v[100003];
priority_queue<int>canuse;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;a--;b--;
		swap(a,b);
		v[a].push_back(b);
		cnt[b]++;
	}
	cntt=n;
	for(int i=0;i<n;i++)
		if(cnt[i]==0)
			canuse.push(i);
	while(canuse.size()){
		int nx=canuse.top();
		canuse.pop();
		ans[nx]=cntt--;
		vis[nx]=1;
		for(int i=0;i<v[nx].size();i++)
			cnt[v[nx][i]]--;
		for(int i=0;i<v[nx].size();i++)
			if(!vis[v[nx][i]]&&cnt[v[nx][i]]==0)
				canuse.push(v[nx][i]);
	} 
	for(int i=0;i<n;i++)cout<<ans[i]<<' ';
}