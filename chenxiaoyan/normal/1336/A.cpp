/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n,m;
vector<int> nei[N+1];
int fa[N+1],sz[N+1];
void dfs(int x=1){
	sz[x]=1;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa[x])continue;
		fa[y]=x;
		dfs(y);
		sz[x]+=sz[y];
	}
}
int del[N+1];
struct cmp{
	bool operator()(int x,int y){
		return sz[x]-del[x]<sz[y]-del[y];
	}
};
int main(){
	cin>>n>>m;
	m=n-m;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].push_back(y);nei[y].push_back(x);
	}
	dfs();
	priority_queue<int,vector<int>,cmp> q;
	q.push(1);
	long long ans=0;
	int old_m=m;
	while(m){
		int x=q.top();
//		cout<<x<<"\n";
		q.pop();
		m--;
		ans+=sz[x]-del[x];
		for(int i=0;i<nei[x].size();i++){
			int y=nei[x][i];
			if(y==fa[x])continue;
			del[y]=del[x]+1;
			q.push(y);
		}
	}
	cout<<ans-old_m;
	return 0;
}