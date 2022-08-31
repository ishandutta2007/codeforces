#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
struct ii
{
	int sc,jin,mi;
}team[205];
int n,m,i,j,k,ranks,s1,s2,t1,t2,cnt[205],len,mi=1<<25,mx,my;
string ch1,ch2;
vector<string> s;
bool check(int x,int y)
{
	if (x==y)
	{
		return 0;
	}
	if (team[x].sc!=team[y].sc)
	{
		return team[x].sc>team[y].sc;
	}
	if (team[x].mi!=team[y].mi)
	{
		return team[x].mi>team[y].mi;
	}
	if (team[x].jin!=team[y].jin)
	{
		return team[x].jin>team[y].jin;
	}
	return s[x]<s[y];
}
int get(string st)
{
	int i;
	for (i=0;i<s.size();i++)
	{
		if (s[i]==st) return i;
	}
	s.push_back(st);
	return s.size()-1;
}
int main()
{
	for (i=1;i<=5;i++)
	{
		cin>>ch1>>ch2;
		s1=get(ch1);
		s2=get(ch2);
		cnt[s1]++;
		cnt[s2]++;
		scanf("%d:%d:",&t1,&t2);
		team[s1].mi+=t1-t2;
		team[s2].mi+=t2-t1;
		team[s1].jin+=t1;
		team[s2].jin+=t2;
		if (t1>t2) team[s1].sc+=3;
		if (t1<t2) team[s2].sc+=3;
		if (t1==t2)
		{
			team[s1].sc++;
			team[s2].sc++;
		}
	}
	for (i=0;i<=3;i++)
	{
		if (s[i]=="BERLAND")
		{
			s1=i;
		}
		else if (cnt[i]<3)
		{
			s2=i;
		}
	}
	for (i=1;i<=100;i++)
	{
		for (j=0;j<i;j++)
		{
			team[s1].mi+=i-j;
			team[s2].mi+=j-i;
			team[s1].jin+=i;
			team[s2].jin+=j;
			if (i>j) team[s1].sc+=3;
			if (i<j) team[s2].sc+=3;
			if (i==j)
			{
				team[s1].sc++;
				team[s2].sc++;
			}
			ranks=1;
			for (k=0;k<=3;k++)
			{
				if (check(k,s1)) ranks++;
			}
			if (ranks<=2)
			{
				/*cout<<i<<':'<<j;
				return 0;*/
				if (i-j<mi)
				{
					mx=i;
					my=j;
					mi=i-j;
				}
			}
			team[s1].mi-=i-j;
			team[s2].mi-=j-i;
			team[s1].jin-=i;
			team[s2].jin-=j;
			if (i>j) team[s1].sc-=3;
			if (i<j) team[s2].sc-=3;
			if (i==j)
			{
				team[s1].sc--;
				team[s2].sc--;
			}
		}
	}
	if (mi<(1<<24))
	{
		cout<<mx<<':'<<my;
		return 0;
	}
	cout<<"IMPOSSIBLE";
	return 0;
}