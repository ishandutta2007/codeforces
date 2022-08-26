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
int n,m,i,j,x[200005],y[200005],ans,op[200005],tx[900005],ty[900005],cnt;
char ss[15];
vector<pair<int,int>/**/> all;
void add(int z,int x,int y,int c,int l,int r)
{
	if (z==c)
	{
		tx[z]=x;ty[z]=y;
		return;
	}
	if (c-262144<(l+r)/2) add(z*2,x,y,c,l,(l+r)/2); else add(z*2+1,x,y,c,(l+r)/2+1,r);
	tx[z]=max(tx[z*2],tx[z*2+1]);
	ty[z]=max(ty[z*2],ty[z*2+1]);
}
void del(int z,int x,int y,int c,int l,int r)
{
	if (z==c)
	{
		tx[z]=ty[z]=0;
		return;
	}
	if (c-262144<(l+r)/2) del(z*2,x,y,c,l,(l+r)/2); else del(z*2+1,x,y,c,(l+r)/2+1,r);
	tx[z]=max(tx[z*2],tx[z*2+1]);
	ty[z]=max(ty[z*2],ty[z*2+1]);
}
int getans(int z,int x,int y)
{
	if (tx[z]<x||ty[z]<y) return -1;
	if (z>=262144) return z;
	int ans=getans(2*z,x,y);
	if (ans!=-1) return ans;
		else return getans(2*z+1,x,y);
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%s%d%d",&ss,x+i,y+i);
		if (ss[0]=='a') op[i]=1;
		if (ss[0]=='r') op[i]=2;
		if (ss[0]=='f') op[i]=3;
		if (op[i]!=3) all.push_back(make_pair(x[i],y[i]));
	}
	if (!all.empty())
	{
		vector<pair<int,int>/**/> all2;
		sort(all.begin(),all.end());
		all2.push_back(all[0]);
		for (i=1;i<all.size();i++) if (all[i]!=all[i-1]) all2.push_back(all[i]);
		all=all2;
	}
	for (i=1;i<=n;i++)
	{
		if (op[i]==1)
		{
			add(1,x[i],y[i],262144+(upper_bound(all.begin(),all.end(),make_pair(x[i],y[i]))-all.begin()),1,262144);
		}
		if (op[i]==2)
		{
			del(1,x[i],y[i],262144+(upper_bound(all.begin(),all.end(),make_pair(x[i],y[i]))-all.begin()),1,262144);
		}
		if (op[i]==3)
		{
			ans=getans(1,x[i]+1,y[i]+1);
			if (ans==-1) printf("%d\n",ans);
				else printf("%d %d\n",tx[ans],ty[ans]);
		}
	}
	return 0;
}