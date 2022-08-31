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
int n1,n2,n3,n,x,ans,i;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>n1>>n2;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		if (x==1)
		{
			if (n1)
			{
				n1--;
				continue;
			}
			if (n2)
			{
				n2--;
				n3++;
				continue;
			}
			if (n3)
			{
				n3--;
				continue;
			}
			ans++;
		}
		if (x==2)
		{
			if (n2)
			{
				n2--;
				continue;
			}
			ans+=2;
		}
	}
	cout<<ans;
	return 0;
}