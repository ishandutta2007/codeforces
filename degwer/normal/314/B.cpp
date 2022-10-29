#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef pair<int,int>pii;
pii dat[100];
int main()
{
	int na,nb;
	scanf("%d%d",&na,&nb);
	string sa,sb;
	cin>>sa>>sb;
	for(int j=0;j<sb.size();j++)
	{
		int pta=0,ptb=j;
		for(;;)
		{
			if(sa[pta]==sb[ptb])
			{
				pta++;
				ptb++;
				if(ptb==sb.size())
				{
					ptb=0;
					dat[j].first++;
				}
			}
			else
			{
				pta++;
			}
			if(pta==sa.size())
			{
				break;
			}
		}
		dat[j].second=ptb;
	}
	int ans=0;
	int np=0;
	for(int i=0;i<na;i++)
	{
		ans+=dat[np].first;
		np=dat[np].second;
	}
	printf("%d\n",ans/nb);
}