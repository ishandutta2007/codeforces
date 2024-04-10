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
int n,a,b,i,j,fa[100005],hi[100005],num[100005],x,y,zh,can[100005],cnt;
map<int,int> mp;
int find(int x)
{
	if (fa[x]==x) return x;
	return find(fa[x]);
}
void hebing(int x,int y)
{
	x=find(x);
	y=find(y);
	if (hi[x]>hi[y]) fa[y]=x;
		else fa[x]=y;
	if (hi[x]==hi[y]) hi[x]++;
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>a>>b;
	for (i=1;i<=n;i++)
	{
		fa[i]=i;
		cin>>num[i];
		if (!mp.count(num[i])) mp[num[i]]=i;
	}
	for (i=1;i<=n;i++)
	{
		if (mp.count(a-num[i]))
		{
			hebing(i,mp[a-num[i]]);
			can[i]|=1;
		}
		if (mp.count(b-num[i]))
		{
			hebing(i,mp[b-num[i]]);
			can[i]|=2;
		}
	}
	for (i=1;i<=n;i++) can[find(i)]&=can[i];
	for (i=1;i<=n;i++) 
	{
		if (!can[find(i)])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for (i=1;i<=n;i++)
	{
		if (can[find(i)]==1) cout<<0<<' ';
			else cout<<1<<' ';
	}
	return 0;
}