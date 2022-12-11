#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}
void print(int x)
{
	if (x>9) print(x/10); putchar(x%10+48);
}
const int INF=0x7fffffff;

int n;
struct Edge{
	int to,nxt,val;
}edge[500010];
int cnt,last[500010];
inline void addedge(int x,int y,int v)
{
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
}
int dp[500010];
int cc[(1<<22)+10],vrn[(1<<22)+10],tim=1;
int mrk1,mrk2;   //xor val
int siz[500010],son[500010][2],dep[500010];
int rec[500010][2],rectop;  //rectop=0
void dfs1(int cur,int dep)
{
	siz[cur]=1; ::dep[cur]=dep;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		dfs1(edge[i].to,dep+1);
		siz[cur]+=siz[edge[i].to];
		if (!son[cur][0]||siz[son[cur][0]]<siz[edge[i].to]) son[cur][0]=edge[i].to,son[cur][1]=edge[i].val;
	}
}
int &c(int x)
{
	if (vrn[x]!=tim) vrn[x]=tim,cc[x]=-INF;
	return cc[x];
}
void dfs3(int cur,int rt,int cond)
{
	rec[++rectop][0]=cond,rec[rectop][1]=dep[cur]-dep[rt];   //first is rec[][0] not rec[][1]
	for (int i=last[cur];i;i=edge[i].nxt)
		dfs3(edge[i].to,rt,cond^(1<<edge[i].val));
}
void dfs2(int cur)
{
//	printf("dfs2 %d\n",cur);
	if (siz[cur]==1) return tim++,c(0)=0,mrk1=mrk2=0,void();  //ok to return?  ok  //tim++,mrk1=mrk2=0
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=son[cur][0]) dfs2(edge[i].to),dp[cur]=max(dp[cur],dp[edge[i].to]);
	dfs2(son[cur][0]); dp[cur]=max(dp[cur],dp[son[cur][0]]);
	mrk1^=(1<<son[cur][1]); mrk2++;
//	printf("cc for %d:\n",cur);
//	for (int i=0;i<4;i++) printf("%d for %d+%d\n",i,c(i^mrk1),mrk2); puts("");
	if (c(mrk1)!=-INF) dp[cur]=max(dp[cur],c(mrk1)+mrk2);
	for (int i=0;i<22;i++) if (c((1<<i)^mrk1)!=-INF) dp[cur]=max(dp[cur],c((1<<i)^mrk1)+mrk2);
	c(mrk1)=max(c(mrk1),-mrk2);
//	printf("cc for %d:\n",cur);
//	for (int i=0;i<4;i++) printf("%d for %d+%d\n",i,c(i^mrk1),mrk2); puts("");
	for (int u=last[cur];u;u=edge[u].nxt)  //u not i
		if (edge[u].to!=son[cur][0])
		{
			rectop=0;
			dfs3(edge[u].to,cur,(1<<edge[u].val));
			for (int i=1;i<=rectop;i++)
			{
//				printf("find cond %d val %d\n",rec[i][0],rec[i][1]);
				if (c(rec[i][0]^mrk1)!=-INF) dp[cur]=max(dp[cur],c(rec[i][0]^mrk1)+mrk2+rec[i][1]);
				for (int j=0;j<22;j++) if (c(rec[i][0]^(1<<j)^mrk1)!=-INF) dp[cur]=max(dp[cur],c(rec[i][0]^(1<<j)^mrk1)+mrk2+rec[i][1]);
			}
			for (int i=1;i<=rectop;i++) c(rec[i][0]^mrk1)=max(c(rec[i][0]^mrk1),rec[i][1]-mrk2);
		}
//	printf("cc for %d:\n",cur);
//	for (int i=0;i<4;i++) printf("%d for %d+%d\n",i,c(i^mrk1),mrk2); puts("");
}

int main()
{
	read(n);
	char str[3];
	for (int i=2,x;i<=n;i++)
	{
		read(x);scanf("%s",str);
		addedge(x,i,str[0]-'a');
	}
	dfs1(1,1); dfs2(1);
	for (int i=1;i<n;i++) print(dp[i]),putchar(' '); print(dp[n]),putchar('\n');
	return 0;
}