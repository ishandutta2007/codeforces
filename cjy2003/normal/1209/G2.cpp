#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<ctime>
#include<iostream>
using namespace std;
int n,q,a[200020];
set<int>S[200020];
struct data
{
	int lmx,rmx,mi,cnt,sum,mx;
	void print(){printf("%d %d %d %d %d %d\n",lmx,rmx,mi,cnt,sum,mx);}

}s[800080];
inline void get(data &a,data &b,data &c)
{
	c.mi=min(a.mi,b.mi);c.mx=max(a.mx,b.mx);
	c.cnt=(a.mi==c.mi?a.cnt:0)+(b.mi==c.mi?b.cnt:0);
	if(b.mi>c.mi)
	{
		c.sum=a.sum;c.rmx=max(b.mx,a.rmx),c.lmx=a.lmx;
		if(b.mx>a.rmx)c.sum+=b.mx-a.rmx;
	}
	else if(a.mi>c.mi)
	{
		c.sum=b.sum;c.lmx=max(a.mx,b.lmx),c.rmx=b.rmx;
		if(a.mx>b.lmx)c.sum+=a.mx-b.lmx;
	}
	else
	{
		c.lmx=a.lmx,c.rmx=b.rmx;
		c.sum=a.sum+b.sum-min(a.rmx,b.lmx);
	}
}
int ad[800080];
inline void pushdown(int k)
{
	ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k];
	s[k<<1].mi+=ad[k],s[k<<1|1].mi+=ad[k];
	ad[k]=0;
}
void build(int k,int l,int r)
{
	s[k].cnt=r-l+1;
	if(l==r)return ;
	build(k<<1,l,l+r>>1);
	build(k<<1|1,(l+r>>1)+1,r);
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)
	{
		ad[k]+=w;
		s[k].mi+=w;
		return ;
	}
	if(ad[k])pushdown(k);
	add(k<<1,l,l+r>>1,ll,rr,w);
	add(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	get(s[k<<1],s[k<<1|1],s[k]);
}
void change(int k,int l,int r,int p,int w)
{
	if(l==r)
	{
		s[k].mx=s[k].lmx=s[k].sum=w;
		return ;
	}
	if(ad[k])pushdown(k);
	if(p<=l+r>>1)change(k<<1,l,l+r>>1,p,w);
	else change(k<<1|1,(l+r>>1)+1,r,p,w);
	get(s[k<<1],s[k<<1|1],s[k]);
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		S[a[i]].insert(i);
	}
	build(1,1,n);
	for(int i=1;i<=200000;++i)
		if(S[i].size())
		{
			if(S[i].size()>1)add(1,1,n,*S[i].begin(),*S[i].rbegin()-1,1);
			change(1,1,n,*S[i].begin(),S[i].size());
		}
	printf("%d\n",n-s[1].sum);
	int x,w,y;
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d",&x,&w);
		if(a[x]!=w)
		{
			y=a[x];
			change(1,1,n,*S[y].begin(),0);
			if(S[y].size()>1)add(1,1,n,*S[y].begin(),*S[y].rbegin()-1,-1);
			S[y].erase(x);
			if(S[y].size())
			{
				if(S[y].size()>1)add(1,1,n,*S[y].begin(),*S[y].rbegin()-1,1);
				change(1,1,n,*S[y].begin(),S[y].size());
			}
			if(S[w].size())
			{
				if(S[w].size()>1)add(1,1,n,*S[w].begin(),*S[w].rbegin()-1,-1);
				change(1,1,n,*S[w].begin(),0);
			}
			S[w].insert(x);
			change(1,1,n,*S[w].begin(),S[w].size());
			if(S[w].size()>1)add(1,1,n,*S[w].begin(),*S[w].rbegin()-1,1);
			a[x]=w;
		}
		printf("%d\n",n-s[1].sum);
	}
	cerr<<clock()<<endl;
	return 0;
}