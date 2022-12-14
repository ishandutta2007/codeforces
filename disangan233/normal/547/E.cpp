#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 400005
int len[N],fa[N],ch[N][26],rt[N],pos[N],f[N];
char str[N];
int cnt=1,n,Q;
int insert(int c,int las)
{
	int p=las,np=++cnt;
	len[np]=len[p]+1;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p) fa[np]=1;
	else
	{
		int q=ch[p][c];
		if(len[p]+1==len[q]) fa[np]=q;
		else
		{
			int nq=++cnt; len[nq]=len[p]+1;
			memcpy(ch[nq],ch[q],26*4);
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
	return np;
}
struct Node{int ls,rs,v;};
struct Query{int l,r,id;};
int ans[N];
Node t[N*39];
vector<int> G[N];
vector<Query> q[N];
int _cnt;
void update(int &u,int l,int r,int p)
{
	if(!u) u=++_cnt;
	// printf("%d %d %d %d\n",u,l,r,p);
	if(l==r) {t[u].v++;  return ;}
	int mid=(l+r)/2;
	if(p<=mid) update(t[u].ls,l,mid,p);
	else update(t[u].rs,mid+1,r,p);
	t[u].v=t[t[u].ls].v+t[t[u].rs].v;
}
int query(int u,int l,int r,int L,int R)
{
	if(!u) return 0;
	if(L<=l&&r<=R) return t[u].v;
	int mid=(l+r)/2,ans=0;
	if(L<=mid) ans+=query(t[u].ls,l,mid,L,R);
	if(R>mid) ans+=query(t[u].rs,mid+1,r,L,R);
	return ans;
}
int merge(int u,int v)
{
	if(!u&&!v) return 0;
	if(!v) return u;
	if(!u)
	{
		int x=++_cnt;
		t[x]=t[v];
		return x;
	}
	int x=++_cnt;
	t[x].v=t[u].v+t[v].v;
	t[x].ls=merge(t[u].ls,t[v].ls);
	t[x].rs=merge(t[u].rs,t[v].rs);
	return x;
}
void dfs(int u)
{
	// printf("%d %d\n",u,f[u]);
	for(int v:G[u])
	{
		if(len[u]==len[v]) f[v]=f[u];
		else f[v]=v;
		dfs(v); rt[u]=merge(rt[u],rt[v]);
	}
}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str); int len=strlen(str);
		// printf("%s %d\n",str,len);
		int las=1;
		for(int j=0;j<len;j++) las=insert(str[j]-'a',las),update(rt[las],1,n,i);;
		pos[i]=las;
	}
	// for(int i=1;i<=cnt;i++) printf("%d %d\n",i,fa[i]);
	for(int i=2;i<=cnt;i++) G[fa[i]].pb(i);
	f[1]=1;
	dfs(1);
	while(Q--)
	{
		int u=read(),v=read(),w=read();
		printf("%d\n",query(rt[f[pos[w]]],1,n,u,v));
	}
	return 0;
}