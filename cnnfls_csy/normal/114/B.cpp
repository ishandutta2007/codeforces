#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
map<string,int> mp;
int hate[25][25],n,m,i,j,ma,ms,x;
string st1,st2,name[25];
vector<string> ans;
int geshu(int n) 
{
	int s=0;
	while (n) 
	{
		s+=n&1;
		n=n>>1;
	}
	return s;
}
bool check(int x)
{
	int i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (hate[i][j]&&((x>>(i-1))&1)&&(x>>(j-1))&1) return 0;
		}
	}
	return 1;
} 
int main()
{ 
	cin>>n>>m;
	memset(hate,0,sizeof(hate));
	for (i=1;i<=n;i++) 
	{
		cin>>st1;
		mp[st1]=i;
		name[i]=st1;
	}
	for (i=1;i<=m;i++)
	{
		cin>>st1>>st2;
		hate[mp[st1]][mp[st2]]=1;
		hate[mp[st2]][mp[st1]]=1;
	}
	/*
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cerr<<hate[i][j];
		}
		cerr<<endl;
	}*/
	for (i=0;i<(1<<n);i++)
	{
		if (check(i)&&geshu(i)>ma)
		{
			ma=geshu(i);
			ms=i;
		}
	} 
	cout<<ma<<endl;
	//cerr<<ms<<endl;
	x=1;
	while (ms) 
	{
		if (ms&1) ans.push_back(name[x]);
		x++;
		ms=ms>>1;
	}
	sort(ans.begin(),ans.end());
	for (i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}