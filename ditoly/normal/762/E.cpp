#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MN 100000
#define MX 1000000000
struct P{int x,r,f;}p[MN+5];
struct node{int l,r,s;}t[MN*50+5];
bool cmp(const P&a,const P&b){return a.r>b.r;}
int rt[MN+5],tn;
int query(int k,int l,int r,int ql,int qr)
{
	if(!k)return 0;
	if(ql<=l&&qr>=r)return t[k].s;
	int mid=l+r>>1;
	if(qr<=mid)return query(t[k].l,l,mid,ql,qr);
	if(ql>mid)return query(t[k].r,mid+1,r,ql,qr);
	return query(t[k].l,l,mid,ql,mid)+query(t[k].r,mid+1,r,mid+1,qr);
}
void add(int&k,int l,int r,int x)
{
	++t[k=k?k:++tn].s;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)add(t[k].l,l,mid,x);
	else add(t[k].r,mid+1,r,x);
}
int main()
{
	int n,k,i,j;long long ans=0;
	n=read();k=read();
	for(i=1;i<=n;++i)p[i].x=read(),p[i].r=read(),p[i].f=read()+k;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;++i)
	{
		for(j=-k;j<=k;++j)ans+=query(rt[p[i].f+j],1,MX,p[i].x-p[i].r,p[i].x+p[i].r);
		add(rt[p[i].f],1,MX,p[i].x);
	}
	printf("%I64d",ans);
}