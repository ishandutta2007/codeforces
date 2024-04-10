#include<bits/stdc++.h>
using namespace std;
int x,n,k,vis[(1<<19)+5];
vector<int>mi[(1<<19)+5],mx[(1<<19)+5],midis[(1<<19)+5];
const int inf=1e9;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		vis[x]=1;
	}
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<(1<<k);j++)
		{
			//printf("@@%d %d %d\n",j,(1<<k),j&((1<<i)-1));
			//if(j==(1<<k)&&i<k)continue;
			if(j&((1<<i)-1))continue;
			//printf("%d %d\n",i,j);
			mi[j].resize(1<<i);mx[j].resize((1<<i));midis[j].resize(1<<i);
			if(i==0)
			{
				if(vis[j])mi[j][0]=mx[j][0]=0,midis[j][0]=inf;
				else mi[j][0]=inf,mx[j][0]=-inf,midis[j][0]=inf;
				continue;
			}
			else
			{
				vector<int>mil,mxl,midisl;
				int l=j;int r=j+(1<<(i-1));
				mil=mi[l];mxl=mx[l];midisl=midis[l];
				int tmp=1<<(i-1);
				for(int k=0;k<(1<<(i-1));k++)
				{
					mi[j][k]=min(mil[k],mi[r][k]+tmp);
					mx[j][k]=max(mxl[k],mx[r][k]+tmp);
					midis[j][k]=min(midisl[k],min(midis[r][k],tmp+mi[r][k]-mxl[k]));
				}
				for(int k=0;k<tmp;k++)
				{
					mi[j][k+tmp]=min(mil[k]+tmp,mi[r][k]);
					mx[j][k+tmp]=max(mxl[k]+tmp,mx[r][k]);
					midis[j][k+tmp]=min(midisl[k],min(midis[r][k],tmp+mil[k]-mx[r][k]));
				}
				vector<int>().swap(mi[r]);
				vector<int>().swap(mx[r]);
				vector<int>().swap(midis[r]);
			}
			//printf("#%d %d %d\n",i,j,k);
		}
		//printf("!%d %d\n",i,k);
	}
	//printf("$");
	for(int i=0;i<(1<<k)-1;i++)printf("%d ",midis[0][i]);
	printf("%d\n",midis[0][(1<<k)-1]);
	return 0;
}