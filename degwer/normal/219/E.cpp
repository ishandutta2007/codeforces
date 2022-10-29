#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int>pii;
int dist[200000];
int park[1000001];
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	set<pii>se;
	set<pii>par;
	fill(park,park+1000001,-1);
	for(int p=0;p<query;p++)
	{/*
		set<pii>::iterator it=par.begin();
		printf("debug ");
		for(;;)
		{
			if(it==par.end())
			{
				break;
			}
			pii zan=*it;
			it++;
			printf("%d %d   ",zan.first,zan.second);
		}
		printf("\n");
		it=se.begin();
		printf("debug ");
		for(;;)
		{
			if(it==se.end())
			{
				break;
			}
			pii zan=*it;
			it++;
			printf("%d %d   ",zan.first,zan.second);
		}
		printf("\n");*/
		int za,zb;
		scanf("%d%d",&za,&zb);
		if(za==1)
		{
			set<pii>::iterator it;
			if(par.empty())
			{
				par.insert(make_pair(0,zb));
				printf("1\n");
				park[zb]=0;
				continue;
			}
			if(par.size()==1)
			{
				it=par.begin();
				pii zan=*it;
				if(zan.first>=num-zan.first-1)
				{
					par.insert(make_pair(0,zb));
					dist[0]=zan.first;
					se.insert(make_pair(zan.first,0));
					park[zb]=0;
					printf("1\n");
				}
				else
				{
					par.insert(make_pair(num-1,zb));
					dist[zan.first]=num-1-zan.first;
					se.insert(make_pair(num-1-zan.first,zan.first));
					park[zb]=num-1;
					printf("%d\n",num);
				}
				continue;
			}
			it=par.begin();
			pii zan=*it;
			int maxi=zan.first;
			int nn=0;
			int hab=zan.first;
			int flag=-1;
			it=se.end();
			it--;
			zan=*it;
			it=se.lower_bound(make_pair(zan.first,-1));
			pii zan2=*it;
			if(maxi<zan2.first/2)
			{
				maxi=zan2.first/2;
				nn=zan2.second;
				hab=zan2.first;
				flag=0;
			}
			if(zan.first%2==1)
			{
				it=se.lower_bound(make_pair(zan.first-1,-1));
				zan2=*it;
				if(maxi==zan2.first/2)
				{
					if(nn>zan2.second)
					{
						nn=zan2.second;
						hab=zan2.first;
						flag=0;
					}
				}
				if(maxi<zan2.first/2)
				{
					maxi=zan2.first/2;
					nn=zan2.second;
					hab=zan2.first;
					flag=0;
				}
			}
			it=par.end();
			it--;
			zan=*it;
			if(maxi<num-1-zan.first)
			{
				maxi=num-1-zan.first;
				nn=zan.first;
				hab=zan.first;
				flag=1;
			}
			it=se.lower_bound(make_pair(hab,nn));
			if(flag==-1)
			{
				se.insert(make_pair(maxi,0));
				par.insert(make_pair(0,zb));
				park[zb]=0;
				printf("1\n");

			}
			if(flag==1)
			{
				se.insert(make_pair(maxi,nn));
				par.insert(make_pair(nn+maxi,zb));
				park[zb]=num-1;
				printf("%d\n",num);
			}
			if(flag==0)
			{
				par.insert(make_pair(nn+maxi,zb));
				zan=*it;
				se.erase(it);
				se.insert(make_pair(maxi,zan.second));
				se.insert(make_pair(zan.first-maxi,nn+maxi));
				park[zb]=nn+maxi;
				printf("%d\n",nn+maxi+1);
			}
		}
		else
		{
			set<pii>::iterator it=par.lower_bound(make_pair(park[zb],-1));
			pii zan=*it;
			if(par.size()==1)
			{
				par.clear();
				se.clear();
				continue;
			}
			if(it==par.begin())
			{
				par.erase(it);
				it=par.begin();
				pii zan2=*it;
				it=se.lower_bound(make_pair(zan2.first-zan.first,zan.first));
				se.erase(it);
				continue;
			}
			it++;
			if(it==par.end())
			{
				it--;
				it--;
				pii zan2=*it;
				it++;
				par.erase(it);
				it=se.lower_bound(make_pair(zan.first-zan2.first,zan2.first));
				se.erase(it);
				continue;
			}
			it--;
			it--;
			pii zan2=*it;
			it++;
			it++;
			pii zan3=*it;
			it--;
			par.erase(it);
			it=se.lower_bound(make_pair(zan3.first-zan.first,zan.first));
			set<pii>::iterator it2=se.lower_bound(make_pair(zan.first-zan2.first,zan2.first));
			se.erase(it2);
			se.erase(it);
			se.insert(make_pair(zan3.first-zan2.first,zan2.first));
		}
	}
}