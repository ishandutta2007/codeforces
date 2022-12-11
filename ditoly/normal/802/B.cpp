#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
#define MN 400000
#define L (k<<1)
#define R (k<<1|1)
#define up(k) t[k].mx=max(t[L].mx,t[R].mx)
struct node{int l,r,mk,mx;}t[MN*4+5];
inline void add(int k,int x){t[k].mx+=x;t[k].mk+=x;}
inline void down(int k){if(t[k].mk)add(L,t[k].mk),add(R,t[k].mk),t[k].mk=0;}
void build(int k,int l,int r)
{
	if((t[k].l=l)==(t[k].r=r))return;
	int mid=l+r>>1;
	build(L,l,mid);build(R,mid+1,r);
}
void add(int k,int l,int r)
{
	if(t[k].l==l&&t[k].r==r){add(k,1);return;}
	int mid=t[k].l+t[k].r>>1;down(k);
	if(r<=mid)add(L,l,r);
	else if(l>mid)add(R,l,r);
	else add(L,l,mid),add(R,mid+1,r);
	up(k);
}
int query(int k,int l,int r)
{
	if(t[k].l==l&&t[k].r==r)return t[k].mx;
	int mid=t[k].l+t[k].r>>1;down(k);
	if(r<=mid)return query(L,l,r);
	if(l>mid)return query(R,l,r);
	return max(query(L,l,mid),query(R,mid+1,r));
}
int ls[MN+5];
int main()
{
	int n,k,i,x,ans=0;
	n=read();k=read();
	build(1,1,n);
	for(i=1;i<=n;++i)
	{
		x=read();
		if(ls[x]&&query(1,ls[x]+1,i)<k)add(1,ls[x]+1,i);
		else add(1,i,i),++ans;
		ls[x]=i;
	}
	printf("%d",ans);
}