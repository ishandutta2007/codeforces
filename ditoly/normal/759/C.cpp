#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MN 100000
#define lc(k) (k<<1)
#define rc(k) ((k<<1)+1)
struct data
{
	int a,b;
	friend data operator+(data a,data b)
	{
		int x=a.b<b.a?a.b:b.a;
		return (data){a.a+b.a-x,a.b+b.b-x};
	}
};
struct node{int l,r;data x;}t[MN*4];
void build(int k,int l,int r)
{
	t[k].l=l;t[k].r=r;
	if(l==r)return;
	int mid=l+r>>1;
	build(lc(k),l,mid);build(rc(k),mid+1,r);
}
void update(int k,int x,int z)
{
	if(t[k].l==t[k].r){++(z?t[k].x.b:t[k].x.a);return;}
	update(x>t[k].l+t[k].r>>1?rc(k):lc(k),x,z);
	t[k].x=t[lc(k)].x+t[rc(k)].x;
}
data query(int k,int l,int r)
{
	if(t[k].l==l&&t[k].r==r)return t[k].x;
	int mid=t[k].l+t[k].r>>1;
	if(r<=mid)return query(lc(k),l,r);
	if(l>mid)return query(rc(k),l,r);
	return query(lc(k),l,mid)+query(rc(k),mid+1,r);
}
int a[MN+5],pn;
int main()
{
	int n=read(),i,p,x,l,r,mid,ans;
	build(1,1,n);
	for(i=1;i<=n;++i)
	{
		p=read();if(x=read())a[p]=read();
		update(1,p,x);
		if(!t[1].x.b){puts("-1");continue;}
		for(l=1,r=n;l<=r;)
		{
			if(query(1,mid=l+r>>1,n).b)l=mid+1,ans=a[mid];
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
}