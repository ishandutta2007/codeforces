#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,w[1010],seq[1010];
bool cmp(int x,int y)
{
	return w[x]>w[y];
}
bool ans[1010][1010];
int id[1010],idtot,stk[1010],stktop;
vector<int> pos[1010];
void split(int x,int y,int k)
{
	if (stk[x]==y)
	{
		for (int i=0;i<stk[x];i++) ans[pos[x][i]][k]=1;
		return;
	}
	stk[++stktop]=y;
	for (int i=1;i<=y;i++)
	{
		ans[pos[x][stk[x]-1]][k]=1;
		id[pos[x][stk[x]-1]]=stktop;
		pos[stktop].push_back(pos[x][stk[x]-1]); pos[x].pop_back();
		stk[x]--;
	}
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	scanf("%d",&n);
	int maxw=0;
	for (int i=1;i<=n;i++) scanf("%d",w+i),seq[i]=i,maxw=max(maxw,w[i]);
	if (maxw==1)
	{
		printf("1\n");
		for (int i=1;i<=n;i++) putchar('1'); putchar('\n');
		return 0;
	}
	sort(seq+1,seq+n+1,cmp);
	if (w[seq[1]]==w[seq[2]])
	{
		stk[++stktop]=1,id[++idtot]=1,ans[1][seq[1]]=1,pos[1].push_back(1);
		stk[++stktop]=1,id[++idtot]=2,ans[2][seq[2]]=1,pos[2].push_back(2);
		stk[++stktop]=w[seq[1]]-1;
		for (int i=1;i<w[seq[1]];i++) id[++idtot]=3,ans[idtot][seq[1]]=ans[idtot][seq[2]]=1,pos[3].push_back(idtot);
	}
	else
	{
		stk[++stktop]=w[seq[1]]-w[seq[2]];
		for (int i=1;i<=w[seq[1]]-w[seq[2]];i++) id[++idtot]=1,ans[idtot][seq[1]]=1,pos[1].push_back(idtot);
		stk[++stktop]=w[seq[2]];
		for (int i=1;i<=w[seq[2]];i++) id[++idtot]=2,ans[idtot][seq[1]]=ans[idtot][seq[2]]=1,pos[2].push_back(idtot);
	}
	for (int i=3;i<=n;i++)
	{
		int maxpos=-1;
		for (int j=1;j<=stktop;j++) if (maxpos==-1||stk[j]>stk[maxpos]) maxpos=j;
		if (stk[maxpos]==1)
		{
			for (int j=1,u=w[seq[i]],v;u&&j<=stktop;j++)
			{
				v=min(u,stk[j]);
				split(j,v,seq[i]);
				u-=v;
			}
			continue;
		}
		int u=w[seq[i]],v=min(stk[maxpos]-1,u);
		split(maxpos,v,seq[i]); u-=v;
		for (int j=1;u&&j<=stktop;j++)
		{
			if (j==maxpos) continue;
			v=min(u,stk[j]);
			split(j,v,seq[i]);
			u-=v;
		}
	}
	printf("%d\n",idtot);
	for (int i=1;i<=idtot;i++,putchar('\n'))
		for (int j=1;j<=n;j++)
			putchar(ans[i][j]?'1':'0');
	return 0;
}