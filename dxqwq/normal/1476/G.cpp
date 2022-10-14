// Problem: G. Minimum Difference
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1476/problem/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
int n,m,qcnt,bl;
int a[100003],cnt[1000003],ccnt[1000003],Ans[100003];
struct query
{
	int l,r,k,id,pl,pr,t;
	bool operator<(const query&a) const { return (pl<a.pl)||(pl==a.pl&&((pr<a.pr)||(pr==a.pr&&t<a.t))); }
}q[100003];
int p[100003],val[100003],tcnt=1;
int nxt[100003],lst[1000003],tmp[1003],sz=0,H=0,T=100001,tot=0;
inline void D(int x)
{                
	if(x<=0) return ;
	if(!--ccnt[x]) 
	{
		if(x==H) H=nxt[x];
		if(x==T) T=lst[x];
		lst[nxt[x]]=lst[x],nxt[lst[x]]=nxt[x];
	}
	return ;
}
inline void A(int x)
{
	if(x<=0) return;
	if(!ccnt[x]++) nxt[lst[T]]=x,lst[x]=lst[T],nxt[x]=T,lst[T]=x;
}
inline void add(int x){D(cnt[x]),A(++cnt[x]);return;}
inline void del(int x){D(cnt[x]),A(--cnt[x]);return;}
signed main()
{
	nxt[0]=100001,nxt[100001]=100001;
	n=read(),m=read(),bl=pow(n,0.6666)+1;
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1,x,y; i<=m; i++) 
	{
		int op=read();
		if(op==1) 
		q[++qcnt].l=read(),q[qcnt].r=read(),q[qcnt].k=read(),q[qcnt].pl=q[qcnt].l/bl,q[qcnt].pr=q[qcnt].r/bl,q[qcnt].t=tcnt,q[qcnt].id=qcnt;
		else ++tcnt,x=read(),y=read(),p[tcnt]=x,val[tcnt]=y-a[x],a[x]=y;
	}
	sort(q+1,q+qcnt+1);
	for(int i=1,l=1,r=0,t=tcnt; i<=qcnt; i++)
	{
		while(t<q[i].t) 
		{
			++t;
			if(l<=p[t] && p[t]<=r) 
			{
				del(a[p[t]]);
				a[p[t]]+=val[t];
				add(a[p[t]]);
			}
			else a[p[t]]+=val[t];
		}
		while(t>q[i].t)
		{
			if(l<=p[t] && p[t]<=r) 
			{
				del(a[p[t]]);
				a[p[t]]-=val[t];
				add(a[p[t]]);
			}
			else a[p[t]]-=val[t];
			--t;
		}
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		Ans[q[i].id]=998244353;
		sz=0;
		for(int i=H; i!=T; i=nxt[i]) if(i) tmp[++sz]=i;
		//for(int i=1; i<=100000; ++i) if(ccnt[i]) tmp[++sz]=i;
		sort(tmp+1,tmp+sz+1);
		for(int l=1,r=1,g=0; r<=sz; ++r)
		{
			g+=ccnt[tmp[r]];
			if(g<q[i].k) continue;
			while(g-ccnt[tmp[l]]>=q[i].k) g-=ccnt[tmp[l]],++l;
			Ans[q[i].id]=min(Ans[q[i].id],tmp[r]-tmp[l]);
		}
		if(Ans[q[i].id]==998244353) Ans[q[i].id]=-1;
	} 
	for(int i=1; i<=qcnt; i++) printf("%d\n",Ans[i]);
	return 0;
}