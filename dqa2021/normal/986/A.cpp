#include<cstdio>
#include<algorithm>
using namespace std;
char ch;
void read(int &x)
{
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for (x=0;ch<='9'&&ch>='0';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
}
int n,m,s,k;
int a;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt,last[100010];
void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
struct Node{
	int to,nxt;
}node[100010];
int cnt2,last2[110];
void addnode(int x,int y)
{node[++cnt2]=(Node){y,last2[x]},last2[x]=cnt2;}
int que[100010],hd,tl;
int res[100010][110];
void bfs(int x)
{
	hd=tl=0;
	for (int i=1;i<=n;i++) res[i][x]=-1;
	for (int i=last2[x];i;i=node[i].nxt) res[node[i].to][x]=0,que[++tl]=node[i].to;
	while (hd<tl)
	{
		hd++;
		for (int i=last[que[hd]];i;i=edge[i].nxt)
			if (res[edge[i].to][x]==-1)
			{
				que[++tl]=edge[i].to;
				res[que[tl]][x]=res[que[hd]][x]+1;
			}
	}
}
int main()
{
	int x,y,ans;
	read(n);read(m);read(k);read(s);
	for (int i=1;i<=n;i++) read(a),addnode(a,i);
	while (m--)
	{
		read(x);read(y);
		addedge(x,y);
	}
	for (int i=1;i<=k;i++) bfs(i);
	for (int i=1;i<=n;i++)
	{
		nth_element(res[i]+1,res[i]+s,res[i]+k+1);
		ans=0;
		for (int j=1;j<=s;j++) ans+=res[i][j];
		printf("%d",ans),putchar(i==n?'\n':' ');
	}
	return 0;
}