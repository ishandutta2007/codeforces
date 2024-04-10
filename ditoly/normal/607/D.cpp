#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
#define MOD 1000000007
#define L (k<<1)
#define R (k<<1|1)
struct edge{int nx,t;}e[MN+5];
int h[MN+5],en,v[MN+5],d[MN+5],o[MN+5],p[MN+5],l[MN+5],r[MN+5],fa[MN+5],cnt;
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
inline int inv(int x)
{
	int r=1,y=MOD-2;
	for(;y;y>>=1,x=1LL*x*x%MOD)if(y&1)r=1LL*r*x%MOD;
	return r;
}
void dfs(int x)
{
	l[x]=++cnt;
	for(int i=h[x];i;i=e[i].nx)
		fa[e[i].t]=x,dfs(e[i].t);
	r[x]=cnt;
}
inline int mod(int x){return x<MOD?x:x-MOD;}
struct node{int s,mk;}t[MN*4+5];
void build(int k,int l,int r)
{
	if(t[k].mk=1,l==r)return;
	int mid=l+r>>1;
	build(L,l,mid);build(R,mid+1,r);
}
void up(int k){t[k].s=mod(t[L].s+t[R].s);}
void mul(int k,int x){t[k].s=1LL*t[k].s*x%MOD;t[k].mk=1LL*t[k].mk*x%MOD;}
void down(int k){if(t[k].mk!=1)mul(L,t[k].mk),mul(R,t[k].mk),t[k].mk=1;}
void change(int k,int l,int r,int x,int z)
{
	if(l==r){t[k].s=1LL*z*t[k].mk%MOD;return;}
	int mid=l+r>>1;down(k);
	if(x<=mid)change(L,l,mid,x,z);else change(R,mid+1,r,x,z);
	up(k);
}
void mul(int k,int l,int r,int ql,int qr,int z)
{
	if(l==ql&&r==qr){mul(k,z);return;}
	int mid=l+r>>1;down(k);
	if(qr<=mid)mul(L,l,mid,ql,qr,z);
	else if(ql>mid)mul(R,mid+1,r,ql,qr,z);
	else mul(L,l,mid,ql,mid,z),mul(R,mid+1,r,mid+1,qr,z);
	up(k);
}
int query(int k,int l,int r,int ql,int qr)
{
	if(l==ql&&r==qr)return t[k].s;
	int mid=l+r>>1;down(k);
	if(qr<=mid)return query(L,l,mid,ql,qr);
	if(ql>mid)return query(R,mid+1,r,ql,qr);
	return mod(query(L,l,mid,ql,mid)+query(R,mid+1,r,mid+1,qr));
}
int Q(int k,int l,int r,int x)
{
	if(l==r)return t[k].mk;
	int mid=l+r>>1;down(k);
	if(x<=mid)return Q(L,l,mid,x);
	return Q(R,mid+1,r,x);
}
int main()
{
	int i,j,q,n=1;
	v[1]=read();q=read();
	for(i=1;i<=q;++i)
	{
		o[i]=read();p[i]=read();
		if(o[i]<2)ins(p[i],++n),v[p[i]=n]=read();
	}
	dfs(1);build(1,1,n);
	for(p[i=0]=1;i<=q;++i)
		if(o[i]<2)
		{
			change(1,1,n,l[p[i]],v[p[i]]);d[p[i]]=1;
			if(j=fa[p[i]])mul(1,1,n,l[j],r[j],1LL*(d[j]+1)*inv(d[j])%MOD),++d[j];
		}
		else printf("%d\n",1LL*query(1,1,n,l[p[i]],r[p[i]])*
			(fa[p[i]]?inv(Q(1,1,n,l[fa[p[i]]])):1)%MOD);
}