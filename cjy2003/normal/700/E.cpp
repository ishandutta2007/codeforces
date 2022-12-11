#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
namespace seg
{
	int tot,ch[10000000][2],sum[10000000];
	void ins(int &k,int l,int r,int p)
	{
		if(!k)k=++tot;
		++sum[k];
		if(l==r)return;
		if(p<=l+r>>1)ins(ch[k][0],l,l+r>>1,p);
		else ins(ch[k][1],(l+r>>1)+1,r,p);
	}
	int merge(int x,int y,int l,int r)
	{
		if(!x||!y)return x+y;
		int k=++tot;
		sum[k]=sum[x]+sum[y];
		if(l==r)return k;
		ch[k][0]=merge(ch[x][0],ch[y][0],l,l+r>>1);
		ch[k][1]=merge(ch[x][1],ch[y][1],(l+r>>1)+1,r);
		return k;
	}
	int query(int k,int l,int r,int ll,int rr)
	{
		if(l>rr||r<ll||!k)return 0;
		if(l>=ll&&r<=rr)return sum[k];
		return query(ch[k][0],l,l+r>>1,ll,rr)+query(ch[k][1],(l+r>>1)+1,r,ll,rr);
	}
}
int n,ans;
char s[200020];
int ch[400040][26],f[400040],len[400040],ed=1,tot=1,rt[400040],pos[400040],cnt[400040],dy[400040];
void extend(int c,int id)
{
	int p=ed;ed=++tot;len[ed]=len[p]+1;dy[ed]=id;
	seg::ins(rt[ed],1,n,id);
	while(p&&!ch[p][c])ch[p][c]=ed,p=f[p];
	if(!p){f[ed]=1;return;}
	int q=ch[p][c];
	if(len[p]+1==len[q]){f[ed]=q;return;}
	int nq=++tot;len[nq]=len[p]+1;
	memcpy(ch[nq],ch[q],sizeof(ch[q]));
	f[nq]=f[q],f[q]=nq,f[ed]=nq;
	while(ch[p][c]==q)ch[p][c]=nq,p=f[p];
}
vector<int>E[400040];
void dfs(int v)
{
	for(auto u:E[v])
	{
		dfs(u);
		if(!dy[v])dy[v]=dy[u];
		rt[v]=seg::merge(rt[v],rt[u],1,n);
	}
}
void dfs1(int v)
{
	if(v>1)
	{
		if(f[v]==1)cnt[v]=1,pos[v]=v;
		else if(seg::query(rt[pos[f[v]]],1,n,dy[v]-len[v]+len[pos[f[v]]],dy[v]-1))cnt[v]=cnt[f[v]]+1,pos[v]=v;
		else cnt[v]=cnt[f[v]],pos[v]=pos[f[v]];
		ans=max(ans,cnt[v]);
	}
	for(auto u:E[v])dfs1(u);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)extend(s[i]-'a',i);
	for(int i=2;i<=tot;++i)E[f[i]].push_back(i);
	dfs(1);
	dfs1(1);
	printf("%d",ans);
	return 0;
}