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
long long num[100005];
int n,k,i,j,x;
long long ans;
string st1,st2;
void dfs(int start,int dep,int last)
{
	//cerr<<start<<' '<<dep<<' '<<last<<' '<<st1<<endl;
	int i;
	if (dep>k)
	{
		int x=0;
		for (i=0;i<st1.length();i++)
		{
			x=x*2+st1[i]-'0';
		}
		//cerr<<start<<' '<<x<<' '<<num[x]<<endl;
		ans+=num[start]*num[x];
		return;
	}
	//if (last+(k-dep)>n) return;
	for (i=last+1;i<st1.length();i++)
	{
		st1[i]='0'+'1'-st1[i];
		dfs(start,dep+1,i);
		st1[i]='0'+'1'-st1[i];
	}
}
int main()
{
	cin>>n>>k;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		num[x]++;
	}
	if (!k)
	{
		for (i=0;i<=10000;i++)
		{
			ans+=num[i]*(num[i]-1ll)/2ll;
		}
		cout<<ans;
		return 0;
	}
	for (i=0;i<=10000;i++)
	{
		if (!num[i]) continue;
		st1="";
		x=i;
		while (x)
		{
			st1.push_back((x&1)+'0');
			x=x>>1;
		}
		while (st1.length()<=14) st1.push_back('0');
		reverse(st1.begin(),st1.end());
		dfs(i,1,-1);
	}
	cout<<ans/2;
	return 0;
}