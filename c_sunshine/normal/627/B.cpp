#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=200005;
LL ans;
int n,k,a,b,q;
int val[maxn];
struct node
{
	LL sum[2];
	node *lc,*rc;
	
	void add(int l,int r,int p,int c)
	{
		if(l==r)
		{
			val[p]+=c;
			sum[0]=min(val[p],b);
			sum[1]=min(val[p],a);
			return;
		}
		int mid=l+r>>1;
		if(p<=mid)lc->add(l,mid,p,c);
		else rc->add(mid+1,r,p,c);
		sum[0]=lc->sum[0]+rc->sum[0];
		sum[1]=lc->sum[1]+rc->sum[1];
	}
	LL ask(int l,int r,int a,int b,int t)
	{
		if(l>=a&&r<=b)return sum[t];
		int mid=l+r>>1;LL res=0;
		if(a<=mid)res+=lc->ask(l,mid,a,b,t);
		if(b>mid)res+=rc->ask(mid+1,r,a,b,t);
		return res;
	}
}ndl[maxn*2],*root,*ns=ndl;

node* build(int l,int r)
{
	node *x=++ns;
	if(l<r)
		x->lc=build(l,l+r>>1),
		x->rc=build(l+r+2>>1,r);
	return x;
}

int main()
{
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	root=build(1,n);
	for(int op,x,y,p,qi=1;qi<=q;qi++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			root->add(1,n,x,y);
		}
		else
		{
			scanf("%d",&p);
			ans=0;
			if(p>1)ans+=root->ask(1,n,1,p-1,0);
			if(p+k<=n)ans+=root->ask(1,n,p+k,n,1);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}