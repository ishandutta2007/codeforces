#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#define sqr(x) (x)*(x)
#define len(x) x.length()
using namespace std;
int us[7],used[7],sx,sy,i,j,k;
string ans,st[7];
vector<string> anss;
bool cmp(vector<string> x,vector<string> y)
{
	int i;
	for (i=0;i<min(x.size(),y.size());i++)
	{
		if (x[i]<y[i]) return 1;
		if (x[i]>y[i]) return 0;
	}
	return (x.size()<y.size());
}
void check()
{
	if (st[us[1]][0]!=st[us[2]][0]) return;
	if (st[us[1]][len(st[us[1]])-1]!=st[us[5]][0]) return;
	if (st[us[2]][len(st[us[2]])-1]!=st[us[6]][0]) return;
	if (st[us[5]][len(st[us[5]])-1]!=st[us[3]][0]) return;
	if (st[us[6]][len(st[us[6]])-1]!=st[us[4]][0]) return;
	if (st[us[3]][len(st[us[3]])-1]!=st[us[4]][len(st[us[4]])-1]) return;
	if (len(st[us[1]])+len(st[us[3]])-1!=len(st[us[6]])) return;
	if (len(st[us[2]])+len(st[us[4]])-1!=len(st[us[5]])) return;
	if (st[us[6]][len(st[us[1]])-1]!=st[us[5]][len(st[us[2]])-1]) return;
	string now;
	int x=len(st[us[5]]),y=len(st[us[6]]),i,j,k=0;
	//cerr<<x<<' '<<y<<endl;
	for (i=1;i<=x;i++)
	{
		for (j=1;j<=y;j++)
		{
			now.push_back('.');
			if (i==1&&j<=len(st[us[1]]))
			{
				now[k]=st[us[1]][j-1];
			}
			if (j==1&&i<=len(st[us[2]]))
			{
				now[k]=st[us[2]][i-1];
			}
			if (i==x&&j>y-len(st[us[3]]))
			{
				now[k]=st[us[3]][j+len(st[us[3]])-y-1];
			}
			if (j==y&&i>x-len(st[us[4]]))
			{
				now[k]=st[us[4]][i+len(st[us[4]])-x-1];
			}
			if (j==len(st[us[1]]))
			{
				now[k]=st[us[5]][i-1];
			}
			if (i==len(st[us[2]]))
			{
				now[k]=st[us[6]][j-1];
			}
			k++;
		}
	}
	vector<string> nows;
	for (i=1;i<=x;i++)
	{
		nows.push_back(now.substr((i-1)*y,y));
	}
	if (cmp(nows,anss))
	{
		anss=nows;
		ans=now;
		sx=x;
		sy=y;
	}
}
void dfs(int x)
{
	int i;
	if (x==7) {check();return;}
	for (i=1;i<=6;i++)
	{
		if (!used[i])
		{
			used[i]=1;
			us[x]=i;
			dfs(x+1);
			used[i]=0;
		}
	}
} 
int main()
{
	anss.push_back("{");
	for (j=1;j<=6;j++) cin>>st[j];
	dfs(1);
	//cerr<<sx<<' '<<sy<<endl;
	if (!sx) cout<<"Impossible";
	else
	{
		k=-1;
		for (i=1;i<=sx;i++)
		{
			for (j=1;j<=sy;j++)
			{
				cout<<ans[++k];
			}
			cout<<endl;
		}
	}
	return 0;
}