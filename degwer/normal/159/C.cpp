#include<stdio.h>
#include<string>
#include<iostream>
#include<deque>
#include<algorithm>
#include<vector>
using namespace std;
int toint(char alpha)
{
	return alpha-97;
}
char tochar(int num)
{
	return num+97;
}
int main()
{
	int connect;
	scanf("%d",&connect);
	string str;
	cin>>str;
	vector<vector<deque<int> > >vec;
	vector<deque<int> >damy;
	vector<int>damy2;
	deque<int>damy3;
	vector<vector<int> >veccut;
	for(int j=1;j<=26;j++)
	{
		vec.push_back(damy);
		veccut.push_back(damy2);
	}
	vector<pair<char,int> >veczan;
	for(int i=1;i<=connect;i++)
	{
		for(int k=1;k<=str.size();k++)
		{
			veczan.push_back(make_pair(str[k-1],veczan.size()));
		}
	}
	for(int l=1;l<=veczan.size();l++)
	{
		char moji=veczan[l-1].first;
		int numarr=veczan[l-1].second;
		veccut[toint(moji)].push_back(numarr);
	}
	for(int m=0;m<=25;m++)
	{
		int nowmoji=0;
		for(int n=1;n<=veccut[m].size();n++)
		{
			if(nowmoji%100==0)
			{
				vec[m].push_back(damy3);
			}
			nowmoji++;
			vec[m][vec[m].size()-1].push_back(veccut[m][n-1]);
		}
		vec[m].push_back(damy3);
	}
	int quely;
	scanf("%d",&quely);
	for(int o=1;o<=quely;o++)
	{
		int delnum;
		char delalpha;
		scanf("%d %c",&delnum,&delalpha);
		delnum--;
		if(vec[toint(delalpha)][delnum/100].size()>=2)
		{
			for(int p=delnum%100;p<=vec[toint(delalpha)][delnum/100].size()-2;p++)
			{
				vec[toint(delalpha)][delnum/100][p]=vec[toint(delalpha)][delnum/100][p+1];
			}
		}
		vec[toint(delalpha)][delnum/100].pop_back();
		for(int q=1;;q++)
		{
			if(vec[toint(delalpha)][delnum/100+q].empty()==false)
			{
				int zan=vec[toint(delalpha)][delnum/100+q][0];
				vec[toint(delalpha)][delnum/100+q].pop_front();
				vec[toint(delalpha)][delnum/100+q-1].push_back(zan);
			}
			else
			{
				break;
			}
		}
	}
	vector<pair<int,int> >vecret;
	for(int r=0;r<=25;r++)
	{
		for(int s=1;s<=vec[r].size();s++)
		{
			for(int t=1;t<=vec[r][s-1].size();t++)
			{
				vecret.push_back(make_pair(vec[r][s-1][t-1],r));
			}
		}
	}
	sort(vecret.begin(),vecret.end());
	for(int u=1;u<=vecret.size();u++)
	{
		printf("%c",tochar(vecret[u-1].second));
	}
	printf("\n");
}