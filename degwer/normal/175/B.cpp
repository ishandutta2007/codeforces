#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int nin;
	scanf("%d",&nin);
	vector<pair<string,int> >read;
	for(int i=0;i<nin;i++)
	{
		string za;
		int zb;
		cin>>za;
		scanf("%d",&zb);
		read.push_back(make_pair(za,zb));
	}
	sort(read.begin(),read.end());
	vector<int>vec;
	vector<pair<string,int> >hoge;
	string now="";
	for(int j=0;j<read.size();j++)
	{
		if(now!=read[j].first)
		{
			hoge.push_back(read[j]);
			now=read[j].first;
		}
		else
		{
			hoge[hoge.size()-1].second=max(hoge[hoge.size()-1].second,read[j].second);
		}
	}
	read=hoge;
	for(int k=0;k<read.size();k++)
	{
		vec.push_back(read[k].second);
	}
	sort(vec.begin(),vec.end());
	sort(read.begin(),read.end());
	int peo=read.size();
	printf("%d\n",peo);
	for(int l=0;l<peo;l++)
	{
		cout<<read[l].first<<" ";
		int upp=upper_bound(vec.begin(),vec.end(),read[l].second)-vec.begin();
		if(upp*2<peo)
		{
			printf("noob\n");
			continue;
		}
		if(upp*5<peo*4)
		{
			printf("random\n");
			continue;
		}
		if(upp*10<peo*9)
		{
			printf("average\n");
			continue;
		}
		if(upp*100<peo*99)
		{
			printf("hardcore\n");
			continue;
		}
		printf("pro\n");
	}
}