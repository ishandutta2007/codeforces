#include<bits/stdc++.h>
using namespace std;
struct node
{
	int to=0,nxt=0;
}a[1000003],b[1000003];
int HEad[1000003],hEAd[1000003],cnt=0,cnT=0,dis[1000003];
int vis[1000003];
inline int read()
{
	int x=0; char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') x*=10,x+=(int)ch-48,ch=getchar();
	return x;
}
inline void add(int u,int v)
{
	a[++cnt].to=v,a[cnt].nxt=HEad[u],HEad[u]=cnt;
	int uu=v,vv=u;
	b[++cnT].to=vv,b[cnT].nxt=hEAd[uu],hEAd[uu]=cnT;
}
int p[1000003],qwq[1000003];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
int main()
{
	int n=read(),m=read(),u,v;
	for(int i=1; i<=n; ++i) dis[i]=999999999;
	for(int i=1; i<=m; ++i) u=read(),v=read(),add(v,u);
	int q=read();
	for(int i=1; i<=q; i++) p[i]=read();
	int sdt=p[q];
	dis[sdt]=0,Q.push(make_pair(0,sdt));
	while(!Q.empty())
	{	
		int x=Q.top().first,y=Q.top().second;
		Q.pop();
		if(vis[y]) continue; else vis[y]=1;
		for(int i=HEad[y]; i; i=a[i].nxt) if(dis[a[i].to]>x+1) 
		{
			dis[a[i].to]=x+1;
			if(!vis[a[i].to]) Q.push(make_pair(dis[a[i].to],a[i].to));
		}
	}
	//for(int i=1; i<=n; i++) cout<<dis[i]<<' '; cout<<'\n';
	for(int i=1; i<=n; i++) for(int j=hEAd[i]; j; j=b[j].nxt) 
	{
		if(dis[b[j].to]==dis[i]-1) qwq[i]++;
	}
	//for(int i=1; i<=n; i++) cout<<qwq[i]<<' '; cout<<'\n';
	int Min=0,Max=0;
	for(int i=1; i<q; i++) if(dis[p[i]]!=dis[p[i+1]]+1) ++Min,++Max; else if(qwq[p[i]]>1) ++Max; 
	cout<<Min<<' '<<Max;
	return 0;
}