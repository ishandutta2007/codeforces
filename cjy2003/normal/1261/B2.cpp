#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,m,a[200020],ans[200020];
struct data
{
	int w,p;
	friend bool operator < (data a,data b)
	{
		if(a.w!=b.w)return a.w>b.w;
		return a.p<b.p;
	}
}p[200020];
struct query
{
	int k,p,id;
	friend bool operator < (query a,query b){return a.k<b.k;}
}q[200020];
int sum[800080];
void ins(int k,int l,int r,int p)
{
	++sum[k];
	if(l==r)return ;
	if(p<=l+r>>1)ins(k<<1,l,l+r>>1,p);
	else ins(k<<1|1,(l+r>>1)+1,r,p);
}
int query(int k,int l,int r,int w)
{
	if(l==r)return a[l];
	if(sum[k<<1]>=w)return query(k<<1,l,l+r>>1,w);
	else return query(k<<1|1,(l+r>>1)+1,r,w-sum[k<<1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),p[i]=data{a[i],i};
	sort(p+1,p+1+n);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)scanf("%d %d",&q[i].k,&q[i].p),q[i].id=i;
	sort(q+1,q+1+m);
	int last=1;
	for(int i=1;i<=m;++i)
	{
		while(last<=q[i].k)ins(1,1,n,p[last].p),++last;
		ans[q[i].id]=query(1,1,n,q[i].p);
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}