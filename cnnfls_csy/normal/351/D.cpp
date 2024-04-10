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
int n,m,i,j,x,y,lst[100005],nxt[100005],lst2[100005],a[100005],ans[100005],arr[100005],arr2[100005];
vector<pair<int,int>/**/> qu[100005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	int i;
	for (i=x;i>0;i-=lowbit(i)) arr[i]+=y;
}
int query(int x)
{
	int i,s=0;
	for (i=x;i<=100000;i+=lowbit(i)) s+=arr[i];
	return s;
}
void add2(int x,int y)
{
	int i;
	for (i=x;i>0;i-=lowbit(i)) arr2[i]+=y;
}
int query2(int x)
{
	int i,s=0;
	for (i=x;i<=100000;i+=lowbit(i)) s+=arr2[i];
	return s;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		nxt[i]=lst[a[i]];
		lst[a[i]]=i;
		if (i-nxt[i]==nxt[i]-nxt[nxt[i]])
		{
			lst2[i]=lst2[nxt[i]];
		}
		else lst2[i]=nxt[nxt[i]];
	}
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		qu[y].push_back(make_pair(i,x));
	}
	for (i=1;i<=n;i++)
	{
		if (nxt[i])
		{
			add(nxt[i],-1);
			add2(lst2[nxt[i]],1);
			add2(nxt[i],-1);
		}
		add(i,1);
		add2(lst2[i],-1);
		add2(i,1);
		for (j=0;j<qu[i].size();j++)
		{
			ans[qu[i][j].first]=query(qu[i][j].second)+(query2(qu[i][j].second)==0);
		}
	}
	for (i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}