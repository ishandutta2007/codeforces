#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;
long long n,a,b,x,y;
vector<long long> ans;

int main()
{
	cin>>n>>a>>b;
	x=-1;
	y=-1;
	int flag=0;
	for(long long i=0;i*a<=n;i++)
		if((n-i*a)%b==0)
		{
			x=i;
			y=(n-i*a)/b;
			flag=1;
		}
	if(!flag){ puts("-1"); return 0; }
	long long now=1;
	ans.clear();
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=a;j++)ans.push_back(now+j%a);
		now+=a;
	}
	for(int i=1;i<=y;i++)
	{
		for(int j=1;j<=b;j++)ans.push_back(now+j%b);
		now+=b;
	}
	int cnt=ans.size();
	for(int i=0;i<cnt;i++)printf("%lld%c",ans[i],i==cnt-1?'\n':' ');
}