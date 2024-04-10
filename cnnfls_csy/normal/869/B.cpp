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
long long x,y,i;
int main()
{
	long long ans=1;
	cin>>x>>y;
	if (y-x>20)
	{
		cout<<0;
		return 0;
	}
	for (i=x+1;i<=y;i++)
	{
		ans=ans*(i%10)%10;
	}
	cout<<ans<<endl;
	return 0;
}