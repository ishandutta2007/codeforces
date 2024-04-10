#include<cstdio>
#include<algorithm>
using namespace std;
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
struct node{int mn,mm,mk;}t[MN*4+5];
inline void up(int k){t[k].mn=min(t[L].mn,t[R].mn);t[k].mm=min(t[L].mm,t[R].mm);}
inline void mark(int k,int x){t[k].mn+=x;t[k].mm+=x;t[k].mk+=x;}
inline void down(int k){if(t[k].mk)mark(L,t[k].mk),mark(R,t[k].mk),t[k].mk=0;}
int a[MN+5],O;
void build(int k,int l,int r)
{
	if(l==r){t[k].mn=a[l];t[k].mm=a[l]+l-1;return;}
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
int query(int k,int l,int r,int ql,int qr)
{
	if(l==ql&&r==qr)return O?t[k].mn:t[k].mm;
	int mid=l+r>>1;down(k);
	if(qr<=mid)return query(L,l,mid,ql,qr);
	if(ql>mid)return query(R,mid+1,r,ql,qr);
	return min(query(L,l,mid,ql,mid),query(R,mid+1,r,mid+1,qr));
}
int main()
{
	int n=read(),i,l,r,mid,res,ans=1e9;
	for(i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	for(i=1;i<=n;++i)
	{
		if(i>1){modify(1,1,n,1,i-1,1);modify(1,1,n,i,n,-1);}
		if(t[1].mn<=0)
		{
			for(l=1,r=n,O=1;l<=r;)
				if(query(1,1,n,1,mid=l+r>>1)<=0)res=mid,r=mid-1;else l=mid+1;
			if(res>1)O=0,ans=min(ans,max(query(1,1,n,1,res-1),query(1,1,n,res,n)));
		}
	}
	printf("%d",ans<1e9?ans:-1);
}