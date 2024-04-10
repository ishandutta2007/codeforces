#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int data,time;
	scanf("%d%d",&data,&time);
	vector<pair<int,pair<string,string> > >vec;
	vector<pair<string,string> >ret;
	for(int i=1;i<=data;i++)
	{
		string sa,sb;
		int jik;
		cin>>sa;
		cin>>sb;
		scanf("%d",&jik);
		vec.push_back(make_pair(jik,make_pair(sa,sb)));
		for(int j=1;j<=vec.size()-1;j++)
		{
			if(vec[j-1].second.first==sb&&vec[j-1].second.second==sa&&vec[j-1].first+time>=jik&&vec[j-1].first!=jik)
			{
				ret.push_back(make_pair(sa,sb));
				ret.push_back(make_pair(sb,sa));
			}
		}
	}
	sort(ret.begin(),ret.end());
	pair<string,string>now=make_pair("","");
	vector<pair<string,string> >hre;
	for(int k=1;k<=ret.size();k++)
	{
		if(ret[k-1]!=now&&ret[k-1].first<=ret[k-1].second)
		{
			hre.push_back(ret[k-1]);
		}
		now=ret[k-1];
	}
	printf("%d\n",hre.size());
	for(int l=1;l<=hre.size();l++)
	{
		cout<<hre[l-1].first<<" "<<hre[l-1].second<<endl;
	}
}