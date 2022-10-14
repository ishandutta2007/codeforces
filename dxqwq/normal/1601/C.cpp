// Problem: C. Optimal Insertion
// Contest: Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],b[1000003],lsh[2000003];
int tree[2000003];
int n,m,c;
int f[2000003],tag[8000003],ans[8000003];
long long Ans=0;
void build(int l,int r,int id)
{
	tag[id]=0;
	if(l==r) return (void)(ans[id]=f[l]);
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1);
	ans[id]=min(ans[id<<1],ans[(id<<1)+1]);
	return ;
}
void push_down(int x)
{
	tag[x<<1]+=tag[x],tag[(x<<1)+1]+=tag[x];
	ans[x<<1]+=tag[x],ans[(x<<1)+1]+=tag[x];
	tag[x]=0;
	return ;
}
void update(int l,int r,int L,int R,int id,int val)
{
	if(L<=l && r<=R) 
	{
		tag[id]+=val,ans[id]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	push_down(id);
	if(L<=mid) update(l,mid,L,R,id<<1,val);
	if(R>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
	ans[id]=min(ans[(id<<1)],ans[(id<<1)+1]);
	return ;
}
int query(int l,int r,int L,int R,int id)
{
	if(L<=l && r<=R) return ans[id];
	int mid=(l+r)>>1;
	push_down(id);
	int res=0x3f3f3f3f;
	if(L<=mid) res=min(res,query(l,mid,L,R,id<<1));
	if(R>=mid+1) res=min(res,query(mid+1,r,L,R,(id<<1)+1));
	return res;
}
void add(int x)
{
	while(x<=c) ++tree[x],x+=x&(-x);
	return ; 
}
void del(int x)
{
	while(x<=c) --tree[x],x+=x&(-x);
	return ; 
}
int find(int x)
{
	int res=0;
	while(x) res+=tree[x],x-=x&(-x);
	return res;
}
pair<int,int> A[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		n=read(),m=read(),c=0,Ans=0;
		for(int i=1; i<=n; ++i)	
			A[i].first=lsh[++c]=a[i]=read(),
			A[i].second=i;
		for(int i=1; i<=m; ++i) lsh[++c]=b[i]=read();
		sort(b+1,b+m+1);
		sort(lsh+1,lsh+c+1);
		int len=unique(lsh+1,lsh+c+1)-lsh-1;
		for(int i=1; i<=n; ++i) A[i].first=a[i]=lower_bound(lsh+1,lsh+len+1,a[i])-lsh;
		for(int i=1; i<=m; ++i) b[i]=lower_bound(lsh+1,lsh+len+1,b[i])-lsh;
		sort(A+1,A+n+1);
		for(int i=1; i<=n; ++i)
			Ans+=(i-1)-find(a[i]),add(a[i]);
		for(int i=1; i<=n; ++i) del(a[i]);
		int N=n+1;
		for(int i=2; i<=N; ++i) f[i]=i-1;
		build(1,N,1);
		int pos1=1,pos2=1;
		for(int i=1; i<=m; ++i)
		{
			while(b[i]>=A[pos1].first&&pos1<=n)
				update(1,N,A[pos1].second+1,N,1,-1),++pos1;
			while(b[i]>A[pos2].first&&pos2<=n)
				update(1,N,1,A[pos2].second,1,1),++pos2;
			Ans+=ans[1];
		}
		printf("%lld\n",Ans);
	}
	return 0;
}