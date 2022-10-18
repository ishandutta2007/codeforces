#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define lbt(x) ((x)&(-(x)))
using namespace std;
const int MX=101000,inf=0x3f3f3f3f;
int n,l,W;
struct Edge{int to,nxt,w;}e[MX<<1];
struct V{int no,l,w;}v[MX];
int vc;
int hed[MX],ec,vis[MX],vis1[MX];
int cc,cnt[MX],O,mnc,mxs[MX];
int s[MX];
long long ans;

inline bool cmp(V a,V b)
{return a.w<b.w;}
inline void ade(int f,int t,int w)
{e[++ec].to=t;e[ec].nxt=hed[f];hed[f]=ec;e[ec].w=w;}
inline void add(int k,int d)
{if(k==0){s[k]+=d;return;}for(int t=k;t<=n;t+=lbt(t))s[t]+=d;}
inline int que(int k)
{if(k<0)return 0;int tmp=0;for(int t=k;t;t-=lbt(t))tmp+=s[t];return tmp+s[0];}
inline void dfso2(int k)
{
	vis1[k]=1;
	if(max(mxs[k],cc-cnt[k])<mnc)
	{
		O=k;
		mnc=max(mxs[k],cc-cnt[k]);
	}
	for(int i=hed[k];i;i=e[i].nxt)
	{
		if(!vis[e[i].to]&&!vis1[e[i].to])dfso2(e[i].to);
	}
	vis1[k]=0;
}
inline void dfso(int k)
{
	mxs[k]=0;
	cnt[k]=1;cc++;vis1[k]=1;
	for(int i=hed[k];i;i=e[i].nxt)
	{
		if(!vis[e[i].to]&&!vis1[e[i].to])
		{
			dfso(e[i].to);
			cnt[k]+=cnt[e[i].to];
			mxs[k]=max(mxs[k],cnt[e[i].to]);
		}
	}
	vis1[k]=0;
}
inline void geto(int k)
{
	cc=0;
	dfso(k);
	mnc=inf;
	dfso2(k);
}
inline void dfs(int k,int l,int w)
{
	v[++vc]=(V){k,l,w};
	vis1[k]=1;
	for(int i=hed[k];i;i=e[i].nxt)
	{
		if(!vis[e[i].to]&&!vis1[e[i].to])dfs(e[i].to,l+1,w+e[i].w);
	}
	vis1[k]=0;
}
inline int dfs2(int k,int ll,int w)
{
	if(ll>l||w>W)return 0;
	int tmp=1;
	vis1[k]=1;
	for(int i=hed[k];i;i=e[i].nxt)
	{
		if(!vis[e[i].to]&&!vis1[e[i].to])tmp+=dfs2(e[i].to,ll+1,w+e[i].w);
	}
	vis1[k]=0;
	return tmp;
}
inline void work(int k)
{
	geto(k);
	vc=0;
	long long tmp=2*(dfs2(O,0,0)-1);
	vis[O]=1;
	for(int j=hed[O];j;j=e[j].nxt)
	{
		if(!vis[e[j].to])
		dfs(e[j].to,1,e[j].w);
	}
	sort(v+1,v+vc+1,cmp);
	int rt=vc;
	for(int i=1;i<=vc;i++)
	{
		add(v[i].l,1);
	}
	for(int i=1;i<=vc;i++)
	{
		while(rt&&v[i].w+v[rt].w>W){add(v[rt].l,-1);rt--;}
		tmp+=que(l-v[i].l);
	}
	for(;rt;rt--)add(v[rt].l,-1);
	for(int j=hed[O];j;j=e[j].nxt)
	{
		if(vis[e[j].to])continue;
		vc=0;dfs(e[j].to,1,e[j].w);
		sort(v+1,v+vc+1,cmp);
		int rt=vc;
		for(int i=1;i<=vc;i++)
		{
			add(v[i].l,1);
		}
		for(int i=1;i<=vc;i++)
		{
			while(rt&&v[i].w+v[rt].w>W){add(v[rt].l,-1);rt--;}
			tmp-=que(l-v[i].l);
		}
		for(;rt;rt--)add(v[rt].l,-1);
	}
	ans+=tmp;
	for(int i=hed[O];i;i=e[i].nxt)if(!vis[e[i].to])work(e[i].to);
}
int main()
{
	//freopen("tst.in","r",stdin);
	//freopen("tst.out","w",stdout);
	scanf("%d%d%d",&n,&l,&W);
	for(int i=2;i<=n;i++)
	{
		int p,w;
		scanf("%d%d",&p,&w);
		ade(p,i,w);
		ade(i,p,w);
	}
	work(1);
	printf("%I64d",ans>>1);
	return 0;
}