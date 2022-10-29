#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<ll,pii>pi3;
typedef pair<ll,pi3>pi4;
ll dist[51][51][2];
ll ans[51][51][2];
ll com[52][52];
ll mod=1000000007;
void calccom()
{
	com[0][0]=1;
	for(int i=1;i<=50;i++)
	{
		com[i][0]=com[i][i]=1;
		for(int j=1;j<i;j++)
		{
			com[i][j]=com[i-1][j-1]+com[i-1][j];
			com[i][j]%=mod;
		}
	}
}
int main()
{
	int num,gen;
	scanf("%d%d",&num,&gen);
	gen/=50;
	calccom();
	int numa=0,numb=0;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		if(zan==50)
		{
			numa++;
		}
		else
		{
			numb++;
		}
	}
	queue<pi4>que;
	for(int i=0;i<=num;i++)
	{
		for(int j=0;j<=num;j++)
		{
			dist[i][j][0]=dist[i][j][1]=-1;
			ans[i][j][0]=ans[i][j][1]=0;
		}
	}
	que.push(make_pair(0,make_pair(0,make_pair(numa,numb))));
	dist[numa][numb][0]=0;
	ans[numa][numb][0]=1;
	for(;;)
	{
		if(que.empty())
		{
			break;
		}
		pi4 zan=que.front();
		que.pop();
		for(int i=0;i<=zan.second.second.first;i++)
		{
			for(int j=0;j<=zan.second.second.second;j++)
			{
				if(i+j==0)
				{
					continue;
				}
				if(i+j*2>gen)
				{
					break;
				}
				int nea=numa-zan.second.second.first+i,neb=numb-zan.second.second.second+j,nes=zan.second.first^1;
				if(dist[nea][neb][nes]==-1||dist[nea][neb][nes]==zan.first+1)
				{
					if(dist[nea][neb][nes]==-1)
					{
						que.push(make_pair(zan.first+1,make_pair(nes,make_pair(nea,neb))));
					}
					dist[nea][neb][nes]=zan.first+1;
					ans[nea][neb][nes]+=((ans[zan.second.second.first][zan.second.second.second][zan.second.first]*com[zan.second.second.first][i])%mod)*com[zan.second.second.second][j];
					ans[nea][neb][nes]%=mod;
				}
			}
		}
	}
	printf("%I64d\n%I64d\n",dist[numa][numb][1],ans[numa][numb][1]);
}