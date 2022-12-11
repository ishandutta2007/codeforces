#include<cstdio>
#define MAXN 100000
#define MOD 1000000007
#define ll long long
#define lc(x) (x<<1)
#define rc(x) ((x<<1)+1)
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
inline void add(int&a,int b){a+=b;if(a>=MOD)a-=MOD;}
struct matrix
{
	int a[2][2];
	inline matrix(int x1=0,int x2=0,int x3=0,int x4=0)
	{
		a[0][0]=x1;a[0][1]=x2;
		a[1][0]=x3;a[1][1]=x4;
	}
}p[51];
inline matrix operator+(matrix a,matrix&b)
{
	add(a.a[0][0],b.a[0][0]);
	add(a.a[0][1],b.a[0][1]);
	return a;
}
inline matrix operator*(matrix&a,matrix&b)
{
	matrix c;int i,j,k;ll x;
	for(i=0;i<2;i++)for(j=0;j<2;j++)
	{
		x=0;
		for(k=0;k<2;k++)x+=(ll)a.a[i][k]*b.a[k][j];
		c.a[i][j]=x%MOD;
	}
	return c;
}
inline void pow(matrix&a,ll x)
{
	if(x==536870911)a=a*p[50];
	else for(int i=0;x;i++,x>>=1)if(x&1)a=a*p[i];
}
struct node
{
	int l,r;ll x;
	matrix s;
}t[MAXN*4];
int a[MAXN+5],x,ans;
void build(int k,int l,int r)
{
	t[k].l=l;t[k].r=r;t[k].x=0;
	if(l==r){t[k].s=matrix(1);pow(t[k].s,a[l]);return;}
	int mid=(l+r)>>1;
	build(lc(k),l,mid);
	build(rc(k),mid+1,r);
	t[k].s=t[lc(k)].s+t[rc(k)].s;
}
inline void inc(int k,ll x)
{
	t[k].x+=x;
	pow(t[k].s,x);
}
void change(int k,int l,int r)
{
	if(t[k].l==l&&t[k].r==r){inc(k,x);return;}
	if(t[k].x){inc(lc(k),t[k].x);inc(rc(k),t[k].x);t[k].x=0;}
	int mid=(t[k].l+t[k].r)>>1;
	if(r<=mid)change(lc(k),l,r);
	else if(l>mid)change(rc(k),l,r);
	else{change(lc(k),l,mid);change(rc(k),mid+1,r);}
	t[k].s=t[lc(k)].s+t[rc(k)].s;
}
void query(int k,int l,int r)
{
	if(t[k].l==l&&t[k].r==r){add(ans,t[k].s.a[0][1]);return;}
	if(t[k].x){inc(lc(k),t[k].x);inc(rc(k),t[k].x);t[k].x=0;}
	int mid=(t[k].l+t[k].r)>>1;
	if(r<=mid)query(lc(k),l,r);
	else if(l>mid)query(rc(k),l,r);
	else query(lc(k),l,mid),query(rc(k),mid+1,r);
	t[k].s=t[lc(k)].s+t[rc(k)].s;
}
int main()
{
	int n,m,i,t,l,r;
	p[0]=matrix(0,1,1,1);
	for(i=1;i<50;i++)p[i]=p[i-1]*p[i-1];
	p[50]=matrix(520757983,380127118,380127118,900885101);
	n=read();m=read();
	for(i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	while(m--)
	{
		t=read();l=read();r=read();
		if(t==1)x=read(),change(1,l,r);
		else ans=0,query(1,l,r),printf("%d\n",ans);
	}
}