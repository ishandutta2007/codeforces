#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define L (k<<1)
#define R (k<<1|1) 
struct node{ll mn,mk;}t[MN*4+5];
struct data{int b,p;}d[MN+5];
bool cmp(const data&a,const data&b){return a.p==b.p?a.b<b.b:a.p<b.p;}
int a[MN+5],z[MN+5],zn;ll s[MN+5];
inline void up(int k){t[k].mn=min(t[L].mn,t[R].mn);}
inline void mark(int k,ll x){t[k].mn-=x;t[k].mk+=x;}
inline void down(int k){if(t[k].mk)mark(L,t[k].mk),mark(R,t[k].mk),t[k].mk=0;}
void build(int k,int l,int r)
{
	if(l==r){t[k].mn=s[l];return;}
	int mid=l+r>>1;
	build(L,l,mid);build(R,mid+1,r);up(k);
}
void modify(int k,int l,int r,int ql,int qr,int x)
{
	if(l==ql&&r==qr){mark(k,x);return;}
	int mid=l+r>>1;down(k);
	if(qr<=mid)modify(L,l,mid,ql,qr,x);
	else if(ql>mid)modify(R,mid+1,r,ql,qr,x);
	else modify(L,l,mid,ql,mid,x),modify(R,mid+1,r,mid+1,qr,x);
	up(k);
}
ll query(int k,int l,int r,int ql,int qr)
{
	if(l==ql&&r==qr)return t[k].mn;
	int mid=l+r>>1;down(k);
	if(qr<=mid)return query(L,l,mid,ql,qr);
	if(ql>mid)return query(R,mid+1,r,ql,qr);
	return min(query(L,l,mid,ql,mid),query(R,mid+1,r,mid+1,qr));
}
int main()
{
	int n,m,i,j,ans=0;
	n=read();m=read();
	for(i=1;i<=n;++i)
	{
		s[i]=s[i-1]+(a[i]=read());
		while(zn&&a[i]>=a[z[zn]])--zn;
		z[++zn]=i;
	}
	build(1,1,n);
	for(i=1;i<=m;++i)d[i].b=read();
	for(i=1;i<=m;++i)d[i].p=read();
	sort(d+1,d+m+1,cmp);
	for(i=1;i<=m;++i)
	{
		int l,r,mid,j=0;
		for(l=1,r=zn;l<=r;)if(a[z[mid=l+r>>1]]>=d[i].b)j=z[mid],l=mid+1;else r=mid-1;
		if(j&&query(1,1,n,j,n)>=d[i].p)modify(1,1,n,j,n,d[i].p),++ans;
	}
	printf("%d",ans);
}