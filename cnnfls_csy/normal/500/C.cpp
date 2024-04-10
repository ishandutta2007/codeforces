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
long long n,m,i,j,ans,cnt[505],zl[505],xl[1005];
vector<int> num;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>zl[i];
	}
	for (i=1;i<=m;i++)
	{
		cin>>xl[i];
		cnt[xl[i]]++;
	}
	for (i=m;i;i--)
	{
		cnt[xl[i]]--;
		if (!cnt[xl[i]])
		{
			num.push_back(xl[i]);
		}
	}
	reverse(num.begin(),num.end());
	for (i=1;i<=m;i++)
	{
		for (j=0;j<num.size();j++)
		{
			if (num[j]==xl[i])
			{
				num.erase(num.begin()+j);
				break;
			}
			ans+=zl[num[j]];
		}
		num.insert(num.begin(),xl[i]);
	}
	cout<<ans;
	return 0;
}