#include<cstdio>
#include<algorithm>
#include<vector>
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
int a[MN+5],c[MN+5],cn,l[MN+5],r[MN+5],w[MN+5],zl[MN+5],zr[MN+5],ans[MN+5],p[MN+5];
vector<int> v[MN+5];
struct data{int n,x,l,r;}t[MN*4+5];
inline data operator+(const data&a,const data&b)
	{return (data){a.n+b.n,max(a.r+b.l,max(a.x,b.x)),a.l+(a.l<a.n?0:b.l),b.r+(b.r<b.n?0:a.r)};}
void build(int k,int l,int r)
{
	if(t[k]=(data){r-l+1,0,0,0},l==r)return;
	int mid=l+r>>1;
	build(L,l,mid);build(R,mid+1,r);
}
void modify(int k,int l,int r,int x)
{
	if(l==r){t[k].x=t[k].l=t[k].r=1;return;}
	int mid=l+r>>1;
	if(x<=mid)modify(L,l,mid,x);else modify(R,mid+1,r,x);
	t[k]=t[L]+t[R];
}
data query(int k,int l,int r,int ql,int qr)
{
	if(l==ql&&r==qr)return t[k];
	int mid=l+r>>1;
	if(qr<=mid)return query(L,l,mid,ql,qr);
	if(ql>mid)return query(R,mid+1,r,ql,qr);
	return query(L,l,mid,ql,mid)+query(R,mid+1,r,mid+1,qr);
}
bool cmp(int a,int b){return zl[a]>zl[b];}
int main()
{
	int n=read(),m,i,j,k,mid;
	for(i=1;i<=n;++i)a[i]=c[i]=read();
	sort(c+1,c+n+1);cn=unique(c+1,c+n+1)-c-1;
	for(i=1;i<=n;++i)v[lower_bound(c+1,c+cn+1,a[i])-c].push_back(i);
	for(m=read(),i=1;i<=m;++i)l[i]=read(),r[i]=read(),w[i]=read(),zl[i]=1,zr[i]=cn,p[i]=i;
	for(;;)
	{
		for(i=1;i<=m;++i)if(zl[i]<=zr[i])break;
		if(i>m)break;
		sort(p+1,p+m+1,cmp);build(1,1,n);
		for(i=1,j=cn;i<=m;++i)
		{
			mid=zl[p[i]]+zr[p[i]]>>1;
			for(;j>=mid;--j)for(k=0;k<v[j].size();++k)modify(1,1,n,v[j][k]);
			if(query(1,1,n,l[p[i]],r[p[i]]).x>=w[p[i]])ans[p[i]]=mid,zl[p[i]]=mid+1;
			else zr[p[i]]=mid-1;
		}
	}
	for(i=1;i<=m;++i)printf("%d\n",c[ans[i]]);
}