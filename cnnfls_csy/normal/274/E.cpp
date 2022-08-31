#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
set<pair<int,int> > all,in[200005],in2[200005];
set<pair<pair<int,int>,pair<int,int> > > vis;
int n,m,k,i,j,x,y,ax,ay,lx,ly,sx,sy;
long long ans;
string st;
pair<pair<int,int>,pair<int,int> > getnxt(pair<pair<int,int>,pair<int,int> > lst)
{
	int x=lst.first.first,y=lst.first.second,ax=lst.second.first,ay=lst.second.second;
	int lx=x,ly=y;
	if (ax*ay==1)
	{
		if (ax==1)
		{
			pair<int,int> nxt=*in2[x-y+100002].lower_bound(make_pair(x,y));
			ans+=abs(x-nxt.first)-1;
			x=nxt.first-1;
			y=nxt.second-1;
			if (all.count(make_pair(nxt.first-1,nxt.second))^all.count(make_pair(nxt.first,nxt.second-1)))
			{
				if (all.count(make_pair(nxt.first-1,nxt.second))) {ay=-ay;x++;}
					else {ax=-ax;y++;}
				ans++;
			}
			else
			{
				ay=-ay;
				ax=-ax;
			}
		}
		else
		{
			pair<int,int> nxt=*(--in2[x-y+100002].lower_bound(make_pair(x,y)));
			ans+=abs(x-nxt.first)-1;
			x=nxt.first+1;
			y=nxt.second+1;
			if (all.count(make_pair(nxt.first+1,nxt.second))^all.count(make_pair(nxt.first,nxt.second+1)))
			{
				if (all.count(make_pair(nxt.first+1,nxt.second))) {ay=-ay;x--;}
					else {ax=-ax;y--;}
				ans++;
			}
			else
			{
				ay=-ay;
				ax=-ax;
			}
		}
	}
	else
	{
		if (ax==-1)
		{
			pair<int,int> nxt=*(--in[x+y].lower_bound(make_pair(x,y)));	
			ans+=abs(x-nxt.first)-1;
			x=nxt.first+1;
			y=nxt.second-1;
			if (all.count(make_pair(nxt.first+1,nxt.second))^all.count(make_pair(nxt.first,nxt.second-1)))
			{
				if (all.count(make_pair(nxt.first+1,nxt.second))) {ay=-ay;x--;}
					else {ax=-ax;y++;}
				ans++;
			}
			else
			{
				ay=-ay;
				ax=-ax;
			}
		}
		else
		{
			pair<int,int> nxt=*in[x+y].lower_bound(make_pair(x,y));
			ans+=abs(x-nxt.first)-1;
			x=nxt.first-1;
			y=nxt.second+1;
			if (all.count(make_pair(nxt.first-1,nxt.second))^all.count(make_pair(nxt.first,nxt.second+1)))
			{
				if (all.count(make_pair(nxt.first-1,nxt.second))) {ay=-ay;x++;} 
					else {ax=-ax;y--;}
				ans++;
			}
			else
			{
				ay=-ay;
				ax=-ax;
			}
		}
	}
	return make_pair(make_pair(x,y),make_pair(ax,ay));
}
bool getans(pair<pair<int,int>,pair<int,int> > sta)
{
	while (!vis.count(sta))
	{
		vis.insert(sta);
		pair<pair<int,int>,pair<int,int> > nxt=getnxt(sta);
		if (sta.second.first==-nxt.second.first&&sta.second.second==-nxt.second.second) return 0;
		sta=nxt;
	}
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (i=0;i<=n+1;i++)
	{
		in[i].insert(make_pair(i,0));
		in2[i+100002].insert(make_pair(i,0));
		all.insert(make_pair(i,0));
		in[i+m+1].insert(make_pair(i,m+1));
		in2[i-m-1+100002].insert(make_pair(i,m+1));
		all.insert(make_pair(i,m+1));
	}
	for (i=1;i<=m;i++)
	{
		in[i].insert(make_pair(0,i));
		in2[100002-i].insert(make_pair(0,i));
		all.insert(make_pair(0,i));
		in[i+n+1].insert(make_pair(n+1,i));
		in2[n+1-i+100002].insert(make_pair(n+1,i));
		all.insert(make_pair(n+1,i));
	}
	for (i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		in[x+y].insert(make_pair(x,y));
		in2[x-y+100002].insert(make_pair(x,y));
		all.insert(make_pair(x,y));
	}
	scanf("%d%d",&x,&y);
	cin>>st;
	if (((int)st.find("N"))!=-1) ax=-1;
		else ax=1;
	if (((int)st.find("W"))!=-1) ay=-1;
		else ay=1;
	pair<pair<int,int>,pair<int,int> > sta=getnxt(make_pair(make_pair(x,y),make_pair(ax,ay)));
	int t=ans;
	ans=0;
	if (getans(sta)); //ans+=t;
	else
	{
		sta.second.first=-sta.second.first;
		sta.second.second=-sta.second.second; 
		getans(sta);
		ans++;
	}
	cout<<ans;
	return 0;
}