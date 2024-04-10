#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct query
{
	int l,r,id;
	friend bool operator < (query a,query b)
	{
		return a.r<b.r;
	}
}q[200020];
int n,m,qnum,a[200020],b[200020],dya[200020],dyb[200020],len[200020],st[200020],mxl;
int ans[200020];
int sum[10000000],lson[10000000],rson[10000000],rt[200020],tot;
void add(int &now,int pre,int l,int r,int p,int w)
{
	now=++tot;
	sum[now]=sum[pre]+w;
	if(l==r)return ;
	if(p<=(l+r>>1))add(lson[now],lson[pre],l,l+r>>1,p,w),rson[now]=rson[pre];
	else add(rson[now],rson[pre],(l+r>>1)+1,r,p,w),lson[now]=lson[pre];
}
int qmin(int k,int l,int r)
{
	if(l==r)return l;
	if(sum[lson[k]])return qmin(lson[k],l,l+r>>1);
	else return qmin(rson[k],(l+r>>1)+1,r);
}
int main()
{
	scanf("%d %d %d",&n,&m,&qnum);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),dya[a[i]]=i;
	a[0]=a[n];
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&b[i]),dyb[b[i]]=i;
		int last=dyb[a[dya[b[i]]-1]];
		add(rt[i],rt[last],1,m,i,1);
		if(len[last]==n)add(rt[i],rt[i],1,m,qmin(rt[last],1,m),-1);
		st[i]=qmin(rt[i],1,m);
		len[i]=min(len[last]+1,n);
	//	printf("%d\n",st[i]);
	}
	int x,y;
	for(int i=1;i<=qnum;++i)
	{
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+1+qnum);
	int last=1;
	for(int i=1;i<=qnum;++i)
	{
		while(last<=q[i].r)
		{
			if(len[last]==n)mxl=max(mxl,st[last]);
			++last;
		}
		ans[q[i].id]=mxl>=q[i].l;
	}
	for(int i=1;i<=qnum;++i)
		printf("%d",ans[i]);
	return 0;
}