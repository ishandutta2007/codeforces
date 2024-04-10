#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,ch[150050][2];
char a[150050];
int dis[150050],dep[150050],siz[150050],f[150050],mx[26][150050],c[150050],zson[150050],id[150050],tp[150050],dy[150050],idnum;
int cnt[26];
bool flag;
void dfs1(int v)
{
	dep[v]=dep[f[v]]+1;siz[v]=1;
	if(ch[v][0])
	{
		dfs1(ch[v][0]);
		for(int i=0;i<26;++i)mx[i][v]=mx[i][ch[v][0]]+(a[ch[v][0]]=='a'+i);
	}
	if(ch[v][1])
	{
		dfs1(ch[v][1]);
		for(int i=0;i<26;++i)mx[i][v]=max(mx[i][v],mx[i][ch[v][1]]+(a[ch[v][1]]=='a'+i));
	}
	zson[v]=siz[ch[v][0]]>=siz[ch[v][1]]?0:1;
	if(ch[v][0]&&ch[v][1]&&dis[ch[v][0]]!=dis[ch[v][1]])flag=1;
	if(ch[v][0])dis[v]=dis[ch[v][0]]+1;
}
void dfs2(int v,int topp)
{
	tp[v]=topp;id[v]=++idnum;dy[idnum]=v;
	if(ch[v][zson[v]])dfs2(ch[v][zson[v]],topp);
	if(ch[v][zson[v]^1])dfs2(ch[v][zson[v]^1],ch[v][zson[v]^1]);
}
struct seg
{
	int mi[600060],ad[600060];
	void build(int k,int l,int r)
	{
		if(l==r)return mi[k]=c[dy[l]],void();
		build(k<<1,l,(l+r)>>1);
		build(k<<1|1,((l+r)>>1)+1,r);
		mi[k]=min(mi[k<<1],mi[k<<1|1]);
	}
	void pushdown(int k)
	{
		mi[k<<1]+=ad[k],mi[k<<1|1]+=ad[k];
		ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k];
		ad[k]=0;
	}
	void add(int k,int l,int r,int ll,int rr,int w)
	{
		// if(k==1)printf("add:%d %d %d\n",ll,rr,w);
		if(l>rr||r<ll)return;
		if(l>=ll&&r<=rr)return mi[k]+=w,ad[k]+=w,void();
		if(ad[k])pushdown(k);
		add(k<<1,l,(l+r)>>1,ll,rr,w);
		add(k<<1|1,((l+r)>>1)+1,r,ll,rr,w);
		mi[k]=min(mi[k<<1],mi[k<<1|1]);
	}
	int qry(int k,int l,int r,int p)
	{
		if(l==r)return mi[k];
		if(ad[k])pushdown(k);
		if(p<=(l+r)>>1)return qry(k<<1,l,(l+r)>>1,p);
		else return qry(k<<1|1,((l+r)>>1)+1,r,p);
	}
	int findmx(int k,int l,int r,int ll,int rr)
	{
		// printf("%d %d %d %d %d %d\n",k,l,r,ll,rr,mi[k]);
		if(l==r)return mi[k]<=0?l:0;
		if(ad[k])pushdown(k);
		if(l>=ll&&r<=rr)
		{
			if(mi[k<<1|1]>0)return findmx(k<<1,l,(l+r)>>1,ll,rr);
			else return findmx(k<<1|1,((l+r)>>1)+1,r,ll,rr);
		}
		if(ll>(l+r)>>1)return findmx(k<<1|1,((l+r)>>1)+1,r,ll,rr);
		if(rr<=(l+r)>>1)return findmx(k<<1,l,(l+r)>>1,ll,rr);
		int cur=findmx(k<<1|1,((l+r)>>1)+1,r,ll,rr);
		if(cur)return cur;
		return findmx(k<<1,l,(l+r)>>1,ll,rr);
	}
	int findmi(int k,int l,int r,int ll,int rr)
	{
		if(l==r)return mi[k]<0?l:0;
		if(ad[k])pushdown(k);
		if(l>=ll&&r<=rr)
		{
			if(mi[k<<1|1]>=0)return findmi(k<<1,l,(l+r)>>1,ll,rr);
			else return findmi(k<<1|1,((l+r)>>1)+1,r,ll,rr);
		}
		if(ll>(l+r)>>1)return findmi(k<<1|1,((l+r)>>1)+1,r,ll,rr);
		if(rr<=(l+r)>>1)return findmi(k<<1,l,(l+r)>>1,ll,rr);
		int cur=findmi(k<<1|1,((l+r)>>1)+1,r,ll,rr);
		if(cur)return cur;
		return findmi(k<<1,l,(l+r)>>1,ll,rr);
	}
}t[27];
void upd(int x,int ch,int opt)
{
	if(opt==1)
	{
		while(x>1)
		{
			int w=tp[x]!=x?t[ch].findmi(1,1,n,id[tp[x]],id[x]-1):0;
			// printf("findmi:%d\n",w);
			if(w)
			{
				// printf("%d %d\n",w+1,id[x]-1);
				t[26].add(1,1,n,w+1,id[x]-1,-1);
				t[ch].add(1,1,n,w,id[x]-1,1);
				break;
			}
			// printf("%d %d\n",id[tp[x]],id[x]-1);
			t[26].add(1,1,n,id[tp[x]],id[x]-1,-1);
			t[ch].add(1,1,n,id[tp[x]],id[x]-1,1);
			if(tp[x]==1)++cnt[ch];
			int y=f[tp[x]];
			if(!y)break;
			if(t[ch].qry(1,1,n,id[y])<=0)
			{
				t[ch].add(1,1,n,id[y],id[y],-1);
				t[26].add(1,1,n,id[y],id[y],-1);
				if(y==1)++cnt[ch];
			}
			else
			{
				t[ch].add(1,1,n,id[y],id[y],-1);
				break;
			}
			x=y;
		}
	}
	else
	{
		while(x>1)
		{
			int w=tp[x]!=x?t[ch].findmx(1,1,n,id[tp[x]],id[x]-1):0;
			if(w)
			{
				// printf("%d %d\n",w+1,id[x]-1);
				t[26].add(1,1,n,w+1,id[x]-1,1);
				t[ch].add(1,1,n,w,id[x]-1,-1);
				break;
			}
			// printf("red %d %d\n",id[tp[x]],id[x]-1);
			t[26].add(1,1,n,id[tp[x]],id[x]-1,1);
			t[ch].add(1,1,n,id[tp[x]],id[x]-1,-1);
			if(tp[x]==1)--cnt[ch];
			int y=f[tp[x]];
			if(!y)break;
			// printf("%d %d\n",y,t[ch].qry(1,1,n,id[y]));
			if(t[ch].qry(1,1,n,id[y])<0)
			{
				// printf("!!!\n");
				t[ch].add(1,1,n,id[y],id[y],1);
				t[26].add(1,1,n,id[y],id[y],1);
				if(y==1)--cnt[ch];
			}
			else
			{
				t[ch].add(1,1,n,id[y],id[y],1);
				break;
			}
			x=y;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=2,x;i<=n;++i)
	{
		scanf("%d %c",&x,&a[i]);
		f[i]=x;
		ch[x][ch[x][0]!=0]=i;
	}
	dfs1(1);
	if(flag)
	{
		while(q--)puts("Fou");
		return 0;
	}
	dfs2(1,1);
	// for(int i=1;i<=n;++i)printf("%d ",tp[i]);printf("\n");
	for(int i=0;i<26;++i)
	{
		for(int j=1;j<=n;++j)c[j]=mx[i][ch[j][zson[j]]]+(a[ch[j][zson[j]]]=='a'+i)-mx[i][ch[j][zson[j]^1]]-(a[ch[j][zson[j]^1]]=='a'+i);
		cnt[i]=mx[i][1];
		t[i].build(1,1,n);
	}
	for(int i=1;i<=n;++i)
	{
		c[i]=dis[i];
		for(int j=0;j<26;++j)c[i]-=mx[j][i];
	}
	t[26].build(1,1,n);
	int x;
	char ch;
	while(q--)
	{
		scanf("%d %c",&x,&ch);
		if(a[x]>='a')upd(x,a[x]-'a',-1);
		a[x]=ch;
		if(a[x]>='a')upd(x,a[x]-'a',1);
	// 	for(int i=0;i<26;++i)printf("%d ",cnt[i]);printf("\n");
		if(t[26].mi[1]<0)puts("Fou");
		else
		{
			int ans=0,w=t[26].qry(1,1,n,1);
			for(int i=0;i<26;++i)ans+=(i+1)*(cnt[i]+w);
			printf("Shi %d\n",ans);
		}
	}
	return 0;
}