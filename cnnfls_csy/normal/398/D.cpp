#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,q,o,i,j,quan[50005],ex[150005],ey[150005],x,y,z,cnt[50005],ans;
bool onl[50005];
vector<int> bi[50005];
char op;
int main()
{
	scanf("%d%d%d%d",&n,&m,&q,&o);
	for (i=1;i<=o;i++)
	{
		scanf("%d",&z);
		onl[z]=1;
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&ex[i],&ey[i]);
		quan[ex[i]]--;quan[ey[i]]--;
	}
	for (i=1;i<=m;i++)
	{
		x=ex[i];y=ey[i];
		if (quan[x]<quan[y]) swap(x,y);
		if (quan[x]==quan[y]&&x<y) swap(x,y);
		bi[x].push_back(y);
		if (onl[x]) cnt[y]++;
	}
	for (i=1;i<=q;i++)
	{
		scanf(" %c",&op);
		if (op=='O')
		{
			scanf("%d",&x);
			onl[x]=1;
			for (j=0;j<bi[x].size();j++) cnt[bi[x][j]]++;
		}
		if (op=='F')
		{
			scanf("%d",&x);
			onl[x]=0;
			for (j=0;j<bi[x].size();j++) cnt[bi[x][j]]--;
		}
		if (op=='A')
		{
			scanf("%d%d",&x,&y);
			if (quan[x]<quan[y]) swap(x,y);
			if (quan[x]==quan[y]&&x<y) swap(x,y);
			bi[x].push_back(y);
			if (onl[x]) cnt[y]++;
		}
		if (op=='D')
		{
			scanf("%d%d",&x,&y);
			if (quan[x]<quan[y]) swap(x,y);
			if (quan[x]==quan[y]&&x<y) swap(x,y);
			for (vector<int>::iterator it=bi[x].begin();it!=bi[x].end();it++)
			{
				if (*it==y)
				{
					bi[x].erase(it);
					break;
				}
			}
			if (onl[x]) cnt[y]--;
		}
		if (op=='C')
		{
			scanf("%d",&x);
			ans=cnt[x];
			for (j=0;j<bi[x].size();j++) if (onl[bi[x][j]]) ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}