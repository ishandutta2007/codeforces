#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ch[100010][2],tot,siz[100010],f[100010];
long long w[100010],ad[100010];
#define pushup(x) siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1
#define pushdown(x) w[ch[x][0]]+=ad[x],w[ch[x][1]]+=ad[x],ad[ch[x][0]]+=ad[x],ad[ch[x][1]]+=ad[x],ad[x]=0
void print()
{
	for(int i=1;i<=tot;++i)printf("%d %d %d %d %lld %lld\n",ch[i][0],ch[i][1],f[i],siz[i],w[i],ad[i]);
	printf("\n");
}
void rotate(int x,int &to)
{
	int y=f[x],z=f[y],s=ch[x][ch[y][0]==x];
	ch[z][ch[z][1]==y]=x;f[x]=z;
	ch[x][ch[y][0]==x]=y;f[y]=x;
	ch[y][ch[y][1]==x]=s;f[s]=y;
	pushup(y);
}
void splay(int x,int &to)
{
	int y,z;
	while(x!=to)
	{
		y=f[x],z=f[y];
		if(y!=to)rotate((ch[z][0]==y)^(ch[y][0]==x)?x:y,to);
		rotate(x,to);
	}
	pushup(x);
}
int findl(int x)
{
	if(ad[x])pushdown(x);
	while(ch[x][0])
	{
		x=ch[x][0];
		if(ad[x])pushdown(x);
	}
	return x;
}
long long dp[100010],cnt,ans;
void dfs(int v)
{
	if(ad[v])pushdown(v);
	if(ch[v][0])dfs(ch[v][0]);
	dp[++cnt]=w[v];
	if(ch[v][1])dfs(ch[v][1]);
}
int n,a[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ch[0][1]=tot=1;
	for(int i=1;i<=n;++i)
	{
		int p=ch[0][1],ret,sz=0;
		while(p)
		{
			if(ad[p])pushdown(p);
			if(w[p]>=1ll*(sz+siz[ch[p][0]])*a[i])ret=p,sz+=siz[ch[p][0]]+1,p=ch[p][1];
			else p=ch[p][0];
		}
	//	printf("%d\n",ret);
		splay(ret,ch[0][1]);
		w[ch[ret][1]]+=a[i];
		ad[ch[ret][1]]+=a[i];
		++tot;siz[tot]=1;
		w[tot]=1ll*(siz[ch[ret][0]]+1)*a[i];
		if(ch[ret][1])
		{
			splay(findl(ch[ret][1]),ch[ret][1]);
	//		print();
			f[tot]=ch[ret][1];ch[ch[ret][1]][0]=tot;
			pushup(ch[ret][1]);pushup(ret);
		}
		else
		{
			f[tot]=ret;ch[ret][1]=tot;
			pushup(ret);
		}
	/*	}
		else
		{
			w[rt]+=a[i],ad[rt]+=a[i];
			++tot;siz[tot]=1;
			w[tot]=a[i];
			ch[tot][1]=rt;f[rt]=tot;rt=tot;
			pushup(tot);
		}*/
	//	print();
	}
	dfs(ch[0][1]);
	for(int i=2;i<=cnt;++i)dp[i]+=dp[i-1];
	for(int i=1;i<=cnt;++i)ans=max(ans,dp[i]);
	printf("%lld",ans);
	return 0;
}