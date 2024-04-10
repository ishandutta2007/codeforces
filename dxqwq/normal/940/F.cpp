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
int a[200003],cnt[200003],cntcnt[200003],Ans[200003];
struct query
{
	int l,r,id,pl,pr,t;
	bool operator<(const query&a) const { return (pl<a.pl)||(pl==a.pl&&((pr<a.pr)||(pr==a.pr&&t<a.t))); }
}q[200003];
int p[200003],val[200003],tcnt=1;
unordered_map<int,int> mp;
int zkakioi=0;
signed main()
{
	n=read(),m=read(),bl=pow(n,0.6666);
	for(int i=1,x; i<=n; i++) 
	{
		x=read();
		if(mp[x]) a[i]=mp[x]; else a[i]=mp[x]=++zkakioi;
	}
	for(int i=1,x,y; i<=m; i++) 
	{
		int opt=read();
		if(opt==1) 
		q[++qcnt].l=read(),q[qcnt].r=read(),q[qcnt].pl=q[qcnt].l/bl,q[qcnt].pr=q[qcnt].r/bl,q[qcnt].t=tcnt,q[qcnt].id=qcnt;
		else 
		{
			++tcnt,x=read(),y=read(),p[tcnt]=x;
			if(mp[y]) y=mp[y]; else y=mp[y]=++zkakioi;
			val[tcnt]=y-a[x],a[x]=y;
		}
	}
	sort(q+1,q+qcnt+1);
	for(int i=1,l=1,r=0,t=tcnt; i<=qcnt; i++)
	{
		while(t<q[i].t) 
		{
			++t;
			if(l<=p[t] && p[t]<=r) 
			{
				--cntcnt[cnt[a[p[t]]]],
				++cntcnt[--cnt[a[p[t]]]],
				a[p[t]]+=val[t],
				--cntcnt[cnt[a[p[t]]]],
				++cntcnt[++cnt[a[p[t]]]];
			}
			else a[p[t]]+=val[t];
		}
		while(t>q[i].t)
		{
			if(l<=p[t] && p[t]<=r) 
			{
				--cntcnt[cnt[a[p[t]]]],
				++cntcnt[--cnt[a[p[t]]]],
				a[p[t]]-=val[t],
				--cntcnt[cnt[a[p[t]]]],
				++cntcnt[++cnt[a[p[t]]]];
			}
			else a[p[t]]-=val[t];
			--t;
		}
		while(l>q[i].l) --cntcnt[cnt[a[--l]]],++cntcnt[++cnt[a[l]]];
		while(r<q[i].r) --cntcnt[cnt[a[++r]]],++cntcnt[++cnt[a[r]]];
		while(r>q[i].r) --cntcnt[cnt[a[r]]],++cntcnt[--cnt[a[r--]]];
		while(l<q[i].l) --cntcnt[cnt[a[l]]],++cntcnt[--cnt[a[l++]]];
		for(Ans[q[i].id]=1; cntcnt[Ans[q[i].id]]; ++Ans[q[i].id]);
	} 
	for(int i=1; i<=qcnt; i++) printf("%d\n",Ans[i]);
	return 0;
}