#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
string won[9]={"","012","345","678","036","147","258","048","246"},st,st1,name[3]={"","first","second"};
int n,m,i,j,ans,x;
map<int,string> mp;
bool check(int x)
{
	int i,j;
	for (i=1;i<=8;i++)
	{
		if ((x>>((won[i][0]-'0')*2)&3)==(x>>((won[i][1]-'0')*2)&3)&&(x>>((won[i][0]-'0')*2)&3)==(x>>((won[i][2]-'0')*2)&3)&&(x>>((won[i][0]-'0')*2)&3))
		{
			return 1;
		}
	}
	return 0;
}
void dfs(int x,int y)
{
	if (check(x))
	{
		mp[x]="the "+name[3-y]+" player won";
		return;
	}
	if (__builtin_popcount(x)==9)
	{
		mp[x]=="draw";
		return;
	}
	mp[x]=name[y];
	int i;
	for (i=0;i<=8;i++)
	{
		if ((!((1<<(i*2))&x))&&(!((1<<(i*2+1))&x)))
		{
			dfs(x|((1<<(i*2))*y),3-y);
		}
	}
}
int main()
{
	dfs(0,1);
	cin>>st>>st1;
	st+=st1;
	cin>>st1;
	st+=st1;
	for (i=0;i<st.length();i++)
	{
		if (st[i]=='X') x|=1<<(i*2);
		if (st[i]=='0') x|=1<<(i*2+1);
	}
	if (mp.count(x))
	{
	    if (mp[x]=="") cout<<"draw";
	        else cout<<mp[x];
	}
	else cout<<"illegal";
	return 0;
}