#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9')x=x*10+(ch&15),ch=getchar();
    return x*f;
}
int n,m;
int a[500003],lsh[500003];
struct query
{
	int l,r,id;
	bool operator<(const query&a) const { return r<a.r; }
}q[500003];
int lst[500003],mn[2000003],Ans[500003];
void update(int l,int r,int x,int val,int id)
{
	if(l==r)
	{
		mn[id]=val;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(l,mid,x,val,(id<<1));
	else update(mid+1,r,x,val,(id<<1)+1);
	mn[id]=min(mn[id<<1],mn[(id<<1)+1]);
	return ;
}
int query(int l,int r,int L,int R,int id)
{
	if(r<L || R<l) return 0x3f3f3f3f;
	if(L<=l && r<=R) return mn[id];
	int mid=(l+r)>>1;
	return min(query(l,mid,L,R,id<<1),query(mid+1,r,L,R,(id<<1)+1));
}
signed main()
{
	memset(mn,0x3f,sizeof(mn));
	n=read(),m=read();
	for(int i=1; i<=n; i++) lsh[i]=a[i]=read();
	sort(lsh+1,lsh+n+1);
	int len=unique(lsh+1,lsh+n+1)-lsh-1;
	for(int i=1; i<=n; i++) a[i]=lower_bound(lsh+1,lsh+len+1,a[i])-lsh;
	for(int i=1; i<=m; i++) q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1,r=0; i<=m; i++)
	{
		if(q[i].l==q[i].r) { Ans[q[i].id]=-1; continue; }
		while(r<q[i].r) 
		{
			if(lst[a[++r]]) update(1,n,lst[a[r]],r-lst[a[r]],1);
			lst[a[r]]=r;
		}
		Ans[q[i].id]=query(1,n,q[i].l,q[i].r-1,1);
	}
	for(int i=1; i<=m; i++) if(Ans[i]==0x3f3f3f3f) puts("-1"); else printf("%d\n",Ans[i]);
	return 0;
}