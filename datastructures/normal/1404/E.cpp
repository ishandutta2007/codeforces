#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 1000000000
using namespace std;
struct Dinic{
	int n,m,s,t,u[200005],v[200005],w[200005],first[200005],nxt[200005];
	void init(int _n,int _s,int _t){
		n=_n,m=1,s=_s,t=_t;
		memset(first,0,sizeof(first));
		memset(nxt,0,sizeof(nxt));
		return;
	}
	void add(int a,int b,int c){
		int i=++m;
		u[i]=a,v[i]=b,w[i]=c;
		nxt[i]=first[u[i]],first[u[i]]=i;
		i=++m;
		u[i]=b,v[i]=a,w[i]=0;
		nxt[i]=first[u[i]],first[u[i]]=i;
		return;
	}
	int cur[100005],depth[100005],head,tail,q[100005];
	bool bfs(){
		for (int i=1;i<=n;i++)cur[i]=first[i];
		memset(depth,-1,sizeof(depth));
		depth[s]=1;
		head=tail=1;
		q[1]=s;
		while(head<=tail){
			int now=q[head];
			head++;
			for (int i=first[now];i;i=nxt[i])
				if (depth[v[i]]==- 1&&w[i]>0){
					depth[v[i]]=depth[now]+1;
					if (v[i]==t)return 1;
					q[++tail]=v[i];
				}
		}
		return 0;
	} 
	int dfs(int now,int in){
		if (now==t)return in;
		int out=0;
		for (int i=cur[now];i!=0&&in>0;i=nxt[i]){
			cur[now]=i;
			if (depth[v[i]]!=depth[now]+1||w[i]==0)continue;
			int qwq=dfs(v[i],min(in,w[i]));
			w[i]-=qwq,w[i^1]+=qwq;
			in-=qwq,out+=qwq;
		}
		return out;
	}
	int work(){
		int ans=0;
		while(bfs())ans+=dfs(s,inf);
		return ans;
	}
}flow;
int n,m;
char d[205][205];
int id(int x,int y){
	return (x-1)*m+y;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%s",d[i]+1);
	int s=n*m+1,t=n*m+2;
	flow.init(t,s,t);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (d[i][j]=='.')continue;
			if (i==1||d[i-1][j]!='#')flow.add(id(i,j),t,1);
			else flow.add(id(i,j),id(i-1,j),1);
			if (j==1||d[i][j-1]!='#')flow.add(s,id(i,j),1);
			else flow.add(id(i,j-1),id(i,j),1);
		}
	cout<<flow.work()<<endl; 
	return 0;
}