#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[100010];
struct Edge{
	int to,nxt;
}edge[100010];
int cnt,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int rec[100010];

int main()
{
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d%d",&x,w+i);
		if (~x) addedge(x,i);
	}
	for (int i=1;i<=n;i++)
	{
		if (!w[i]) continue;
		bool flg=true;
		for (int j=last[i];j;j=edge[j].nxt) if (!w[edge[j].to]) flg=false;
		if (flg) rec[++*rec]=i;
	}
	if (*rec)
	{
		for (int i=1;i<(*rec);i++) printf("%d ",rec[i]); printf("%d\n",rec[*rec]);
	}
	else puts("-1");
	return 0;
}