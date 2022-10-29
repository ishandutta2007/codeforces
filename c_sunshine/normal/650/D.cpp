#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
inline void readi(int &x);
const int maxn=400005;
int n,m,Q;
int a[maxn],v[maxn];
int prel[maxn],prer[maxn],len[maxn],cnt[maxn],bes;
int ans[maxn],lp[maxn],rp[maxn];

int t[maxn],tl[maxn],tr[maxn];

vector<int> id[maxn],c[maxn];

void add(int x,int i)
{
	for(;x<=m;x+=x&-x)
		if(len[i]>t[x])
		{
			t[x]=len[i];
			tl[x]=tr[x]=i;
		}
		else if(len[i]==t[x])
		{
			tl[x]=min(tl[x],i);
			tr[x]=max(tr[x],i);
		}
}

int get(int x,int &l,int &r)
{
	int s=0;l=r=0;
	for(;x;x^=x&-x)
		if(t[x]>s)
		{
			s=t[x];
			l=tl[x],r=tr[x];
		}
		else if(t[x]==s)
			l=min(l,tl[x]),r=max(r,tr[x]);
	return s;
}

void Add(int x,int c)
{
	for(;x<=m;x+=x&-x)
		t[x]=max(t[x],c);
}

int Get(int x)
{
	int s=0;
	for(;x;x^=x&-x)
		s=max(s,t[x]);
	return s;
}

void dfsl(int x)
{
	if(!x)return;
	cnt[x]++;
	dfsl(prel[x]);
}
void dfsr(int x)
{
	if(!x)return;
	cnt[x]++;
	dfsr(prer[x]);
}

int main()
{
	readi(n),readi(Q);
	for(int i=1;i<=n;i++)
		readi(a[i]),v[i]=a[i];
	sort(v+1,v+n+1);
	m=unique(v+1,v+n+1)-v-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(v+1,v+m+1,a[i])-v;
	memset(tl,31,m+1<<2);
	for(int i=1;i<=n;i++)
	{
		bes=max(bes,len[i]=get(a[i]-1,prel[i],prer[i])+1);
		add(a[i],i);
	}
	for(int i=1;i<=n;i++)
		if(len[i]==bes)
			{dfsl(i);break;}
	for(int i=n;i>0;i--)
		if(len[i]==bes)
			{dfsr(i);break;}
	for(int i=1;i<=n;i++)
		if(cnt[i]==2)
			cnt[i]=bes-1;
			else cnt[i]=bes;
	for(int x,y,i=1;i<=Q;i++)
	{
		readi(x),readi(y);
		id[x].push_back(i);
		c[x].push_back(y);
		ans[i]=cnt[x];
	}
	memset(t,0,m+1<<2);
	for(int i=1;i<=n;i++)
	{
		int k;
		for(int j=0;j<c[i].size();j++)
		{
			k=lower_bound(v+1,v+m+1,c[i][j])-v-1;
			lp[id[i][j]]=Get(k);
		}
		k=Get(a[i]-1)+1;
		Add(a[i],k);
	}
	memset(t,0,m+1<<2);
	for(int i=n;i>0;i--)
	{
		int k;
		for(int j=0;j<c[i].size();j++)
		{
			k=upper_bound(v+1,v+m+1,c[i][j])-v;
			rp[id[i][j]]=Get(m-k+1);
		}
		k=Get(m-a[i])+1;
		Add(m-a[i]+1,k);
	}
	for(int i=1;i<=Q;i++)
		printf("%d\n",max(ans[i],lp[i]+rp[i]+1));
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}