#include<bits/stdc++.h>
using namespace std;
int n;
int p[2003]; 
int dis[2003],fr[2003];
void dfs(int u){
	if(dis[u]==0)
		return;
	if(fr[u]==0){
		int sw=(u&1)?u+1:u-1;
		dfs(sw);
		for(int i=1;i<=n;i++)swap(p[2*i],p[2*i-1]);
	}else{
		int rev=(u<=n?u+n:u-n);
		dfs(rev);
		for(int i=1;i<=n;i++)swap(p[i],p[i+n]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)cin>>p[i];
	queue<int>que;
	memset(dis,-1,sizeof(dis));
	for(int i=1;i<=2*n;i++)if(p[i]==1)que.push(i),dis[i]=0;
	while(!que.empty()){
		int u=que.front();que.pop();
		int sw=(u&1)?u+1:u-1;
		if(dis[sw]<0)dis[sw]=dis[u]+1,que.push(sw),fr[sw]=0;
		int rev=(u<=n?u+n:u-n);
		if(dis[rev]<0)dis[rev]=dis[u]+1,que.push(rev),fr[rev]=1;
	}
	if(dis[1]<0){
		puts("-1");
		return 0;
	}
	dfs(1);
	for(int i=1;i<=2*n;i++)if(p[i]!=i){
		puts("-1");
		return 0;
	}
	cout<<dis[1];
}