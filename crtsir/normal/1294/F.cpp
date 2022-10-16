#include<bits/stdc++.h>
using namespace std;
int n,fa[200003];bool vis[200003];
vector<int>v[200003];
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;scanf("%d%d",&a,&b);
		a--;b--;v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int>Q;Q.push(0);int onep,twop;
	while(Q.size()){
		int x=Q.front();onep=x;Q.pop();vis[x]=1;
		for(int i=0;i<v[x].size();i++)
			if(!vis[v[x][i]])
				Q.push(v[x][i]);
	}
	memset(vis,0,sizeof(vis));;
	Q.push(onep);
	while(Q.size()){
		int x=Q.front();twop=x;Q.pop();
		vis[x]=1;
		for(int i=0;i<v[x].size();i++)
			if(!vis[v[x][i]])
				Q.push(v[x][i]),
				fa[v[x][i]]=x;
	}
	memset(vis,0,sizeof(vis));
	queue<pair<int,int> >q;
	int now=twop,ans=0,ret=0;while(now!=onep)q.push(make_pair(now,0)),vis[now]=1,now=fa[now],ans++;
	q.push(make_pair(onep,0));
	vis[onep]=1;
	while(q.size()){
		int x=q.front().first,len=q.front().second;q.pop();
		ret=len;if(x!=onep)now=x;
		for(int i=0;i<v[x].size();i++)
			if(!vis[v[x][i]])
				q.push(make_pair(v[x][i],len+1)),
				vis[v[x][i]]=1;
	}
	cout<<ret+ans<<endl<<onep+1<<' '<<twop+1<<' '<<now+1<<endl;
}