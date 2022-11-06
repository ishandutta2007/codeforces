#include<bits/stdc++.h>
using namespace std;

int n,a[500010],q[500010],cnt,w[500010],c[500010];
pair<int,int> pa[500010];
char s[3];

struct node
{
	bool bo;
	long long val;
	int l,r;
	long long mi;
}t[1200010];

const long long inf=1000000000000000000ll;

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].val=0,t[i].bo=0,t[i].mi=inf;
	if (l==r) {t[i].val=-w[l]; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

void pushdown(int i)
{
	if (!t[i].val) return;
	t[i<<1].mi+=t[i].val,t[i<<1|1].mi+=t[i].val;
	t[i<<1].val+=t[i].val,t[i<<1|1].val+=t[i].val;
	t[i].val=0;
}

void change(int i,int x)
{
	if (t[i].l==t[i].r)
	{
		t[i].bo^=1;
		if (t[i].bo) t[i].mi=t[i].val;
		else t[i].mi=inf;
		return;
	}
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	change(i<<1|(x>mid),x);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
}

void add(int i,int l,int r,long long v)
{
	if (t[i].l==l&&t[i].r==r)
	{
		t[i].val+=v,t[i].mi+=v;
		return;
	}
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	if (r<=mid) add(i<<1,l,r,v); else
	if (l>mid) add(i<<1|1,l,r,v); else
	add(i<<1,l,mid,v),add(i<<1|1,mid+1,r,v);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
}

int findmi(int i)
{
	if (t[i].l==t[i].r) return 1;
	pushdown(i);
	int ans=0;
	if (t[i<<1].mi<0) ans+=findmi(i<<1);
	if (t[i<<1|1].mi<0) ans+=findmi(i<<1|1);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) 
	{
		scanf("%s",s),scanf("%d",&pa[i].first),pa[i].second=i;
		q[i]=(s[0]=='+'?1:-1);
	}
	sort(pa+1,pa+1+n),cnt=0;
	for (int i=1; i<=n; i++)
	{
		if (i==1||pa[i].first!=pa[i-1].first) cnt++,w[cnt]=pa[i].first;
		q[pa[i].second]*=cnt;
	}
	memset(c,0,sizeof(c));
	build(1,1,cnt);
	int tot=0;
	for (int i=1; i<=n; i++)
	{
		if (q[i]>0) 
		{
			c[q[i]]++,tot++; 
			if (c[q[i]]==1) change(1,q[i]);
			if (q[i]!=cnt) add(1,q[i]+1,cnt,2*w[q[i]]);
		} else 
		{
			q[i]=-q[i];
			c[q[i]]--,tot--;
			if (c[q[i]]==0) change(1,q[i]);
			if (q[i]!=cnt) add(1,q[i]+1,cnt,-2*w[q[i]]);
		}
		int ans=tot-(t[1].mi<0?findmi(1):0);
		printf("%d\n",ans);
	}
	return 0;
}