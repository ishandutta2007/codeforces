#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
typedef pair<int,pii>pi3;
typedef pair<pii,pii>piiv;
vector<piiv>get(vector<pi3>v,bool f)
{
	int g=1;
	for(int i=0;i<v.size();i++)g*=3;
	vector<piiv>ret;
	for(int p=0;p<g;p++)
	{
		int sa=0,sb=0,sc=0;
		vector<int>z;
		int now=p;
		for(int i=0;i<v.size();i++)
		{
			z.push_back(now%3);
			now/=3;
		}
		for(int i=0;i<v.size();i++)
		{
			if(z[i]==0)
			{
				sb+=v[i].second.first;
				sc+=v[i].second.second;
			}
			if(z[i]==1)
			{
				sa+=v[i].first;
				sc+=v[i].second.second;
			}
			if(z[i]==2)
			{
				sb+=v[i].second.first;
				sa+=v[i].first;
			}
		}
		if(f)ret.push_back(make_pair(make_pair(sb-sa,sc-sb),make_pair(-sa,p)));
		else ret.push_back(make_pair(make_pair(sa-sb,sb-sc),make_pair(-sa,p)));
	}
	sort(ret.begin(),ret.end());
	return ret;
}
int main()
{
	int num;
	scanf("%d",&num);
	vector<pi3>va,vb;
	for(int i=0;i<num/2;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		va.push_back(make_pair(za,make_pair(zb,zc)));
	}
	for(int i=num/2;i<num;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		vb.push_back(make_pair(za,make_pair(zb,zc)));
	}
	vector<piiv>a=get(va,true),b=get(vb,false);
	//for(int i=0;i<a.size();i++)printf("%d %d\n",a[i].first.first,a[i].first.second);
	int maxi=-1000000000;
	int r1=-1,r2=-1;
	for(int i=0;i<a.size();i++)
	{
		int low=lower_bound(b.begin(),b.end(),make_pair(a[i].first,make_pair(-1000000000,0)))-b.begin();
		if(low==b.size())continue;
		if(a[i].first==b[low].first)
		{
			if(maxi<-(a[i].second.first+b[low].second.first))
			{
				maxi=-a[i].second.first-b[low].second.first;
				r1=i,r2=low;
			}
		}
	}
	if(r1==-1)printf("Impossible\n");
	else
	{
		int now=a[r1].second.second;
		for(int j=0;j<va.size();j++)
		{
			if(now%3==0)printf("MW\n");
			if(now%3==1)printf("LW\n");
			if(now%3==2)printf("LM\n");
			now/=3;
		}
		now=b[r2].second.second;
		for(int j=0;j<vb.size();j++)
		{
			if(now%3==0)printf("MW\n");
			if(now%3==1)printf("LW\n");
			if(now%3==2)printf("LM\n");
			now/=3;
		}
	}
}