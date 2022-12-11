#include<cstdio>
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
#define L (k<<1)
#define R (k<<1|1)
int s[MN+5][10];
struct node{int l,r,v[10];ll s[10];}t[MN*4+5];
void up(int k){for(int i=0;i<10;++i)t[k].s[i]=t[L].s[i]+t[R].s[i];}
inline void cal(int k,int f)
{
	ll s[10];int i;
	for(i=0;i<10;++i)s[i]=t[k].s[i],t[k].s[i]=0;
	for(i=0;i<10;++i)t[k].s[t[f].v[i]]+=s[i];
	for(i=0;i<10;++i)t[k].v[i]=t[f].v[t[k].v[i]];
}
inline void down(int k)
{
	cal(L,k);cal(R,k);
	for(int i=0;i<10;++i)t[k].v[i]=i;
}
void build(int k,int l,int r)
{
	for(int i=0;i<10;++i)t[k].v[i]=i;
	if((t[k].l=l)==(t[k].r=r))
	{
		for(int i=0;i<10;++i)t[k].s[i]=s[l][i];
		return;
	}
	int mid=l+r>>1;
	build(L,l,mid);build(R,mid+1,r);up(k);
}
void change(int k,int l,int r,int x,int y)
{
	if(t[k].l==l&&t[k].r==r)
	{
		t[k].s[y]+=t[k].s[x];t[k].s[x]=0;
		for(int i=0;i<10;++i)if(t[k].v[i]==x)t[k].v[i]=y;
		return;
	}
	int mid=t[k].l+t[k].r>>1;down(k);
	if(r<=mid)change(L,l,r,x,y);
	else if(l>mid)change(R,l,r,x,y);
	else change(L,l,mid,x,y),change(R,mid+1,r,x,y);
	up(k);
}
ll query(int k,int l,int r)
{
	if(t[k].l==l&&t[k].r==r)
	{
		ll res=0;
		for(int i=0;i<10;++i)res+=i*t[k].s[i];
		return res;
	}
	int mid=t[k].l+t[k].r>>1;down(k);
	if(r<=mid)return query(L,l,r);
	if(l>mid)return query(R,l,r);
	return query(L,l,mid)+query(R,mid+1,r);
}
int main()
{
	int n,q,i,j,x,y;
	n=read();q=read();
	for(i=1;i<=n;++i)for(x=read(),j=1;x;j*=10,x/=10)s[i][x%10]+=j;
	build(1,1,n);
	while(q--)
		if(read()==1)
		{
			i=read();j=read();x=read();y=read();
			if(x!=y)change(1,i,j,x,y);
		}
		else i=read(),j=read(),printf("%I64d\n",query(1,i,j));
}