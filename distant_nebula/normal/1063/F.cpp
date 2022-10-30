#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
using std::queue;
using std::vector;
const int N=1000005;
int n;
char s[N];
namespace SAM{
	int nxt[N][26], link[N], len[N], lst, top;
	inline void init(void) { link[0]=-1; }
	void insert(int x)
	{
		int u=++top, p=lst;
		len[u]=len[lst]+1;
		for(; ~p&&!nxt[p][x]; p=link[p]) nxt[p][x]=u;
		if(~p)
		{
			int q=nxt[p][x];
			if(len[q]==len[p]+1) link[u]=q;
			else
			{
				int t=++top;
				std::copy(nxt[q], nxt[q]+26, nxt[t]);
				link[t]=link[q], len[t]=len[p]+1;
				for(;  ~p&&nxt[p][x]==q; p=link[p]) nxt[p][x]=t;
				link[q]=link[u]=t;
			}
		}
		lst=u;
	}
	vector<int> e[N];
	int pa[N][25], in[N], out[N], cnt;
	void dfs(int u, int fa)
	{
//		pa[u][0]=fa;
//		for(int i=1; (1<<i)<=top; ++i) pa[u][i]=pa[pa[u][i-1]][i-1];
		in[u]=++cnt;
		for(int v:e[u]) dfs(v, u);
		out[u]=cnt;
	}
	void build(void)
	{
		for(int i=1; i<=top; ++i) e[link[i]].pb(i);//, printf("link %d %d\n", link[i], i);
		dfs(0, 0);
	}
//	inline int findstr(int x, int l)
//	{
//		for(int i=20; ~i; --i) if(len[pa[x][i]]>=l) x=pa[x][i];
//		return x;
//	}
}
using namespace SAM;
namespace SGT{
	#define lid (id<<1)
	#define rid (id<<1|1)
	int mx[N<<2];
	void upt(int id) { mx[id]=std::max(mx[lid], mx[rid]); }
	void add(int id, int l, int r, int p, int v)
	{
//		if(id==1) printf("add %d %d\n", p, v);
		if(l==r) { mx[id]=std::max(mx[id], v); return; }
		int mid=(l+r)>>1;
		if(p<=mid) add(lid, l, mid, p, v);
		else add(rid, mid+1, r, p, v);
		upt(id);
	}
	int ask(int id, int l, int r, int l1, int r1)
	{
//		if(id==1) printf("ask %d %d\n", l1, r1);
		if(l1<=l&&r<=r1) return mx[id];
		int mid=(l+r)>>1;
		if(r1<=mid) return ask(lid, l, mid, l1, r1);
		else if(l1>mid) return ask(rid, mid+1, r, l1, r1);
		return std::max(ask(lid, l, mid, l1, r1), ask(rid, mid+1, r, l1, r1));
	}
}
using namespace SGT;
int f[N], idx[N], ans;
int main()
{
	scanf("%d%s", &n, s+1);
	std::reverse(s+1, s+n+1);
//	puts(s+1);
	init();
	for(int i=1; i<=n; ++i) insert(s[i]-'a');
	build();
//	printf("nxt %d\n", nxt[0]['c'-'a']);
	for(int i=1, cur=0, cur1=0, l=0; i<=n; ++i)
	{
		cur=nxt[cur][s[i]-'a'];
		++l;
		while(cur&&len[link[cur]]>=l) cur=link[cur];
//		printf("ga %d %d %d %d\n", cur, len[cur], link[cur], len[link[cur]]);
		int curr=len[link[cur]]==l-1?link[cur]:cur;
//		printf("fa %d %d %d %d %d\n", cur, curr, len[cur], link[cur], len[link[cur]]);
		while(l-1>std::max(ask(1, 1, top, in[cur1], out[cur1]), ask(1, 1, top, in[curr], out[curr])))
		{
			--l;
//			puts("dec");
			add(1, 1, top, in[idx[i-l]],  f[i-l]);
			if(cur&&len[link[cur]]>=l) cur=link[cur];
			if(cur1&&len[link[cur1]]>=l-1) cur1=link[cur1];
			curr=len[link[cur]]==l-1?link[cur]:cur;
		}
		cur1=cur;
		f[i]=l;
//		printf("cur %d %d\n", cur, len[cur]);
		ans=std::max(l, ans), idx[i]=cur;
//		printf("%d %d\n", i, l);
	}
	printf("%d\n", ans);
	return 0;
}