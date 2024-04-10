// Problem: E. Sockets
// Contest: Codeforces - Codeforces Round #377 (Div. 2)
// URL: https://codeforces.com/contest/732/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
struct node
{
	int cur,id,t;
	bool operator<(const node&g)const{
		if(cur!=g.cur) return cur<g.cur;
		if(t!=g.t)return t>g.t;
		return id<g.id;
	}
};
node make_node(int x,int y,int z)
{
	node S;
	S.cur=x,S.id=y,S.t=z;
	return S;
}
#define pii node
#define mp make_node
priority_queue<pii> q1;
priority_queue<pii> q2;
int a[1000003],b[1000003];
int c[1000003],d[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) a[i]=read(),q1.push(mp(a[i],i,0));
	for(int j=1; j<=m; ++j) b[j]=read(),q2.push(mp(b[j],j,0));
	int ans=0,A=0;
	while(!q1.empty()&&!q2.empty())
	{
		pii Y=q2.top();
		int X=Y.cur;
		q2.pop();
		while(X<(q1.top()).cur) q1.pop();
		if(X==q1.top().cur)
		{
			d[q1.top().id]=Y.id;
			c[Y.id]=Y.t;
			A+=Y.t;
			q1.pop();
			++ans;
			continue;
		}
		if(X==1) break;
		X=(X-1)/2+1;
		Y.cur=X,Y.t++;
		q2.push(Y);
	}
	printf("%d %d\n",ans,A);
	for(int i=1; i<=m; i++) printf("%d ",c[i]);puts("");
	for(int i=1; i<=n; i++) printf("%d ",d[i]);puts("");
    return 0;
}