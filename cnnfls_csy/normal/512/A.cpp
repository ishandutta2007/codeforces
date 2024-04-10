#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
vector<int> bi[1005],ans;
int n,m,i,j,rd[1005],x,y;
string st[1005];
queue<int> nord;
void make(string x,string y)
{
	if (x==y)
	{
		cout<<"Impossible";
		exit(0);
	}
	if (x.length()>y.length()&&x.substr(0,y.length())==y)
	{
		cout<<"Impossible";
		exit(0);
	}
	if (y.length()>x.length()&&y.substr(0,x.length())==x)
	{
		return;
	}
	int i=0;
	while (x[i]==y[i]) i++;
	bi[x[i]-'a'+1].push_back(y[i]-'a'+1);
	rd[y[i]-'a'+1]++;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st[i];
	}
	for (i=1;i<=n;i++)
	{
		for (j=i+1;j<=n;j++)
		{
			make(st[i],st[j]);
		}
	}
	for (i=1;i<=26;i++)
	{
		if (!rd[i])
		{
			nord.push(i);
		}
	}
	while (!nord.empty())
	{
		x=nord.front();
		nord.pop();
		ans.push_back(x);
		for (i=0;i<bi[x].size();i++)
		{
			rd[bi[x][i]]--;
			if (!rd[bi[x][i]])
			{
				nord.push(bi[x][i]);
			}
		}
	}
	if (ans.size()!=26)
	{
		cout<<"Impossible";
		return 0;
	}
	for (i=0;i<ans.size();i++) cout<<char(ans[i]+'a'-1);
	return 0;
}