#include<cstdio>
#include<cstring>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
#define L (k<<1)
#define R (k<<1|1)
struct lb{int b[30],v[30],u;};
void ins(lb&a,int x,int v)
{
	for(int i=30;i--;)if(x&(1<<i))
		if(a.b[i])x^=a.b[i],v^=a.v[i];else{a.b[i]=x;a.v[i]=v;x=-1;break;}
	if(x>=0&&v)++a.u;
}
lb operator+(lb a,const lb&b)
{
	a.u+=b.u;
	for(int i=30;i--;)if(b.b[i])ins(a,b.b[i],b.v[i]);
	return a;
}
struct node{lb x;int mk;}t[MN*4+5];
int a[MN+5];
inline void up(int k){t[k].x=t[L].x+t[R].x;}
void mark(int k,int x)
{
	lb a;memset(&a,0,sizeof(a));
	for(int i=30;i--;)if(t[k].x.b[i])ins(a,t[k].x.b[i]^(t[k].x.v[i]*x),t[k].x.v[i]);
	if(t[k].x.u)ins(a,x,1);
	t[k].x=a;t[k].mk^=x;
}
inline void down(int k){if(t[k].mk)mark(L,t[k].mk),mark(R,t[k].mk),t[k].mk=0;}
void build(int k,int l,int r)
{
	if(l==r){ins(t[k].x,a[l],1);return;}
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
lb query(int k,int l,int r,int ql,int qr)
{
	if(l==ql&&r==qr)return t[k].x;
	int mid=l+r>>1;down(k);
	if(qr<=mid)return query(L,l,mid,ql,qr);
	if(ql>mid)return query(R,mid+1,r,ql,qr);
	return query(L,l,mid,ql,mid)+query(R,mid+1,r,mid+1,qr);
}
int main()
{
	int n,q,i,t,l,r;
	n=read();q=read();
	for(i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	while(q--)
	{
		t=read();l=read();r=read();
		if(t<2)modify(1,1,n,l,r,read());
		else
		{
			lb x=query(1,1,n,l,r);t=1;
			for(i=30;i--;)if(x.b[i])t<<=1;
			printf("%d\n",t);
		}
	}
}