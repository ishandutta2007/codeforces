#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 1000000000
using namespace std;
struct Dinic{
	int n,m,s,t,u[600005],v[600005],w[600005],first[3005],nxt[600005];
	int ans;
	void init(int qwqn,int qwqs,int qwqt){
		n=qwqn,m=1,s=qwqs,t=qwqt;
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		memset(w,0,sizeof(w));
		memset(first,0,sizeof(first));
		memset(nxt,0,sizeof(nxt));
		ans=0;
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
	int dfs(int now,int in){
		if (now==t)return in;
		int out=0;
		for (int i=cur[now];i;i=nxt[i]){
			cur[now]=i;
			if (w[i]==0||depth[v[i]]!=depth[now]+1)continue;
			int qwq=dfs(v[i],min(in,w[i]));
			out+=qwq,in-=qwq;
			w[i]-=qwq,w[i^1]+=qwq;
		}
		return out;
	}
	bool bfs(){
		memset(depth,-1,sizeof(depth));
		for (int i=1;i<=n;i++)cur[i]=first[i];
		head=tail=1;
		q[1]=s;
		depth[s]=0;
		while(head<=tail){
			int now=q[head];
			head++;
			for (int i=first[now];i;i=nxt[i])
				if (w[i]>0&&depth[v[i]]==-1)depth[v[i]]=depth[now]+1,q[++tail]=v[i];
		}
		if (depth[t]==-1)return 0;
		return 1;
	}
	void upd(){
		while(bfs())ans+=dfs(s,inf);
		return;
	}
}flow;
int n,a[3005],b[3005];
int book[105],ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)cin>>b[i];
	int s=n+1,t=n+2;
	flow.init(n+2,s,t);
	for (int i=1;i<=n;i++){
		memset(book,0,sizeof(book));
		for (int j=i-1;j>=1;j--){
			if (a[i]%a[j]!=0)continue;
			if (book[a[j]]==1)continue;
			flow.add(i,j,inf);
			book[a[j]]=1;
		}
	}
	for (int i=1;i<=n;i++)
		if (b[i]>0)ans+=b[i],flow.add(s,i,b[i]);
		else flow.add(i,t,-b[i]);
	flow.upd();
	cout<<ans-flow.ans<<endl;
	return 0;
}