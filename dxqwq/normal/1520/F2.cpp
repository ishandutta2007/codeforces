// Problem: F1. Guess the K-th Zero (Easy version)
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/F1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1000003],tag[4000003],ans[4000003];
void build(int l,int r,int id)
{
	if(l==r) return (void)(ans[id]=a[l]);
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1);
	ans[id]=ans[id<<1]+ans[(id<<1)+1];
	return ;
}
void push_down(int x,int l1,int l2)
{
	tag[x<<1]+=tag[x],tag[(x<<1)+1]+=tag[x];
	ans[x<<1]+=tag[x]*l1,ans[(x<<1)+1]+=tag[x]*l2;
	tag[x]=0;
	return ;
}
void update(int l,int r,int& L,int& R,int id,int val)
{
	if(L<=l && r<=R) 
	{
		tag[id]+=val;
		ans[id]+=(r-l+1)*val;
		return ;
	}
	int mid=(l+r)>>1;
	push_down(id,mid-l+1,r-mid);
	if(L<=mid) update(l,mid,L,R,id<<1,val);
	if(R>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
	ans[id]=ans[(id<<1)]+ans[(id<<1)+1];
	return ;
}
long long query(int l,int r,int& L,int& R,int id)
{
	if(L<=l && r<=R) return ans[id];
	int mid=(l+r)>>1;
	push_down(id,mid-l+1,r-mid);
	long long res=0;
	if(L<=mid) res+=query(l,mid,L,R,id<<1);
	if(R>=mid+1) res+=query(mid+1,r,L,R,(id<<1)+1);
	return res;
}
bool f[200003];
int n,t;
int sum(int r)
{
	if(f[r]) return query(1,n,r,r,1);
	int l=1;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x=read(),A=r-l+1-x;
	int B=query(1,n,r,r,1);
	update(1,n,r,r,1,A-B);
	f[r]=1;
	return r-l+1-x;
}
void solve(int k)
{
	int l=1,r=n;
	int ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(sum(mid)>=k) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("! %d\n",ans);
	fflush(stdout);
	update(1,n,ans,n,1,-1);
	return ;
}
signed main()
{
	n=read(),t=read();
	build(1,n,1);
	for(;t--;)solve(read());
	return 0;
}