#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 2000000000
using namespace std;
int n,m,a,b,u[1005],v[1005],w[1005],first[1005],nxt[1005];
int dsu[205],sz[205],l,s[205];
int book[71][131072],head,tail,q[40000005][2],dis[71][131072];
int ans[205];
int dsu_find(int x){
	if (x==dsu[x])return dsu[x];
	return dsu[x]=dsu_find(dsu[x]);
}
void SPFA(){
	memset(dis,0x3f,sizeof(dis));
	dis[1][s[1]]=0;
	head=tail=1;
	q[1][0]=1,q[1][1]=s[1];
	book[1][s[1]]=1;
	while(head<=tail){
		int now=q[head][0],nows=q[head][1];
		head++;
		book[now][nows]=0;
		for (int i=first[now];i;i=nxt[i]){
			if (((nows&s[v[i]])||dsu[now]==dsu[v[i]])&&w[i]==b)continue;
			if (dis[now][nows]+w[i]<dis[v[i]][nows|s[v[i]]]){
				dis[v[i]][nows|s[v[i]]]=dis[now][nows]+w[i];
				if (book[v[i]][nows|s[v[i]]]==0){
					++tail;
					q[tail][0]=v[i],q[tail][1]=(nows|s[v[i]]);
					book[v[i]][nows|s[v[i]]]=1;
				}
			}
		}
	}
	return;
}
int main(){
	cin>>n>>m>>a>>b;
	for (int i=1;i<=n;i++)dsu[i]=i,sz[i]=1;
	for (int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		nxt[i]=first[u[i]],first[u[i]]=i;
		if (w[i]==a){
			int x=dsu_find(u[i]),y=dsu_find(v[i]);
			sz[y]+=sz[x],dsu[x]=y;
		}
		u[i+m]=v[i],v[i+m]=u[i],w[i+m]=w[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	for (int i=1;i<=n;i++){
		if (i!=dsu_find(i))continue;
		if (sz[i]>=4)s[i]=(1<<(l++));
	}
	for (int i=1;i<=n;i++)
		if (i!=dsu_find(i))s[i]=s[dsu_find(i)];
	SPFA();
	for (int i=1;i<=n;i++){
		ans[i]=inf;
		for (int j=0;j<(1<<l);j++)ans[i]=min(ans[i],dis[i][j]);
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}