#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,q;
char s[200020],t[200020];
int cnt[800080],tag[800080];
void build(int k,int l,int r)
{
	tag[k]=-1;
	if(l==r)return cnt[k]=t[l]=='1',void();
	build(k<<1,l,(l+r)>>1);
	build(k<<1|1,((l+r)>>1)+1,r);
	cnt[k]=cnt[k<<1]+cnt[k<<1|1];
}
void pushdown(int k,int l,int r)
{
	tag[k<<1]=tag[k<<1|1]=tag[k];
	if(tag[k])cnt[k<<1]=((l+r)>>1)-l+1,cnt[k<<1|1]=r-((l+r)>>1);
	else cnt[k<<1]=cnt[k<<1|1]=0;
	tag[k]=-1;
}
int query(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return 0;
	if(l>=ll&&r<=rr)return cnt[k];
	if(tag[k]!=-1)pushdown(k,l,r);
	return query(k<<1,l,(l+r)>>1,ll,rr)+query(k<<1|1,((l+r)>>1)+1,r,ll,rr);
}
void change(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return;
	if(l>=ll&&r<=rr)
	{
		tag[k]=w;
		cnt[k]=w?r-l+1:0;
		return;
	}
	if(tag[k]!=-1)pushdown(k,l,r);
	change(k<<1,l,(l+r)>>1,ll,rr,w);
	change(k<<1|1,((l+r)>>1)+1,r,ll,rr,w);
	cnt[k]=cnt[k<<1]+cnt[k<<1|1];
}
bool chk(int k,int l,int r)
{
	if(l==r)return cnt[k]==(s[l]=='1');
	if(tag[k]!=-1)pushdown(k,l,r);
	return chk(k<<1,l,(l+r)>>1)&&chk(k<<1|1,((l+r)>>1)+1,r);
}
int l[200010],r[200010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&q);
		scanf(" %s",s+1);
		scanf(" %s",t+1);
		build(1,1,n);
		bool flag=1;
		for(int i=1;i<=q;++i)scanf("%d %d",&l[i],&r[i]);
		for(int i=q;i;--i)
		{
			static int x,y;
			x=l[i],y=r[i];
			int c=query(1,1,n,x,y);
			if(2*c==y-x+1)flag=0;
			if(2*c<=y-x+1)change(1,1,n,x,y,0);
			else change(1,1,n,x,y,1);
		}
		flag&=chk(1,1,n);
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}