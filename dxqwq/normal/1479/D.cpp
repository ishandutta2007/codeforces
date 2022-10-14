#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
int n,m,qcnt,bl,Q;
int a[600003],cnt[300003];
int Ans[600003];
struct query
{
	int vl,vr,l,r,id,pl,qwq;
	bool operator<(const query&a) const { return (pl<a.pl)||(pl==a.pl&&r<a.r); }
}q[600003];
int nxt[600003],head[300003],to[600003],ecnt;
int IN[300003],OUT[300003],CNT;
int A[600003],d[300003],fa[300003][20];
bool flag[300003];
stack<int> s[603];
inline void ins(int x)
{
	if(flag[x]) --cnt[a[x]];
	else ++cnt[a[x]];
	if(cnt[a[x]]&1) s[a[x]>>10].push(a[x]);
	flag[x]^=1;
} 
inline void dfs(int x,int y)
{
	fa[x][0]=y,d[x]=d[y]+1;
	for(int i=1; i<=19; i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	IN[x]=++CNT,A[CNT]=x;
	for(int i=head[x]; i; i=nxt[i]) if(to[i]!=y) dfs(to[i],x);
	OUT[x]=++CNT,A[CNT]=x;
}
inline int LCA(int x,int y)
{
	if(d[x]>d[y]) swap(x,y);
	for(int i=19; i>=0; i--) if(d[x]<=d[fa[y][i]]) y=fa[y][i];
	if(x==y) return x;
	for(int i=19; i>=0; i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
signed main()
{
	n=read(),Q=read(),bl=sqrt(n)*2+1;
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1,u,v; i<n; i++) u=read(),v=read(),
	to[++ecnt]=v,nxt[ecnt]=head[u],head[u]=ecnt,
	to[++ecnt]=u,nxt[ecnt]=head[v],head[v]=ecnt;
	dfs(1,1);
	for(int i=1,x,y,l,r; i<=Q; i++) 
	{
		x=read(),y=read(),l=read(),r=read();
		if(IN[x]>IN[y]) swap(x,y);
		if(LCA(x,y)==x) q[++qcnt].l=IN[x],q[qcnt].r=IN[y];
		else q[++qcnt].l=OUT[x],q[qcnt].r=IN[y],q[qcnt].qwq=LCA(x,y);
		q[qcnt].pl=q[qcnt].l/bl,q[qcnt].id=qcnt,q[qcnt].vl=l,q[qcnt].vr=r;
	}
	sort(q+1,q+qcnt+1),memset(Ans,-1,sizeof(Ans));
	for(int i=1,l=1,r=0; i<=qcnt; i++)
	{
		while(l<q[i].l) ins(A[l++]);
		while(l>q[i].l) ins(A[--l]);
		while(r<q[i].r) ins(A[++r]);
		while(r>q[i].r) ins(A[r--]);
		if(q[i].qwq) ins(q[i].qwq);
		int L=q[i].vl,R=q[i].vr,pl=L>>10,pr=R>>10;
		if(pl==pr)
		{
			for(int j=L; j<=R; ++j) if(cnt[j]&1)
			{
				Ans[q[i].id]=j;
				break;
			 } 
		}
		else
		{
			for(int j=L,t=(pl+1)<<10; j<t; ++j) if(cnt[j]&1)
			{
				Ans[q[i].id]=j;
				break;
			} 
			if(Ans[q[i].id]==-1) for(int j=pr<<10; j<=R; ++j) if(cnt[j]&1)
			{
				Ans[q[i].id]=j;
				break;
			} 
			if(Ans[q[i].id]==-1) for(int j=pl+1; j<pr; ++j)
			{
				while(!s[j].empty())
				{
					if(cnt[s[j].top()]&1) 
					{
						Ans[q[i].id]=s[j].top();
						break;
					}
					else s[j].pop();
				}	
				if(Ans[q[i].id]!=-1) break;
			}
		}
		if(q[i].qwq) ins(q[i].qwq);
	} 
	for(int i=1; i<=qcnt; i++) printf("%d\n",Ans[i]);
	return 0;
}