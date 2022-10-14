// Problem: CF803G Periodic RMQ Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF803G
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
} 
int a[100003],f[1000003];
int st[100003][19],l2[100003],n;
int tag[4000003],ans[4000003];
inline void init(int l)
{
	st[l][0]=a[l];
	for(int i=1; i<19; i++) 
	st[l][i]=min(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
}
inline int query_(int l,int r)
{
	int L=l2[r-l+1];
	return min(st[l][L],st[min(r-(1<<L)+1,n)][L]);
}
void build(int l,int r,int id)
{
	tag[id]=0;
	if(l==r) return (void)(ans[id]=f[l]);
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1);
	ans[id]=min(ans[id<<1],ans[(id<<1)+1]);
	return ;
}
void update(int l,int r,int L,int R,int id,int val)
{
	if(L<=l && r<=R) 
	{
		tag[id]=ans[id]=val;
		return ;
	}
	int mid=(l+r)>>1;
	if(tag[id]) 
	tag[id<<1]=tag[(id<<1)+1]=ans[id<<1]=ans[(id<<1)+1]=tag[id],tag[id]=0;
	if(L<=mid) update(l,mid,L,R,id<<1,val);
	if(R>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
	ans[id]=min(ans[(id<<1)],ans[(id<<1)+1]);
	return ;
}
int query(int l,int r,int L,int R,int id)
{
	if(L<=l && r<=R) return ans[id];
	int mid=(l+r)>>1;
	if(tag[id]) 
	tag[id<<1]=tag[(id<<1)+1]=ans[id<<1]=ans[(id<<1)+1]=tag[id],tag[id]=0;
	int res=0x3f3f3f3f;
	if(L<=mid) res=min(res,query(l,mid,L,R,id<<1));
	if(R>=mid+1) res=min(res,query(mid+1,r,L,R,(id<<1)+1));
	return res;
}
int O[100003],L[100003],R[100003],V[100003];
int lsh[500003];
signed main()
{
	n=read(),read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=n; i>=1; --i) init(i);
	for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
	int m=read(),c=0;
	for(int i=1; i<=m; ++i) 
	{
		O[i]=read(),lsh[++c]=L[i]=read(),lsh[++c]=R[i]=read()+1;
		if(O[i]==1) V[i]=read();
	}
	sort(lsh+1,lsh+c+1);
	c=unique(lsh+1,lsh+c+1)-lsh-1;
	for(int i=1; i<c; ++i) if(lsh[i+1]-lsh[i]>=n) f[i]=query_(1,n);
	else if((lsh[i+1]-2)/n==(lsh[i]-1)/n) f[i]=query_((lsh[i]-1)%n+1,(lsh[i+1]-2)%n+1);
	else f[i]=min(query_((lsh[i]-1)%n+1,n),query_(1,(lsh[i+1]-2)%n+1));
	build(1,c-1,1);
	// for(int i=1; i<c; ++i) printf("%d ",f[i]);puts("");
	for(int i=1; i<=m; ++i) 
	{
		L[i]=lower_bound(lsh+1,lsh+c+1,L[i])-lsh,
		R[i]=lower_bound(lsh+1,lsh+c+1,R[i])-lsh-1;
		if(O[i]==1) update(1,c-1,L[i],R[i],1,V[i]);
		else printf("%d\n",query(1,c-1,L[i],R[i],1));
	}
	return 0;
}