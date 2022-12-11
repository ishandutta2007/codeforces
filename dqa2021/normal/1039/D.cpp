#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
const int Block=1350;

int n;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int dfn[100010],fat[100010];  //fat needed?
void dfs1(int cur,int fat)
{
	::fat[cur]=fat;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^fat)
			dfs1(edge[i].to,cur);
	dfn[++*dfn]=cur;
}
int fstmax[100010],secmax[100010];
int dfs2(int Base)
{
	int res=0;
	memset(fstmax+1,0,n*sizeof(int));
	memset(secmax+1,0,n*sizeof(int));
	for (int i=1;i<=n;i++)  //i and dfn_i
	{
		if (fstmax[dfn[i]]+secmax[dfn[i]]+1>=Base) res++;
		else
		{
			fstmax[dfn[i]]++;
			if (fstmax[dfn[i]]>fstmax[fat[dfn[i]]]) secmax[fat[dfn[i]]]=fstmax[fat[dfn[i]]],fstmax[fat[dfn[i]]]=fstmax[dfn[i]];
			else if (fstmax[dfn[i]]>secmax[fat[dfn[i]]]) secmax[fat[dfn[i]]]=fstmax[dfn[i]];
		}
	}
	return res;
}
int main()
{
	n=read();
	for (int i=2;i<=n;i++) addedge(read(),read());
	dfs1(1,0);
	if (n<=Block)
	{
		for (int i=1;i<=n;i++) printf("%d\n",dfs2(i));
		return 0;
	}
	for (int i=1;i<=Block;i++) printf("%d\n",dfs2(i));
	int pos=Block+1;
	while (pos<=n)
	{
		int curans=dfs2(pos);
		/*if (!curans)
		{
			for (int i=pos;i<=n;i++) puts("0");
			break;
		}*/
		int l=pos,r=n,mid;
		while (l<r)
		{
			mid=l+r+1>>1;
			if (dfs2(mid)==curans) l=mid;
			else r=mid-1;
		}
		for (int i=pos;i<=l;i++) printf("%d\n",curans);
		pos=l+1;
	}
	return 0;
}