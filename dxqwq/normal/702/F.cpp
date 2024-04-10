#include<bits/stdc++.h>
#define ll long long
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void print(ll x) {
    if(x>9) print(x/10);
    *O++=x%10+'0';
}
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int lg16[65536];
inline int lg(int x){return x>=65536?(lg16[x>>16]+4):lg16[x];}
struct node
{
	int mx=0,mn=1000000000,cnt=0,tag=0;
	ll sum=0;
	node(){}
	node(int A,int B,int C,ll D){mx=A,mn=B,cnt=C,sum=D;}
	node operator+(const node&t)const{return node((mx<t.mx?t.mx:mx),(mn>t.mn?t.mn:mn),cnt+t.cnt,sum+t.sum);}
}seg[8][252144];
int tag[8][252144];
int a[500003],L[500003];
int n;
inline int Max(int&x,int&y){return (x<y)?y:x;}
inline int Min(int&x,int&y){return (x>y)?y:x;}
const int C=32;
int ans[500003];
void rebuild(int b,int nl,int nr,int x,int i)
{
	if(nr-nl<C)
	{
		ll s=0;
		int mn=1000000000,mx=0,c=0;
		if(tag[b][i]) 
		for(int j=nl; j<=nr; ++j) if(L[j]==b&&j!=x) ans[j]+=seg[b][i].tag,a[j]+=tag[b][i];
		seg[b][i].tag=0,tag[b][i]=0;
		for(int j=nl; j<=nr; ++j) if(L[j]==b) 
			s+=a[j],(mn>a[j])&&(mn=a[j]),(mx<a[j])&&(mx=a[j]),++c;
		seg[b][i]=(node){mx,mn,c,s};
		return ;
	}
	if(tag[b][i])
	seg[b][i<<1].sum+=1ll*tag[b][i]*seg[b][i<<1].cnt,
	seg[b][(i<<1)+1].sum+=1ll*tag[b][i]*seg[b][(i<<1)+1].cnt,
	seg[b][i<<1].mx+=tag[b][i],seg[b][(i<<1)+1].mx+=tag[b][i],
	seg[b][i<<1].mn+=tag[b][i],seg[b][(i<<1)+1].mn+=tag[b][i],
	tag[b][i<<1]+=tag[b][i],tag[b][(i<<1)+1]+=tag[b][i],
	tag[b][i]=0;
	seg[b][i<<1].tag+=seg[b][i].tag,seg[b][(i<<1)+1].tag+=seg[b][i].tag,
	seg[b][i].tag=0;
	int mid=(nl+nr)>>1;
	if(x<=mid) rebuild(b,nl,mid,x,i<<1);
	else rebuild(b,mid+1,nr,x,(i<<1)+1);
	seg[b][i].sum=seg[b][i<<1].sum+seg[b][(i<<1)+1].sum,
	seg[b][i].mn=Min(seg[b][i<<1].mn,seg[b][(i<<1)+1].mn),
	seg[b][i].mx=Max(seg[b][i<<1].mx,seg[b][(i<<1)+1].mx),
	seg[b][i].cnt=seg[b][i<<1].cnt+seg[b][(i<<1)+1].cnt;
	return ;
}
void update(int b,int l,int r,int nl,int nr,int k,int i)
{
	if(nr<l||r<nl||seg[b][i].mx<=k) return ;
	if(l<=nl&&nr<=r&&seg[b][i].mn-k>=1<<(b<<2))
	{
		++seg[b][i].tag,
		tag[b][i]-=k,seg[b][i].sum-=1ll*k*seg[b][i].cnt,
		seg[b][i].mn-=k,seg[b][i].mx-=k;
		return ;
	}
	if(nr-nl<C)
	{
		ll s=0;
		int mx=0,mn=1000000000,c=0;
		for(int j=nl; j<=nr; ++j) if(L[j]==b) ans[j]+=seg[b][i].tag;
		seg[b][i].tag=0;
		if(tag[b][i]) for(int j=nl; j<=nr; ++j) if(L[j]==b) a[j]+=tag[b][i];
		tag[b][i]=0;
		for(int j=nl; j<=nr; ++j) if(L[j]==b)
		if(l<=j&&j<=r&&a[j]>k) 
		{
			++ans[j],a[j]-=k;
			if(L[j]==lg(a[j])) s+=a[j],(mn>a[j])&&(mn=a[j]),(mx<a[j])&&(mx=a[j]),++c;
			else L[j]=lg(a[j]),rebuild(L[j],1,n,j,1);
		}
		else s+=a[j],(mn>a[j])&&(mn=a[j]),(mx<a[j])&&(mx=a[j]),++c;
		seg[b][i]=(node){mx,mn,c,s};
		return ;
	}
	if(tag[b][i])
	seg[b][i<<1].sum+=1ll*tag[b][i]*seg[b][i<<1].cnt,
	seg[b][(i<<1)+1].sum+=1ll*tag[b][i]*seg[b][(i<<1)+1].cnt,
	seg[b][i<<1].mx+=tag[b][i],seg[b][(i<<1)+1].mx+=tag[b][i],
	seg[b][i<<1].mn+=tag[b][i],seg[b][(i<<1)+1].mn+=tag[b][i],
	tag[b][i<<1]+=tag[b][i],tag[b][(i<<1)+1]+=tag[b][i],
	tag[b][i]=0;
	seg[b][i<<1].tag+=seg[b][i].tag,seg[b][(i<<1)+1].tag+=seg[b][i].tag,
	seg[b][i].tag=0;
	int mid=(nl+nr)>>1;
	update(b,l,r,nl,mid,k,i<<1),update(b,l,r,mid+1,nr,k,(i<<1)+1);
	seg[b][i].sum=seg[b][i<<1].sum+seg[b][(i<<1)+1].sum,
	seg[b][i].mn=Min(seg[b][i<<1].mn,seg[b][(i<<1)+1].mn),
	seg[b][i].mx=Max(seg[b][i<<1].mx,seg[b][(i<<1)+1].mx),
	seg[b][i].cnt=seg[b][i<<1].cnt+seg[b][(i<<1)+1].cnt;
	return ;
}
void dfs(int b,int l,int r,int nl,int nr,int k,int i)
{
	if(nr<l||r<nl||seg[b][i].mx<=k) return ;
	if(nr-nl<C)
	{
		for(int j=nl; j<=nr; ++j) if(L[j]==b) ans[j]+=seg[b][i].tag;
		return ;
	}
	seg[b][i<<1].tag+=seg[b][i].tag,seg[b][(i<<1)+1].tag+=seg[b][i].tag,
	seg[b][i].tag=0;
	int mid=(nl+nr)>>1;
	dfs(b,l,r,nl,mid,k,i<<1),dfs(b,l,r,mid+1,nr,k,(i<<1)+1);
	return ;
}
pair<int,int> A[1000003];
signed main()
{
	int N=read();
	for(int i=1; i<=N; ++i) A[i].second=read(),A[i].first=-read();
	sort(A+1,A+N+1),n=read();
	memset(L,-1,sizeof(L));
	for(int i=16; i<65536; ++i) lg16[i]=lg16[i>>4]+1;
	for(int i=1; i<=n; ++i) a[i]=read()+1,L[i]=lg(a[i]),rebuild(L[i],1,n,i,1);
	for(int i=1; i<=N; ++i)
		for(int j=lg(A[i].second); j<8; ++j) update(j,1,n,1,n,A[i].second,1);
	for(int j=0; j<8; ++j) dfs(j,1,n,1,n,0,1);
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
    return 0;
}