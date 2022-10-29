#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll map[1002][1002];
ll rui[1003][1003];
ll nrui1[2003][2004];
ll nrui2[2003][2004];
int main()
{
	int mx,my,gen;
	scanf("%d%d%d",&mx,&my,&gen);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			scanf("%I64d",&map[i][j]);
			rui[i+1][j+1]=rui[i+1][j]+rui[i][j+1]-rui[i][j]+map[i][j];
			nrui1[i-j+1000][i+1]=nrui1[i-j+1000][i]+map[i][j];
			nrui2[i+j][i+1]=nrui2[i+j][i]+map[i][j];
		}
	}
	ll now=0,maxi=0;
	int nx=gen-1,ny=gen-1;
	for(int i=gen-1;i<=mx-gen;i++)
	{
		now=0;
		for(int j=0;j<gen;j++)
		{
			now+=rui[i+j+1][gen-1+(gen-j-1)+1]-rui[i+j+1][gen-1-(gen-j-1)]-rui[i-j][gen-1+(gen-j-1)+1]+rui[i-j][gen-1-(gen-j-1)];
		}
		ll nowmi=0,nowpl=0;
		for(int j=0;j<gen;j++)
		{
			nowmi+=rui[i+j+1][j+1]-rui[i-j][j+1]-rui[i+j+1][j]+rui[i-j][j];
		}
		for(int j=0;j<gen;j++)
		{
			nowpl+=rui[i+gen-j][gen+j+1]-rui[i+gen-j][gen+j]-rui[i-gen+j+1][gen+j+1]+rui[i-gen+j+1][gen+j];
		}
		if(maxi<now)
		{
			maxi=now;
			nx=i;
			ny=gen-1;
		}
		for(int j=gen;j<=my-gen;j++)
		{
			now-=nowmi;
			now+=nowpl;
			nowmi-=nrui2[i+j-gen][i+1]-nrui2[i+j-gen][i+1-gen]+nrui1[i-j+1000+gen][i+gen]-nrui1[i-j+1000+gen][i+1];
			nowpl+=nrui2[i+j+gen][i+gen]-nrui2[i+j+gen][i]+nrui1[i-j+1000-gen][i]-nrui1[i-j+1000-gen][i+1-gen];
			nowmi+=rui[i+(gen-1)+1][j+1]-rui[i+(gen-1)+1][j]-rui[i-(gen-1)][j+1]+rui[i-(gen-1)][j];
			nowpl-=rui[i+(gen-1)+1][j+1]-rui[i+(gen-1)+1][j]-rui[i-(gen-1)][j+1]+rui[i-(gen-1)][j];
			if(maxi<now)
			{
				maxi=now;
				nx=i;
				ny=j;
			}
		}
	}
	printf("%d %d\n",nx+1,ny+1);
}