#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,t[100010];
long long po[]={1,42,1764,74088,3111696,130691232,5489031744,230539333248,9682651996416,406671383849472,17080198121677824,717368321110468608};
long long mi[400040],ad[400040];
int pos[400040];
bool eq[400040];
void build(int k,int l,int r)
{
	if(l==r)
	{
		eq[k]=1;
		while(po[pos[k]]<=t[l])++pos[k];
		mi[k]=po[pos[k]]-t[l];
		return ;
	}
	build(k<<1,l,l+r>>1),build(k<<1|1,(l+r>>1)+1,r);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
	if(eq[k<<1]&&eq[k<<1|1]&&mi[k<<1]==mi[k<<1|1]&&pos[k<<1]==pos[k<<1|1])eq[k]=1,pos[k]=pos[k<<1];
}
inline void pushdown(int k)
{
	if(eq[k])
	{
		eq[k<<1]=eq[k<<1|1]=1;
		mi[k<<1]=mi[k<<1|1]=mi[k];
		pos[k<<1]=pos[k<<1|1]=pos[k];
	}
	else ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k],mi[k<<1]-=ad[k],mi[k<<1|1]-=ad[k];
	ad[k]=0;
}
long long getva(int k,int l,int r,int p)
{
	if(eq[k])return po[pos[k]]-mi[k];
	if(eq[k]||ad[k])pushdown(k);
	if(p<=l+r>>1)return getva(k<<1,l,l+r>>1,p);
	else return getva(k<<1|1,(l+r>>1)+1,r,p);
}
void upd(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)
	{
		eq[k]=1;
		pos[k]=0;
		while(po[pos[k]]<w)++pos[k];
		mi[k]=po[pos[k]]-w;ad[k]=0;
		return ;
	}
	if(eq[k]||ad[k])pushdown(k);
	upd(k<<1,l,l+r>>1,ll,rr,w);
	upd(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
	if(eq[k<<1]&&eq[k<<1|1]&&mi[k<<1]==mi[k<<1|1]&&pos[k<<1]==pos[k<<1|1])eq[k]=1,pos[k]=pos[k<<1];
	else eq[k]=0;
}
bool flag;
void change(int k,int l,int r)
{
	if(mi[k]>=0)return ;
	if(eq[k])
	{
		long long w=po[pos[k]]-mi[k];
		while(po[pos[k]]<w)++pos[k];
		mi[k]=po[pos[k]]-w;
		return ;
	}
	if(eq[k]||ad[k])pushdown(k);
	change(k<<1,l,l+r>>1);
	change(k<<1|1,(l+r>>1)+1,r);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
	if(eq[k<<1]&&eq[k<<1|1]&&mi[k<<1]==mi[k<<1|1]&&pos[k<<1]==pos[k<<1|1])eq[k]=1,pos[k]=pos[k<<1];
	else eq[k]=0;
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)
	{
		mi[k]-=w;ad[k]+=w;
		if(mi[k]<0)change(k,l,r);
		if(mi[k]==0)flag=1;
		return ;
	}
	if(eq[k]||ad[k])pushdown(k);
	add(k<<1,l,l+r>>1,ll,rr,w);
	add(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
	if(eq[k<<1]&&eq[k<<1|1]&&mi[k<<1]==mi[k<<1|1]&&pos[k<<1]==pos[k<<1|1])eq[k]=1,pos[k]=pos[k<<1];
	else eq[k]=0;	
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]);
	build(1,1,n);
	int c,x,y,w;
	while(q--)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d",&x);
			printf("%lld\n",getva(1,1,n,x));
		}
		else if(c==2)
		{
			scanf("%d %d %d",&x,&y,&w);
			upd(1,1,n,x,y,w);
		}
		else
		{
			scanf("%d %d %d",&x,&y,&w);
			flag=1;
			while(flag)flag=0,add(1,1,n,x,y,w);
		}
	}
	return 0;
}