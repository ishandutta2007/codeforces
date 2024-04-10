#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
long long x,y,z,n,i,j,e,t1,t2,s,ss,Max,Min=2147480000;
string st;
vector<long long> a,b,c,d;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	cin>>x>>y>>z>>n;
	if (n==0) {cout<<0<<' '<<0; return 0;}
	for (i=1;i<=n;i++)
	{
		scanf("%d ",&e);
		getline(cin,st);
		if (st[0]=='U')
		a.push_back(e);
		else 
		b.push_back(e);
	}
	//cout<<a.size()<<' '<<b.size();
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	if (!a.empty())
	c.push_back(a[0]);
	if (!b.empty())
	d.push_back(b[0]);
	if (!a.empty())
	for (i=1;i<a.size();i++)
	{
		c.push_back(c[i-1]+a[i]);
	}
	if (!b.empty())
	for (i=1;i<b.size();i++)
	{
		d.push_back(d[i-1]+b[i]);
	}
	if (!a.empty())
	for (i=0;i<=min((long long)a.size(),x+z);i++)
	{
		if (!b.empty())
		j=min((long long)(b.size()),min(x+z-i+y,y+z));
		else j=0;
		if (i+j>Max)
		{
			Max=i+j;
			if (!i&&!j) Min=0;
			else if (!i) Min=d[j-1];
			else if (!j) Min=c[i-1];
			else Min=c[i-1]+d[j-1];
		}
		else if (i+j==Max)
		{
			if (!i&&!j) Min=0;
			else if (!i) Min=min(Min,d[j-1]);
			else if (!j) Min=min(Min,c[i-1]);
			else Min=min(Min,c[i-1]+d[j-1]);
		}
	}
	else 
	{
		i=0;
		j=min((long long)(b.size()),min(x+z-i+y,y+z));
		if (i+j>Max)
		{
			Max=i+j;
			if (!i&&!j) Min=0;
			Min=d[j-1];
		}
		else if (i+j==Max)
		{
			if (!i&&!j) Min=0;
			else Min=min(Min,d[j-1]);
		}
	}
	cout<<Max<<' '<<Min;
	return 0;
}