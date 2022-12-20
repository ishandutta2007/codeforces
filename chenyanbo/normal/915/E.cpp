#include<bits/stdc++.h>
#define M 15600000

using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int rt,k,ans,n,q,tot,l,r,s[M],ls[M],rs[M],t[M]; 
void ins(int&p,int l,int r,int x,int y)
{
	if(!p)p=++tot,s[p]=r-l+1;
	if(x<=l&&y>=r)
	{
		t[p]=1;
		s[p]=0;
		return;
	}
	if(t[p]==1)return;
	int mid=(l+r)>>1;
	if(t[p]==0)
	{
		if(!ls[p])ls[p]=++tot;
		if(!rs[p])rs[p]=++tot;
		t[ls[p]]=0;
		t[rs[p]]=0;
		s[ls[p]]=mid-l+1;
		s[rs[p]]=r-mid;
		t[p]=-1;
	}
	if(y<=mid)ins(ls[p],l,mid,x,y);
	else  if(x>mid)ins(rs[p],mid+1,r,x,y);
	else{
		ins(ls[p],l,mid,x,mid);
		ins(rs[p],mid+1,r,mid+1,y);
	}
	s[p]=s[ls[p]]+s[rs[p]];
	if(!ls[p])s[p]+=mid-l+1;
	if(!rs[p])s[p]+=r-mid;
}

void del(int&p,int l,int r,int x,int y)
{
	if(!p)return;
	if(x<=l&&y>=r)
	{
		t[p]=0;
		s[p]=r-l+1;
		return;
	}
	if(t[p]==0)return;
	int mid=(l+r)>>1;
	if(t[p]==1)
	{
		if(!ls[p])ls[p]=++tot;
		if(!rs[p])rs[p]=++tot;
		t[ls[p]]=1;
		t[rs[p]]=1;
		s[ls[p]]=0;
		s[rs[p]]=0;
		t[p]=-1;
	}
	if(y<=mid)del(ls[p],l,mid,x,y);
	else  if(x>mid)del(rs[p],mid+1,r,x,y);
	else{
		del(ls[p],l,mid,x,mid);
		del(rs[p],mid+1,r,mid+1,y);
	}
	s[p]=s[ls[p]]+s[rs[p]];
	if(!ls[p])s[p]+=mid-l+1;
	if(!rs[p])s[p]+=r-mid;
}

int que(int p,int l,int r,int x,int y)
{
	if(!p)return r-l+1;
	if(x<=l&&y>=r)return s[p];
	if(t[p]==0)return r-l+1;
	if(t[p]==1)return 0;
	int mid=(l+r)>>1;
	if(y<=mid)return que(ls[p],l,mid,x,mid);
	if(x>mid)return que(rs[p],mid+1,r,mid+1,y);
	else return que(ls[p],l,mid,x,mid)+que(rs[p],mid+1,r,mid+1,y);
}

int main()
{
//	freopen("1.in","r",stdin);
	n=read(); q=read();
	ans=n;
	s[0]=n;
	while(q--)
	{
		l=read(); r=read(); k=read();
		if(k==2)del(rt,1,n,l,r);
		else ins(rt,1,n,l,r);
		printf("%d\n",s[rt]);
	}
}