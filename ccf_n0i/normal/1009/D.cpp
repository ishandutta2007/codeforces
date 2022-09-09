#include <bits/stdc++.h>
using namespace std;
vector<int> priss;
set<set<int> > s;
set<int> ss;
int notaprime[70005];
int main()
{
vector<pair<int,int> > edg;
int i,j;
	int vsz,esz;	cin>>vsz>>esz;
	if (esz+1<vsz)	{		puts("Impossible");
		return 0;
	}	
	priss.push_back(1);if (vsz>7000){for (i=2;i<=6000;i++)
	{		if (notaprime[i]) continue;		priss.push_back(i);		for (j=i+i;j<=6000;j+=i)
		{
			notaprime[j]=1;		}
	}
	for (i=0;i<priss.size();i++){		for (j=priss[i]+1;j<=vsz;j++)		{
			if (__gcd(priss[i],j)==1)
					edg.push_back(make_pair(priss[i],j));
							if (edg.size()>esz) break;		}				if (edg.size()>esz) break;
	}	
	if (edg.size()<esz) puts("Impossible");	else
	{		puts("Possible");		for (i=0;i<esz;i++) printf("%d %d\n",edg[i].first,edg[i].second);
	}	return 0;		}
	
	for (i=1;i<=vsz;i++)		{			for (j=i+1;j<=vsz;j++)			{
				if (__gcd(i,j)==1){
					edg.push_back(make_pair(i,j));			
			}if (edg.size()>=esz) break;
				if (edg.size()>=esz) break;		}}
			//	if (edg.size()<esz) return 1; 
		if (edg.size()<esz) puts("Impossible");		else		{			puts("Possible");
			for (i=0;i<esz;i++) printf("%d %d\n",edg[i].first,edg[i].second);		}
		return 0;
	
}