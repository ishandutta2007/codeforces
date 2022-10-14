// Problem: E2. Array and Segments (Hard version)
// Contest: Codeforces - Codeforces Round #535 (Div. 3)
// URL: https://codeforces.com/contest/1108/problem/E2
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
int a[100003],mn[400003],tag[400003];
void build(int l,int r,int id)
{
	if(l==r) return (void)(mn[id]=a[l]);
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1);
	mn[id]=min(mn[id<<1],mn[(id<<1)+1]);
	return ;
}
void push_down(int x,int l1,int l2)
{
	tag[x<<1]+=tag[x],tag[(x<<1)+1]+=tag[x];
	mn[x<<1]+=tag[x],mn[(x<<1)+1]+=tag[x];
	tag[x]=0;
	return ;
}
void update(int l,int r,int& L,int& R,int id,int val)
{
	if(L<=l && r<=R) 
	{
		tag[id]+=val;
		mn[id]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	push_down(id,mid-l+1,r-mid);
	if(L<=mid) update(l,mid,L,R,id<<1,val);
	if(R>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
	mn[id]=min(mn[id<<1],mn[(id<<1)+1]);
	return ;
}
int query(int l,int r,int L,int R,int id)
{
	if(L<=l && r<=R) return mn[id];
	int mid=(l+r)>>1;
	push_down(id,mid-l+1,r-mid);
	int res=1000000000;
	if(L<=mid) res=min(res,query(l,mid,L,R,id<<1));
	if(R>=mid+1) res=min(res,query(mid+1,r,L,R,(id<<1)+1));
	return res;
}
int l[1003],r[1003];
int cnt,C[1003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	build(1,n,1);
	for(int i=1; i<=m; i++) l[i]=read(),r[i]=read();
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++) if(l[j]>i||r[j]<i) 
		update(1,n,l[j],r[j],1,-1);
		if(i!=1){int L=query(1,n,1,i-1,1);
		if(a[i]-L>ans)
		{cnt=0;
			for(int j=1; j<=m; j++) if(l[j]>i||r[j]<i) C[++cnt]=j;
		}
		ans=max(ans,a[i]-L);}
		if(i!=n){int R=query(1,n,i+1,n,1);
		if(a[i]-R>ans)
		{cnt=0;
			for(int j=1; j<=m; j++) if(l[j]>i||r[j]<i) C[++cnt]=j;
		}
		ans=max(ans,a[i]-R);}
		for(int j=1; j<=m; j++) if(l[j]>i||r[j]<i) 
		update(1,n,l[j],r[j],1,1);
	}
	printf("%d\n",ans);
	printf("%d\n",cnt);
	for(int i=1; i<=cnt; i++) printf("%d ",C[i]);
	puts("");
    return 0;
}